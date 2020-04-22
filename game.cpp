#include "game.hpp"
#include "deck.hpp"
#include "card.hpp"
#include "player.hpp"

Game::Game(){
    p1 = Player();
    p2 = Player();
    drawPile = drawPile.makeStartingDeck();
    discardPile = Deck();

    //drawPile.theDeck.shuffle();

    dealCards();

    discardPile.theDeck.push_back(drawCard());
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
    Card c = drawPile.theDeck.at(drawPile.getTop());
    drawPile.theDeck.pop_back();
    drawPile.setTopOfDeck(drawPile.theDeck.size() - 1);

    return c;
}
