#include "player.hpp"
  
Player::Player(){
    name = "N/A";
    setNumCards();
}

void Player::addToHand(Card c){
    hand.push_back(c);
    setNumCards();
}

void Player::setNumCards(){
    this->numCards = hand.size();
}

void Player::sName(std::string name){
    this->name = name;
}

int Player::getNumCards(){
    return hand.size();
}

std::string Player::getName(){
    return name;
}

Card Player::play(Card discard){
        return Card("none", -3);
}

//checks to see if colors on attempted move and discard pile match
bool Player::checkColor(Card move, Card discard){
    if(move.getColor() == discard.getColor()){
        return true;
    }

    return false;
}

//checks to see if values on non-action attempted move and discard pile match
bool Player::checkValue(Card move, Card discard){
    if((move.getValue() == discard.getValue()) && move.getValue() <= 9){
        return true;
    }

    return false;
}

//checks to see if actions on attempted action move and discard pile match
bool Player::checkAction(Card move, Card discard){
    if((discard.getIsAction()) && (move.getAction() == discard.getAction())){
        return true;
    }

    return false;
}

//checks to see if attempted draw four move is valid
bool Player::checkDrawFour(Card discard){
    for(size_t i = 0; i < hand.size(); i++){
        if(hand.at(i).getColor() == discard.getColor()){
            return false;
        }

        else if((hand.at(i).getValue() == discard.getValue()) && hand.at(i).getValue() <= 9){
            return false;
        }

        else if((discard.getIsAction()) && (hand.at(i).getAction() == discard.getAction())){
            return false;
        }

        else if(hand.at(i).getAction() == "wild"){
            return false;
        }
    }

    return true;
}

bool Player::checkMove(Card move, Card discard){
    if(move.getAction() != "draw4"){
        if(checkColor(move, discard) || checkValue(move, discard) || checkAction(move, discard)){
            return true;
        }
    }
             
    else if(move.getAction() == "draw4"){
        if(checkDrawFour(discard)){
                return true;
        }
    }
    
    return false;
    
} 
