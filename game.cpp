#include "game.hpp"
#include "deck.hpp"
#include "card.hpp"

Game::Game(){
    drawPile = makeStartingDeck();
    discardPile = new Deck();

    drawPile.theDeck.shuffle();

    dealCards();

    discardPile.push_back(drawCard());
}       

void Game::dealCards(){
    for(int i = 0; i < 7; i++){
        Card c = drawCard();
        p1.addToHand(c);
        c = drawCard();
        p2.addToHand(c);
    }
}       

Card Game::drawCard(){
    Card c = drawPile.getTop();
    drawPile.theDeck.pop_back();
    drawPile.setTop(drawPile.theDeck.size() - 1);
}
