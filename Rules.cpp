#include "Rules.hpp"

// Lambda defines; makes the rules cleaner and easier to read. 
#define tst [](const Card& discard, const std::vector<Card>& deck) -> bool
#define act [](const Card& discard, const std::vector<Card>& deck) -> Card

// ADD RULES BELOW

std::vector<Rules::Rule> Rules::rules = {
    Rules::Rule( // example rule definition
        tst { // do we have a normal card that we can play? 
            bool r = false;
            for(auto c : deck) {
                r = (!r) ? (c.getColor() == discard.getColor() || (c.getValue() == discard.getValue())) : r;
            }
            return r;
        },
        act { // if we do, then play the one with the max value
            std::vector<Card> pdeck;
            for(auto c : deck) {
                if((c.getColor() == discard.getColor() || (c.getValue() == discard.getValue()))) {
                    pdeck.push_back(c);
                }
            }
            // std::max hates me, so using this junk instead
            Card max = pdeck.at(0);
            for(auto c : pdeck) {
                if (c.getValue() >= max.getValue()) {
                    max = c;
                }
            }
            if(max.getColor() != "wild") {
                return max;
            } else {
                std::array<int, 4> colorCount;
                for(auto c : deck) {
                    switch(c.getColor()) {
                        case "red": {
                            colorCount.at(0)++;
                            break;
                        }
                        case "green": {
                            colorCount.at(1)++;
                            break;
                        }
                        case "blue": {
                            colorCount.at(2)++;
                            break;
                        }
                        case "yellow": {
                            colorCount.at(3)++;
                            break;
                        }
                    }
                }
                int index = std::distance(colorCount, std::find(colorCount.begin(), colorCount.end(), *(std::max_element(colorCount.begin(), colorCount.end()))));
                std::string colors[] = {"red", "green", "blue", "yellow"};
                max.setColor(colors[index]);
            }
            return max;
        }
    )
};

// we don't need development definitions anymore
#undef tst
#undef act