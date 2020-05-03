#include "human.hpp"

HumanPlayer::HumanPlayer(){
    setName();
}

void HumanPlayer::setName(){
    std::cout << "Enter name: ";
    std::string t;
    std::cin >> t;
    std::cout << "Thanks, " << t << "!" << std::endl;
sName(t);
}

void HumanPlayer::chooseCard(){
    int card;
    printCards();
    std::cout << "Enter the number of the card you wish to play: ";
    std::cin >> card;
    this->currentCard = card;

}

int HumanPlayer::getCurrentCard(){
    return currentCard;
}

Card HumanPlayer::play(Card discard){
    if(checkMovePossible(discard)){
	    chooseCard();
    }
    else{
        std::cout << "No move! Drawing a card...\n";
	    return Card::turnOver;
    }
    while(getCurrentCard() - 1 < 0 || getCurrentCard() - 1 > hand.size() - 1){
        std::cout << "Invalid choice" << std::endl;
        chooseCard();
    }

    Card c = hand.at(getCurrentCard() - 1);

    if(checkMove(c, discard)){
        hand.erase(hand.begin() + getCurrentCard() - 1);
    }

    else{
        do{
            std::cout << "Invalid move" << std::endl;
            play(discard);
        }while(!checkMove(c,discard));
    }

    if(c.getColor() == "wild"){
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

        c.setColor(select);

    }

    return c;
}

bool HumanPlayer::checkMovePossible(Card discard){
    for(size_t i = 0; i < hand.size(); i++){
        Card c = hand.at(i);
        if(checkMove(c, discard)) { 
            return true;
        }
    }
    return false;
}

void HumanPlayer::printCards(){
    std::cout << "The current cards in your hand are: " << std::endl;
    for(size_t i = 0; i < hand.size(); i++){
        if(hand.at(i).getIsAction() == false){
            std::cout << "Card #" << i + 1 << ": " << hand.at(i).getColor() << " " << hand.at(i).getValue() << std::endl;
        }

        else{
            std::cout << "Card #" << i + 1 << ": " << hand.at(i).getColor() << " " << hand.at(i).getAction() << std::endl;
        }
    }
}
