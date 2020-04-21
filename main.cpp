#include "card.hpp"
#include "deck.hpp"
#include "game.hpp"
#include "player.hpp"
#include <iostream>

using namespace std;

int main(){
    Game g = new Game();

    for(int i = 0; i < p1.hand.size(); i++){
        cout << hand.at(i).getColor() << " " << hand.at(i).getValue();
        if(hand.at(i).isAction() == true){
            cout << " " << hand.at(i).getAction() << endl;
        }
        else{
            cout << endl;
        }
    }
    return 0;
}  
