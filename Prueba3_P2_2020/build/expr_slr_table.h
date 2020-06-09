#ifndef __EXPR_SLR_TABLE_H__
#define __EXPR_SLR_TABLE_H__

#include <vector>

enum class Symbol: unsigned {
    input = 0,
    stmt_list = 1,
    opt_stmt = 2,
    opt_eol = 3,
    stmt = 4,
    assign = 5,
    expr = 6,
    fun_decl = 7,
    arg_list = 8,
    arg = 9,
    term = 10,
    factor = 11,
    opt_arg_list = 12,
    Eof = 13,
    KwPrint = 14,
    Eol = 15,
    Ident = 16,
    OpAssign = 17,
    Comma = 18,
    Number = 19,
    OpAdd = 20,
    OpSub = 21,
    OpMul = 22,
    OpDiv = 23,
    OpenPar = 24,
    ClosePar = 25,
    _epsilon = 26,
    Epsilon = 27
};

struct Rule {
    Rule() = default;
    Rule(const Rule&) = delete;

    Symbol lhs;
    std::vector<Symbol> rhs;
    bool isEmpty() const { return rhs.empty(); }
};

using RuleRef = std::reference_wrapper<Rule>;

class PAction {
public:
    enum { Shift, Reduce, Empty };

    PAction(): action(Empty), value(0) {}
    PAction(unsigned action, int value)
        : action(action), value(value) {}
    bool isShift() const { return action == Shift; }
    bool isReduce() const { return action == Reduce; }
    bool isEmpty() const { return action >= Empty; }
    int getValue() const { return value; }
private:
    unsigned action;
    int value;
};

static inline unsigned indexOf(Symbol s) {
    unsigned index = static_cast<unsigned>(s);
    if (index < 13) return index;
    else return (index - 13);
}

static inline bool isTerminal(Symbol s) {
    return static_cast<unsigned>(s) >= 13;
}

namespace lr
{
    const Rule& rule(int index);
    PAction Action(int state, Symbol term);
    int Goto(int state, Symbol non_term);
    std::string ruleString(int index);
}

#endif
