#include "card.hpp"
#include "deck.hpp"
#include "game.hpp"
#include "player.hpp"
#include "Rules.hpp"
#include "human.hpp"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void sleepForMillis(size_t x) {
    this_thread::sleep_for(chrono::milliseconds(x));
}

int main(){
    char choice = 'y';
    Player* currentPlayer;
    bool counter = false;
    bool win = false;
    do{

        cout << "Welcome to UNO!" << endl;
        Game g = Game(); //initialize game

        while(!win){
            if(!counter){
                currentPlayer = g.p1;
            }
            else {
                currentPlayer = g.p2;
            }
            cout << "Top of discard pile: " << g.getDiscard().getColor() << " " << g.getDiscard().getValue() << endl;
            Card c = currentPlayer->play(g.getDiscard());
            sleepForMillis(250);
            if(c.getValue() == -100 && c.getColor() == "red") { // this is our "it's the next player's move" card
                c = g.drawCard();
                currentPlayer->addToHand(c);
                goto flip; // skip to the next player turn
            } else if(c.getColor() == "wild") {
                // it is a wild colored card, and we need to set the color
                char selection = 0;
                do {
                    std::cout << "Wild card! Please pick a color (r,y,b,g): ";
                    std::cin >> selection;
                } while (selection != 'r' || selection != 'y' || selection != 'b' || selection != 'g');
                switch(selection) {
                    case 'r': {
                        c.setColor("red");
                        break;
                    }
                    case 'y': {
                        c.setColor("yellow");
                        break;
                    }
                    case 'g': {
                        c.setColor("green");
                        break;
                    }
                    case 'b': {
                        c.setColor("blue");
                        break;
                    }
                }
            } else {
                g.discardPile.theDeck.push_back(c);
                if(g.getDiscard().getIsAction() && g.getDiscard().getAction() != "wild"){
                    do{
                        Card c = currentPlayer->play(g.getDiscard());
                        g.discardPile.theDeck.push_back(c);
                        if(currentPlayer->hand.size() == 1){
                            cout << "Uno!!!" << endl;
                            break;
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
            flip: // here we skip to the next player (gross)
            counter = !counter;
        }
        std::cout << currentPlayer->getName() << " won!\nDo you want to play again? (Y/N): ";
        std::cin >> choice;
        choice = (choice != 'n' || choice != 'y' || choice != 'N' || choice != 'Y') ? 'n' : choice;
    } while(choice != 'n' && choice != 'N');

    return 0;
}
