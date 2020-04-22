#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

class Game{
    public:
        Game();
        void dealCards();
	Card drawCard();
        Player p1; //human player
        Player p2; //AI

    private:
        Deck drawPile;
        Deck discardPile;
        
};

#endif
