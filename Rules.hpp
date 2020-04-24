#pragma once
#ifndef RULES_HPP
#define RULES_HPP
#include <functional>
#include <vector>
// This struct acts as an organizer for the rules defined for the game. C++14 required for this object.
struct Rules {
    struct Rule;
    static std::vector<Rule> rules;
};
#endif