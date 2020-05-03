#pragma once
#ifndef RULES_HPP
#define RULES_HPP
#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include "card.hpp"
// This struct acts as an organizer for the rules defined for the game. C++14 required for this object.
struct Rules {
    /* 

    This struct is the core of the way we handle rules; it takes in a bool test() and Card action()
    as parameters to the structures. Using new C++ features, we can save these into variables without
    needing to do complex and/or unsafe things such as storing function pointers or any nonsense like that.
    This way we can define the rules we need easily.

    No, this is not the ideal method, but alas, writing code is hard, and this is the easiest way to achieve
    the effects we desire.

    */
    struct Rule {
        std::function<bool(const Card& discard, const std::vector<Card>& deck)> test;
        std::function<Card(const Card& discard, const std::vector<Card>& deck)> action;
        Rule(auto _tst, auto _act) : test(_tst), action(_act) { };
    };
    static std::vector<Rule> rules;
};
#endif
