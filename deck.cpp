#include "deck.hpp"
#include <iostream>

std::vector<std::string> Deck::colors  = {"red", "yellow", "blue", "green"};

Deck::Deck(){
    setTopOfDeck(0);
}

Deck::Deck(std::vector<Card> &aDeck, int top){
    this->theDeck = aDeck;
    setTopOfDeck(top);
}

void Deck::setTopOfDeck(int top){
    this->topOfDeck = top;
}

int Deck::getTop(){
    return topOfDeck;
}

Deck Deck::makeStartingDeck(){
    std::vector<Card> deck;

    for(int i = 0; i < 4; i++){
        Card c = Card(colors.at(i), 0);
        deck.push_back(c);
    }

   for(int i = 0; i < 9; i++){
        for(int j = 0; j < 4; j++){
            Card c = Card(colors.at(j), i + 1);
            deck.push_back(c);
            deck.push_back(c);
        }
    }

    for(int i = 0; i < 4; i++){
	Card c = Card(colors.at(i), 20, "reverse");
	deck.push_back(c);
	deck.push_back(c);
	c = Card(colors.at(i), 20, "skip");
	deck.push_back(c);
	deck.push_back(c);
	c = Card(colors.at(i), 20, "draw2");
	deck.push_back(c);
	deck.push_back(c);
    }

    for(int i = 0; i < 4; i++){
        Card c = Card("wild", 50, "wild");
        deck.push_back(c);

        c = Card("wild", 50, "draw4");
        deck.push_back(c);
    }

    Deck d = Deck(deck, deck.size() - 1);
    
    return d;
}
