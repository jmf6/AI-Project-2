#ifndef DECK_HPP
#define DECK_HPP
#include "card.hpp"

class Deck{
	public:
	    Deck();
	    Deck(vector<Card> &aDeck);
	    Deck makeStartingDeck();
	    vector<Card> getDeck();
	    int getTop();
	    void setDeck(vector<Card> &aDeck);
	    void setTop(int top);

	private:
	    vector<string> colors("red", "yellow", "blue", "green");
	    int topOfDeck;
	    vector<Card> theDeck;
}
