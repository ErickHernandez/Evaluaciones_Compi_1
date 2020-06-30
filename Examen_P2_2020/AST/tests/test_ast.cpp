#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "spl_ast.h"

#define SEQ std::make_shared<Ast::Sequence>
#define FUNC std::make_shared<Ast::FuncDecl>
#define PRINT(a) std::make_shared<Ast::Print>(a)
#define ASSIGN std::make_shared<Ast::Assign>
#define RETURN(a) std::make_shared<Ast::Return>(a)
#define CALL std::make_shared<Ast::FuncCall>
#define ADD(a, b) std::make_shared<Ast::Add>(a, b)
#define SUB(a, b) std::make_shared<Ast::Sub>(a, b)
#define MUL(a, b) std::make_shared<Ast::Mul>(a, b)
#define NUM(n) std::make_shared<Ast::Number>(n)
#define VAR(x) std::make_shared<Ast::Ident>(x)

TEST_CASE("One function")
{
    std::vector<Ast::NodePtr> stmts = {
        PRINT(MUL(ADD(NUM(10), NUM(7)), NUM(5)))
    };
    std::vector<Ast::NodePtr> empty_args;

    Ast::NodePtr root = FUNC("main", empty_args, SEQ(stmts));

    CHECK(root->toString() == "main(){\n"
                              "print ((10)+(7))*(5)\n"
                              "}");
}

TEST_CASE("Two functions")
{
    std::vector<Ast::NodePtr> add_stmts = {
        RETURN(ADD(VAR("a"), VAR("b")))
    };
    std::vector<Ast::NodePtr> add_params = {
        VAR("a"), VAR("b")
    };
    Ast::NodePtr add_fn = FUNC("add", add_params, SEQ(add_stmts));


    std::vector<Ast::NodePtr> add_args = { ADD(VAR("a"), NUM(10)), ADD(VAR("b"), NUM(20)) };
    std::vector<Ast::NodePtr> main_stmts = {
        ASSIGN( VAR("x"), CALL("add", add_args) )
    };
    std::vector<Ast::NodePtr> main_params = {
        VAR("a"), VAR("b")
    };
    Ast::NodePtr main_fn = FUNC("main", main_params, SEQ(main_stmts));

    std::vector<Ast::NodePtr> seq_stmts = { add_fn, main_fn };
    Ast::NodePtr root = SEQ(seq_stmts);

    CHECK(root->toString() == "add(a,b){\n"
                              "return (a)+(b)\n"
                              "}\n"
                              "main(a,b){\n"
                              "x=add((a)+(10),(b)+(20))\n"
                              "}\n");
}

Ast::NodePtr makeFunc(const std::string& name,
                      const std::initializer_list<Ast::NodePtr>& iparams,
                      const std::initializer_list<Ast::NodePtr>& istmts)
{
    std::vector<Ast::NodePtr> stmtsv(istmts);
    std::vector<Ast::NodePtr> paramsv(iparams);

    return std::make_shared<Ast::FuncDecl>(name, paramsv, SEQ(stmtsv));
}

Ast::NodePtr makeSeq(const std::initializer_list<Ast::NodePtr>& istmts)
{
    std::vector<Ast::NodePtr> stmtv(istmts);
    
    return std::make_shared<Ast::Sequence>(std::move(stmtv));
}

Ast::NodePtr makeCall(const std::string& name,
                      const std::initializer_list<Ast::NodePtr>& iargs)
{
    std::vector<Ast::NodePtr> argv(iargs);

    return std::make_shared<Ast::FuncCall>(name, argv);
}

TEST_CASE("Three functions")
{
    Ast::NodePtr add_fn = makeFunc("add",  { VAR("a"), VAR("b"), VAR("c") },
                                   {
                                       PRINT(MUL(ADD(VAR("c"), VAR("d")), SUB(VAR("c"), VAR("b")))),
                                       RETURN(ADD(VAR("a"), VAR("b")))
                                   });

    Ast::NodePtr printer_fn = makeFunc("printer",  { VAR("a"), VAR("b"), VAR("c") },
                                        {
                                            PRINT(ADD(VAR("a"), NUM(10))),
                                            PRINT(ADD(VAR("b"), NUM(20))),
                                            PRINT(ADD(VAR("c"), NUM(30))),
                                        });

    Ast::NodePtr main_fn = makeFunc("main",  { VAR("a"), VAR("b") },
                                    {
                                        ASSIGN(VAR("x"), makeCall("add", {ADD(VAR("a"), NUM(10)), ADD(VAR("b"), NUM(20))})),
                                        makeCall("printer", {VAR("a"), VAR("b"), VAR("x")})
                                    });

    Ast::NodePtr root = makeSeq({add_fn, printer_fn, main_fn });

    CHECK(root->toString() ==   "add(a,b,c){\n"
                                "print ((c)+(d))*((c)-(b))\n"
                                "return (a)+(b)\n"
                                "}\n"
                                "printer(a,b,c){\n"
                                "print (a)+(10)\n"
                                "print (b)+(20)\n"
                                "print (c)+(30)\n"
                                "}\n"
                                "main(a,b){\n"
                                "x=add((a)+(10),(b)+(20))\n"
                                "printer(a,b,x)\n"
                                "}\n");
}

TEST_CASE("Main not defined")
{
    Ast::NodePtr root = PRINT(VAR("10"));

    REQUIRE_THROWS_MESSAGE(eval(root, std::cout), "Function main not defined");
}

TEST_CASE("Duplicated definition of function")
{
    Ast::NodePtr fn1 = makeFunc("add", {}, {});
    Ast::NodePtr fn2 = makeFunc("add", {}, {});

    REQUIRE_THROWS_MESSAGE(eval(makeSeq({fn1, fn2}), std::cout), "Function add redeclared");
}

TEST_CASE("Function not defined")
{
    Ast::NodePtr fn1 = makeFunc("main", {}, {
        ASSIGN(VAR("x"), makeCall("add", {}))
    });
    
    REQUIRE_THROWS_MESSAGE(eval(makeSeq({fn1}), std::cout), "Function add is not defined");
}

TEST_CASE("Mismatch argument count")
{
    Ast::NodePtr add_fn = makeFunc("add",  { VAR("a"), VAR("b"), VAR("c") },
                                   {
                                       RETURN(ADD(VAR("a"), VAR("b")))
                                   });

    Ast::NodePtr main_fn = makeFunc("main", {},
                                    {
                                        ASSIGN(VAR("x"), makeCall("add", {}))
                                    });
    
    REQUIRE_THROWS_MESSAGE(eval(makeSeq({add_fn, main_fn}), std::cout), "Invalid argument count: add");
}

TEST_CASE("Variable not defined")
{
    Ast::NodePtr main_fn = makeFunc("main", {},
                                    {
                                        ASSIGN(VAR("x"), VAR("y"))
                                    });
    
    REQUIRE_THROWS_MESSAGE(eval(makeSeq({main_fn}), std::cout), "Variable y not defined");
}

TEST_CASE("One function")
{
    Ast::NodePtr main_fn = makeFunc("main", {},
                                    {
                                        PRINT(NUM(10))
                                    });

    std::ostringstream out;
    REQUIRE_NOTHROW( eval(main_fn, out) );

    CHECK(out.str() == "10\n");
}

TEST_CASE("Function call 1")
{
    Ast::NodePtr add_fn = makeFunc("add",  { VAR("a"), VAR("b") },
                                   {
                                       RETURN(ADD(VAR("a"), VAR("b")))
                                   });

    Ast::NodePtr main_fn = makeFunc("main", {},
                                    {
                                        ASSIGN(VAR("x"), makeCall("add", {NUM(100), NUM(200)})),
                                        PRINT(VAR("x"))
                                    });

    std::ostringstream out;
    REQUIRE_NOTHROW( eval(makeSeq( {add_fn, main_fn} ), out) );

    CHECK(out.str() == "300\n");
}

TEST_CASE("Function call 2")
{
    Ast::NodePtr add_fn = makeFunc("add",  { VAR("a"), VAR("b"), VAR("c") },
                                   {
                                       PRINT(MUL(ADD(VAR("c"), VAR("b")), SUB(VAR("c"), VAR("b")))),
                                       RETURN(ADD(VAR("a"), VAR("c")))
                                   });

    Ast::NodePtr printer_fn = makeFunc("printer",  { VAR("a"), VAR("b"), VAR("c") },
                                        {
                                            PRINT(ADD(VAR("a"), NUM(10))),
                                            PRINT(ADD(VAR("b"), NUM(20))),
                                            PRINT(ADD(VAR("c"), NUM(30))),
                                        });

    Ast::NodePtr main_fn = makeFunc("main",  {},
                                    {
                                        ASSIGN(VAR("x"), makeCall("add", {NUM(10), NUM(20), NUM(30)})),
                                        makeCall("printer", {NUM(10), NUM(20), VAR("x")})
                                    });

    std::ostringstream out;
    REQUIRE_NOTHROW( eval(makeSeq( {add_fn, printer_fn, main_fn} ), out) );

    CHECK( out.str() == "500\n20\n40\n70\n" );
}