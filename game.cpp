#include "game.hpp"
#include <algorithm>
#include <iostream>
Game::Game(){
    p1 = HumanPlayer();
    p2 = AIplayer();
    drawPile = Deck::makeStartingDeck();
    discardPile = Deck();

    srand(time(NULL));
    int shuffle = std::rand() % 15 + 10; // 10 - 24 times

    for(int i = 0; i < shuffle; i++){
        std::random_shuffle(drawPile.theDeck.begin(), drawPile.theDeck.end());
    }

    dealCards();

    discardPile.theDeck.push_back(drawCard());
}

void Game::dealCards(){
    for(int i = 0; i < 7; i++){
        Card c = drawCard();
        p2.addToHand(c);
        c = drawCard();
        p1.addToHand(c);
    }
}

Card Game::drawCard(){
    Card c = drawPile.theDeck.at(drawPile.getTop());
    drawPile.theDeck.pop_back();
    drawPile.setTopOfDeck(drawPile.theDeck.size() - 1);

    return c;
}

Card Game::getDiscard(){
    return discardPile.theDeck.at(discardPile.theDeck.size() - 1);
}
