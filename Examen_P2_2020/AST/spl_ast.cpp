#include "spl_ast.h"

namespace Ast{

    VarTable varTable;
    VarTable funTable;

    // std::string toString(const NodePtr& root)
    // {
    //     switch (root->getKind())
    //     {
            
    //         case Ast::Kind::Sequence:
    //         {
    //             std::string str = "";
    //             Sequence* n = reinterpret_cast<Sequence*>(root.get());
    //             for (const auto& s : n->getStatements())
    //                 str += toString(s) + "\n";
    //             return str;
    //         }
    //         case Ast::Kind::Assign:
    //         {
    //             Assign* n = reinterpret_cast<Assign*>(root.get());
    //             return n->getVarName() + "=" + toString(n->getExpr());
    //         }
    //         case Ast::Kind::Print:
    //         {
    //             Print* n = reinterpret_cast<Print*>(root.get());
    //             return "print " + toString(n->getExpr());
    //         }
    //         case Ast::Kind::Add:
    //         {
    //             Add* n = reinterpret_cast<Add*>(root.get());
    //             return "(" + toString(n->getExpr1()) + ")+" +
    //                 "(" + toString(n->getExpr2()) + ")";
    //         }
    //         case Ast::Kind::Sub:
    //         {
    //             Sub* n = reinterpret_cast<Sub*>(root.get());
    //             return "(" + toString(n->getExpr1()) + ")-" +
    //                 "(" + toString(n->getExpr2()) + ")";
    //         }
    //         case Ast::Kind::Mul:
    //         {
    //             Mul* n = reinterpret_cast<Mul*>(root.get());
    //             return "(" + toString(n->getExpr1()) + ")*" +
    //                 "(" + toString(n->getExpr2()) + ")";
    //         }
    //         case Ast::Kind::Number:
    //         { 
    //             Number* n = reinterpret_cast<Number*>(root.get());
    //             return std::to_string(n->getValue());
    //         }
    //         case Ast::Kind::Ident:
    //         { 
    //             Ident* n = reinterpret_cast<Ident*>(root.get());
    //             return n->getText();
    //         }
    //         default:
    //         { 
    //             throw "Invalide Node Type. Can't convert to String.";
    //         }
    //     }

    //     return "";
    // }

    int eval(const NodePtr& root, std::ostream& out){
        switch (root->getKind()){
            
            case Ast::Kind::Sequence:
            {
                Sequence* n = reinterpret_cast<Sequence*>(root.get());
                for (const auto& s : n->getStatements())
                    eval(s, out);
                return -1;
            }
            case Ast::Kind::Assign:
            { 
                Assign* n = reinterpret_cast<Assign*>(root.get());
                int value = eval(n->getExpr(), out);
                varTable.emplace(n->getVarName(), value);

                return -1;
            }
            case Ast::Kind::Print:
            { 
                Print* n = reinterpret_cast<Print*>(root.get());
                int val = eval(n->getExpr(), out);
                
                out<<val;

                return -1;
            }
            case Ast::Kind::Add:
            { 
                Add* n = reinterpret_cast<Add*>(root.get());
                int a = eval(n->getExpr1(), out);
                int b = eval(n->getExpr2(), out);

                return a + b;
            }
            case Ast::Kind::Sub:
            { 
                Sub* n = reinterpret_cast<Sub*>(root.get());
                int a = eval(n->getExpr1(), out);
                int b = eval(n->getExpr2(), out);

                return a - b;
            }
            case Ast::Kind::Mul:
            { 
                Mul* n = reinterpret_cast<Mul*>(root.get());
                int a = eval(n->getExpr1(), out);
                int b = eval(n->getExpr2(), out);

                return a * b;
            }
            case Ast::Kind::Number:
            { 
                Number* n = reinterpret_cast<Number*>(root.get());
                return n->getValue();
            }
            case Ast::Kind::Ident:
            { 
                Ident* n = reinterpret_cast<Ident*>(root.get());
                auto it = varTable.find(n->getText());
                if(it != varTable.end())
                    return it->second;  

                throw "Variable has not been declared yet.";
            }
            default:
            { 
                throw "Impossible to eval. Unknown type node.";
            }        
        }

        return 0;
    }
}