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

Card Player::play(){
        return Card("none", -3);
}
