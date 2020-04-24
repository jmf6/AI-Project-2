#pragma once
#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include "human.hpp"
#include "AIplayer.hpp"

class Game{
    public:
        Game();
        void dealCards();
        Card drawCard();
        Card getDiscard();
        Player p1; //human player
        Player p2; //AI
        Deck drawPile;

    private:
        //Deck drawPile; I don't know why I did this and which draw pile needs to stay but I'll figure it out
        Deck discardPile;

};

#endif
