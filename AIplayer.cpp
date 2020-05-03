#include "AIplayer.hpp"
#include <iostream>
  
AIplayer::AIplayer(){
    sName("CPU 1");
}

Card AIplayer::play(Card discard) {
	std::cout << "AI is making move!\n";
    Card c = Card::turnOver;
    for(auto rule : Rules::rules) {
	std::cout << "looping through rules...\n";
        if(rule.test(discard, hand)) {
            c = rule.action(discard, hand);
        }
    }
    if (!checkMove(c, discard))  {
        c = Card::turnOver;
    }
    Card nc = Card(c); // copy constructor, so we can safely delete it from our deck without worries about dangling pointers or whatever
    for(size_t i = 0; i < hand.size(); i++) {
        c = hand.at(i);
        if(c.equals(nc)) { // we want to remove played cards from the AI's hand
            hand.erase(hand.begin()+i);
            break;
        }
    }
    return nc;
}
