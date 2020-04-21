#include "player.hpp"

Player::Player(){
    h = new Hand();
}

void Player::addToHand(Card c){
    hand.push_back(c);
}
