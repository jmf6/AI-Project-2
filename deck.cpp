#include "deck.hpp"

Deck::Deck(){
    setTopOfDeck(0);
}

Deck::Deck(vector<Card> &aDeck){
    this->theDeck = aDeck;
    setTopOfDeck(theDeck.size() - 1);
}

Deck Deck::makeStartingDeck(){
    vector<Card> deck;

    for(int i = 0; i < 4; i++){
	Card c = new Card(colors.at[i], 0);
	deck.push_back(c);
    }

   for(int i = 0; i < 9; i++){
	for(int j = 0; j < 4; j++){
	    Card c = new Card(colors.at[j], i + 1);
	    deck.push_back(c);
	    deck.push_back(c);
	    Card c = new Card(colors.at[j], 20, "reverse");
	    deck.push_back(c);
	    deck.push_back(c);
	    Card c = new Card(colors.at[j], 20, "skip");
            deck.push_back(c);
            deck.push_back(c);
	    Card c = new Card(colors.at[j], 20, "draw2");
            deck.push_back(c);
            deck.push_back(c);
	}
    }   

    for(int i = 0; i < 4; i++){
	Card c = new Card("wild", 50, "wild");
	deck.push_back(c);
        deck.push_back(c);
	deck.push_back(c);
        deck.push_back(c);

	Card c = new Card("wild", 50, "draw4");
	deck.push_back(c);
        deck.push_back(c);
	deck.push_back(c);
        deck.push_back(c);
    }

    return deck;
}
