#include "card.hpp"
#include "deck.hpp"
#include "game.hpp"
#include "player.hpp"
#include "Rules.hpp"
#include "human.hpp"
#include <iostream>

using namespace std;

int main(){
    char choice = 'y';
    int card;
    do{
        cout << "Welcome to UNO!" << endl;
        Game g = Game(); //initialize game

        cout << g.p1->getName() << endl;
        cout << "top of discard pile: " << g.getDiscard().getColor() << " " << g.getDiscard().getValue() << endl;
        //cout << Card::turnOver.getValue() << endl;
        g.p1->play(g.getDiscard());
	
        //auto mrule = Rules::rules.at(0);
        //cout << mrule.test() << endl;

        choice = 'n';
    }while(choice != 'n' && choice != 'N');

    return 0;
}
