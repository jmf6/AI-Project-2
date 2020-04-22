#include "card.hpp"
#include "deck.hpp"
#include "game.hpp"
#include "player.hpp"
#include <iostream>

using namespace std;

int main(){
    Game g = Game();

    for(int i = 0; i < g.p1.hand.size(); i++){
        cout << g.p1.hand.at(i).getColor() << " " << g.p1.hand.at(i).getValue();
        if(g.p1.hand.at(i).getIsAction() == true){
            cout << " " << g.p1.hand.at(i).getAction() << endl;
        }
        else{
            cout << endl;
        }
    }
    return 0;
}  
