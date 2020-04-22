#ifndef DECK_HPP
#define DECK_HPP
#include <vector>
#include "card.hpp"

class Deck{
	public:
	    Deck();
	    Deck(std::vector<Card> &aDeck, int top);
	    std::vector<Card> getDeck();
	    int getTop();
	    Deck makeStartingDeck();
	    void setDeck(std::vector<Card> &aDeck);
	    void setTopOfDeck(int top);
	    std::vector<Card> theDeck;

	private:
	    std::vector<std::string> colors = {"red", "yellow", "blue", "green"};
	    int topOfDeck;
};

#endif
