#pragma once
#include "player.hpp"
#include <string>
#include <iostream>
#ifndef HUMAN_HPP
#define HUMAN_HPP

class HumanPlayer : public Player{
    public:
        HumanPlayer();
        Card play() override;
    private:
        void setName();
        void printCards();
};

#endif
