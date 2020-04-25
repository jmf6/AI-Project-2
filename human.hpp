#pragma once
#include "player.hpp"
#include "game.hpp"
#include <string>
#include <iostream>
#ifndef HUMAN_HPP
#define HUMAN_HPP

class HumanPlayer : public Player{
    public:
        HumanPlayer();
        Card play(Card discard) override;
	void chooseCard();
	int getCurrentCard();

    private:
        void setName();
        void printCards();
	int currentCard;
};

#endif
