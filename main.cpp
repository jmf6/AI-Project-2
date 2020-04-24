#include "card.hpp"
#include "deck.hpp"
#include "game.hpp"
#include "player.hpp"
#include "Rules.hpp"
#include <iostream>

using namespace std;

int main(){
    Game g = Game();

    for(size_t i = 0; i < g.p1.hand.size(); i++){
        cout << g.p1.hand.at(i).getColor() << " " << g.p1.hand.at(i).getValue();
        if(g.p1.hand.at(i).getIsAction() == true){
            cout << " " << g.p1.hand.at(i).getAction() << endl;
        }
        else{
            cout << endl;
        }
    }

    cout << "top of discard pile: " << g.getDiscard().getColor() << " " << g.getDiscard().getValue() << endl;
    cout << Card::turnOver.getValue() << endl;
    auto mrule = Rules::rules.at(0);
    cout << mrule.test() << endl;
    return 0;
}  
