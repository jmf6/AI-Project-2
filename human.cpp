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

Card HumanPlayer::play(){
    std::cout << "entering play function" << std::endl;

    int card;
    std::cout << "The current cards in your hand are: " << std::endl;

    printCards();

    std::cout << "Enter the number of the card you wish to play: ";
    std::cin >> card;
    Card c = hand.at(card - 1);
    //check here for valid move using hand.at(card - 1)

    return c;
}

void HumanPlayer::printCards(){
    for(int i = 0; i < hand.size(); i++){
        if(hand.at(i).getIsAction() == false){
            std::cout << "Card #" << i + 1 << ": " << hand.at(i).getColor() << " " << hand.at(i).getValue() << std::endl;
        }

        else{
            std::cout << "Card #" << i + 1 << ": " << hand.at(i).getColor() << " " << hand.at(i).getAction() << std::endl;
        }
    }
}
