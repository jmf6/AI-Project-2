#include "Rules.hpp"

// Lambda defines; makes the rules cleaner and easier to read. 
#define tst []() -> bool
#define act []()

// ADD RULES BELOW

std::vector<Rules::Rule> Rules::rules = {
    Rule( // example rule definition
        tst {
            return 1 == 1;
        },
        act {
            1 + 2;
        }
    )
};

// we don't need development definitions anymore
#undef tst
#undef act