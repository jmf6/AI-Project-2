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
    Player* currentPlayer;
    Player* otherPlayer;
    int counter = 1;
    bool win = false;
    do{

        cout << "Welcome to UNO!" << endl;
        Game g = Game(); //initialize game
        if(g.getDiscard().getColor() == "wild"){
            char color;
            std::string select;
            std::cout << "Which color would you like to change to? (r = red, b = blue, g = green, y = yellow) ";
            while(color != 'r' && color != 'b' && color != 'g' && color != 'y'){
               std::cout << "Invalid choice, r = red, b = blue, g = green, y = yellow";
            }

            switch(color){
                case 'r':
                    select = "red";
                    break;
                case 'b':
                    select = "blue";
                    break;
                case 'g':
                    select = "green";
                    break;
                case 'y':
                        select = "yellow";
                        break;
            }

            g.getDiscard().setColor(select);
        }

        while(!win){
                if(counter == 1){
                    currentPlayer = g.p1;
                    otherPlayer = g.p2;
                }
                else if(counter == 2){
                    currentPlayer = g.p2;
                    otherPlayer = g.p1;
                }

                cout << "Top of discard pile: " << g.getDiscard().getColor() << " " << g.getDiscard().getValue() << endl;

                Card c = currentPlayer->play(g.getDiscard());
		if(c.getValue() == -100){
		    c = g.drawCard();
		    currentPlayer->addToHand(c);
		}
		else{
                    g.discardPile.theDeck.push_back(c);
                    if(g.getDiscard().getIsAction() && g.getDiscard().getAction() != "wild"){
                        do{
                            Card c = currentPlayer->play(g.getDiscard());
                            g.discardPile.theDeck.push_back(c);
                            if(currentPlayer->hand.size() == 1){
                                cout << "Uno!!!" << endl;
                            }
                        }while(g.getDiscard().getIsAction() && g.getDiscard().getAction() != "wild");
                    }

                    if(currentPlayer->hand.size() == 1){
                        cout << "Uno!!!" << endl;
                    }

                    if(currentPlayer->hand.size() == 0){
                            win = true;
                    }
		}
                if(counter == 1){
                        counter = 2;
                }
                else if(counter == 2){
                        counter = 1;
                }
        }


                //auto mrule = Rules::rules.at(0);
                //cout << mrule.test() << endl;

        choice = 'n';
    }while(choice != 'n' && choice != 'N');

    return 0;
}
