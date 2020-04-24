#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "card.hpp"
#include <vector>

class Player{                              // Base Player class
    
    public:
        Player();
        //virtual int play();                 // override-able behavior
        void addToHand(Card c);
	std::vector<Card> hand;

};
#endif
