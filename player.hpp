#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "card.hpp"

#include <vector>
#include <string>
#include <iostream>

class Player{                              // Base Player class
    private:                                // No one may access this other than the player
        int numCards;
        std::string name;
	bool checkColor(Card move, Card discard);
	bool checkValue(Card move, Card discard);
	bool checkAction(Card move, Card discard);
	bool checkDrawFour(Card discard);
   
    protected:                              // protected means inherited classes can access this data, as opposed to private
        void sName(std::string name);
	    bool checkMove(Card move, Card discard);
    public:
        Player();
        virtual Card play(Card discard);                 // override-able behavior
        void addToHand(Card c);
        void setNumCards();
        std::vector<Card> hand;
        int getNumCards();
        std::string getName();
};
#endif
