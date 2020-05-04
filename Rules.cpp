#include "Rules.hpp"

// Lambda defines; makes the rules cleaner and easier to read. 
#define tst [](const Card& discard, const std::vector<Card>& deck) -> bool
#define act [](const Card& discard, const std::vector<Card>& deck) -> Card

// ADD RULES BELOW

std::vector<Rules::Rule> Rules::rules = {
    Rules::Rule( // turns out this one rule is pretty good, and we don't really need more. How about that?
        tst { // do we have a card that we can play? 
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
                    if(c.getColor() == "red"){
                        colorCount.at(0)++;
                    }
                    else if(c.getColor() == "green"){
                        colorCount.at(1)++;
                    }
                    else if(c.getColor() == "blue"){
                        colorCount.at(2)++;
                    }
                    else if(c.getColor() == "yellow"){
                        colorCount.at(3)++;
                    }
                }
		        int tmp = *(std::max_element(colorCount.begin(), colorCount.end()));
                int index = std::distance(colorCount.begin(), std::find(colorCount.begin(), colorCount.end(), tmp));
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
