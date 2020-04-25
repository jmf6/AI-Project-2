#include "AIplayer.hpp"
  
AIplayer::AIplayer(){
    sName("CPU 1");
}

Card AIplayer::play(Card discard){
    //do AI shit here
    Card c = Card::turnOver;
    for(auto rule : Rules::rules) {
        if(rule.test(discard, hand)) {
            c = rule.action(discard, hand);
        }
    }
    if (!checkMove(c, discard))  {
        c = Card::turnOver;
    }
    return c; //just until AI shit is done
}
