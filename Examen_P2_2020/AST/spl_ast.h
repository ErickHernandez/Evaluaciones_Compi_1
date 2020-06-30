#ifndef __SPL_AST_H__
#define __SPL_AST_H__


//Abstract Syntax Tree Class

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

namespace Ast
{
    enum class Kind{
        Sequence,
        Assign,
        Print,
        Add,
        Sub,
        Mul,
        Number,
        Ident,
        FuncCall,
        Return,
        FuncDecl
    };
    
    class Node;

    //Creating Typedef
    using VarTable = std::unordered_map<std::string, int>;
    using NodePtr = std::shared_ptr<Node>;


    class Node
    {
        public:
            virtual Kind getKind() const = 0;
            virtual std::string toString() const = 0;
            virtual ~Node() {}
    };

    class Sequence : public Node
    {
        public:
            Sequence(std::vector<NodePtr>&& stmts) : statements(std::move(stmts)){}

            Kind getKind() const override { return Kind::Sequence; }

            std::vector<NodePtr> getStatements() { return statements; }

            std::string toString() const override{
                std::string str = "";
                
                for (const auto& s : statements)
                    str += s->toString() + "\n";
                return str;
            }
        private:
            std::vector<NodePtr> statements;
            
    };

    class FuncDecl : public Node
    {
        public:
            FuncDecl(const std::string& name, std::vector<NodePtr>&& params, NodePtr stmts)
            : name(name), params(std::move(params)), statements(stmts){}

            Kind getKind() const override { return Kind::FuncDecl; }

            std::string getName() { return name; }
            std::vector<NodePtr> getParams() { return params; }
            NodePtr getStatements() { return statements; }

            std::string toString() const override{
                std::string str = "";
                
                for (const auto& s : params)
                    str += s->toString() + ",";

                if(str.size() > 0)
                    str.pop_back();

                return name +"("+ str + ")" "{\n"+ statements->toString() + "}\n";
            }

        private:
            std::string name;
            std::vector<NodePtr> params;
            NodePtr statements;
            
    };

    class FuncCall : public Node
    {
        public:
            FuncCall(const std::string& name, std::vector<NodePtr>&& params)
            : name(name), params(std::move(params)){}

            Kind getKind() const override { return Kind::FuncCall; }

            std::string getName() { return name; }
            std::vector<NodePtr> getParams() { return params; }

            std::string toString() const override{

                 std::string str = "";

                for (const auto& s : params)
                    str += s->toString() + ",";

                if(str.size() > 0)
                    str.pop_back();

                return name +"("+ str + ")";
            }

        private:
            std::string name;
            std::vector<NodePtr> params;
            
    };

    class Return : public Node
    {
        public:
            Return(NodePtr expr) : expr(expr){}

            Kind getKind() const override { return Kind::Return; }

            NodePtr getExpr() { return expr; }

            std::string toString() const override{
                return "return " + expr->toString();
            }
        private:
            NodePtr expr;
            
    };
    
    
    class Print : public Node
    {
        public:
            Print(NodePtr expr):expr(expr){}

            Kind getKind() const override { return Kind::Print; }

            NodePtr getExpr(){return expr;}

            std::string toString() const override{
                return "print " + expr->toString();
            }
        private:
            NodePtr expr;

    };

    class Assign : public Node
    {
        public:
            Assign(NodePtr var, NodePtr expr) : var(var), expr(expr){}

            Kind getKind() const override { return Kind::Assign; }

            NodePtr getVarName() { return var; }
            NodePtr getExpr() { return expr; }

            std::string toString() const override{
                return var->toString() + "=" + expr->toString();
            }
        private:
            NodePtr var;
            NodePtr expr;
    };

    class Add : public Node
    {
        public:
            Add(NodePtr expr1, NodePtr expr2) : expr1(expr1), expr2(expr2){}

            Kind getKind() const override { return Kind::Add; }

            NodePtr getExpr1() { return expr1; }
            NodePtr getExpr2() { return expr2; }

            std::string toString() const override{
                return "(" + expr1->toString() + ")+" +
                    "(" + expr2->toString() + ")";
            }
        private:
            NodePtr expr1;
            NodePtr expr2;
    };

    class Sub : public Node
    {
        public:
            Sub(NodePtr expr1, NodePtr expr2):expr1(expr1), expr2(expr2){}

            Kind getKind() const override { return Kind::Sub; }

            NodePtr getExpr1() { return expr1; }
            NodePtr getExpr2() { return expr2; }

            std::string toString() const override{
                return "(" + expr1->toString() + ")-" +
                    "(" + expr2->toString() + ")";
            }
        private:
            NodePtr expr1;
            NodePtr expr2;
    };

    class Mul : public Node
    {
        public:
            Mul(NodePtr expr1, NodePtr expr2):expr1(expr1), expr2(expr2){}

            Kind getKind() const override { return Kind::Mul; }

            NodePtr getExpr1() { return expr1; }
            NodePtr getExpr2() { return expr2; }

            std::string toString() const override{
                return "(" + expr1->toString() + ")*" +
                    "(" + expr2->toString() + ")";
            }
        private:
            NodePtr expr1;
            NodePtr expr2;
    };

    class Number : public Node
    {
        public:
            Number(int value):value(value){}

            Kind getKind() const override { return Kind::Number; }

            int getValue() { return value; }

            std::string toString() const override{
                return std::to_string(value);
            }
        private:
            int value;
    };

    class Ident : public Node
    {
        public:
            Ident(const std::string& text):text(text){}

            Kind getKind() const override { return Kind::Ident; }

            std::string getText() { return text; }

            std::string toString() const override{
                return text;
            }
        private:
            std::string text;
    };


    //std::string toString(const NodePtr& root);
    int eval(const NodePtr& root, std::ostream& out);
}

#endif
