#ifndef __SPL_SYMBOLS_H__
#define __SPL_SYMBOLS_H__

#include <vector>

enum class Symbol: unsigned {
    input = 0,
    opt_func_list = 1,
    func_list = 2,
    func_decl = 3,
    func_listPrime = 4,
    opt_arg_list = 5,
    block = 6,
    arg_list = 7,
    arg_listPrime = 8,
    stmt_list = 9,
    stmt = 10,
    stmt_listPrime = 11,
    stmt_listtPrime = 12,
    expr_list = 13,
    stmt2 = 14,
    expr = 15,
    expr_listPrime = 16,
    expr_listtPrime = 17,
    term = 18,
    exprPrime = 19,
    factor = 20,
    termPrime = 21,
    factor2 = 22,
    Eof = 23,
    IDENT = 24,
    OPEN_PARENTHESIS = 25,
    CLOSE_PARENTHESIS = 26,
    COMMA = 27,
    OPEN_BRACE = 28,
    CLOSE_BRACE = 29,
    SEMICOLON = 30,
    EQUAL = 31,
    PLUS = 32,
    ASTERISK = 33,
    NUMBER = 34,
    Epsilon = 35
};

struct Rule {
    Rule() = default;
    Rule(const Rule&) = delete;

    Symbol lhs;
    std::vector<Symbol> rhs;
    bool isEmpty() const { return rhs.empty(); }
};

using RuleRef = std::reference_wrapper<Rule>;

static inline unsigned indexOf(Symbol s) {
    unsigned index = static_cast<unsigned>(s);
    if (index < 23) return index;
    else return (index - 23);
}

static inline bool isTerminal(Symbol s) {
    return static_cast<unsigned>(s) >= 23;
}

const Rule& getEntry(Symbol non_term, Symbol term);

#endif
