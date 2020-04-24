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

int HumanPlayer::play(){
    int card;
    std::cout << "The current cards in your hand are: " << std::endl;

    for(int i = 0; i < hand.size(); i++){
	if(hand.at(i).getIsAction() == false){
	    std::cout << "Card #" << i + 1 << ": " << hand.at(i).getColor() << " " << hand.at(i).getValue() << std::endl;
	}

	else{
	    std::cout << "Card #" << i + 1 << ": " << hand.at(i).getColor() << " " << hand.at(i).getAction() << std::endl;
	}
    }

    std::cout << "Enter the number of the card you wish to play: ";
    std::cin >> card;

    //check here for valid move using hand.at(card - 1)
    
    return card; //not sure about this yet
}
