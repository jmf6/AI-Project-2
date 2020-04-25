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
    chooseCard();
       
    Card c = hand.at(getCurrentCard());

    if(checkMove(c, discard)){
	hand.erase(hand.begin() + getCurrentCard());
    }

    else{
	do{
	    std::cout << "Invalid move" << std::endl;
	    play(discard);
	}while(!checkMove(c,discard));
    }


    return c;
}

void HumanPlayer::printCards(){
    std::cout << "The current cards in your hand are: " << std::endl;
    for(int i = 0; i < hand.size(); i++){
        if(hand.at(i).getIsAction() == false){
            std::cout << "Card #" << i + 1 << ": " << hand.at(i).getColor() << " " << hand.at(i).getValue() << std::endl;
        }

        else{
            std::cout << "Card #" << i + 1 << ": " << hand.at(i).getColor() << " " << hand.at(i).getAction() << std::endl;
        }
    }
}
