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
    do{
        cout << "Welcome to UNO!" << endl;
        Game g = Game(); //initialize game

        cout << g.p1.getName() << endl;
        cout << "top of discard pile: " << g.getDiscard().getColor() << " " << g.getDiscard().getValue() << endl;
        cout << Card::turnOver.getValue() << endl;
        cout << "Enter play sequence" << endl;
        cout << g.p1.getNumCards() << endl;
        g.p1.play();
        cout << "Exiting play sequence" << endl;
        //auto mrule = Rules::rules.at(0);
        //cout << mrule.test() << endl;

        choice = 'n';
        cout << choice << endl;
    }while(choice != 'n' && choice != 'N');

    return 0;
}
