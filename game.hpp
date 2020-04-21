#ifndef GAME_HPP
#define GAME_HPP
#include <string>
class Game{
    public:
        Game();
        void dealCards();
        Player p1; //human player
        Player p2; //AI

    private:
        Deck drawPile;
        Deck discardPile;
        
}

#endif
