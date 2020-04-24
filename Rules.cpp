#include "Rules.hpp"

// Lambda defines; makes the rules cleaner and easier to read. 
#define test []() -> bool
#define action []()

/* 

This struct is the core of the way we handle rules; it takes in a bool test() and void action()
as parameters to the structures. Using new C++ features, we can save these into variables without
needing to do complex and/or unsafe things such as storing function pointers or any nonsense like that.
This way we can define the rules we need easily.

No, this is not the ideal method, but alas, writing code is hard, and this is the easiest way to achieve
the effects we desire.

*/

struct Rules::Rule {
    std::function<bool()> test;
    std::function<void()> action;
    Rule(auto _tst, auto _act) : test(_tst), action(_act) { };
};

// ADD RULES BELOW

std::vector<Rule> Rules::rules = {
    Rule( // example rule definition
        test {
            return 1 == 1;
        },
        action {
            1 + 2;
        }
    )
};

// we don't need development definitions anymore
#undef test
#undef action