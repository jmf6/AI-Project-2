#include "AIplayer.hpp"
#include <iostream>
  
AIplayer::AIplayer(){
    sName("CPU 1");
}

Card AIplayer::play(Card discard){
    //do AI shit here
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
    return c; //just until AI shit is done
}
