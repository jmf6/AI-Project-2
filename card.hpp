#ifndef CARD_HPP
#define CARD_HPP
#include <string>
class Card{
    public:
	Card(string color, int value);
        Card(string color, int value, string action);
        void setColor(string color);
	void setIsAction(bool isAction);
        void setAction(string action);
        void setValue(int value);
        string getColor();
        string getAction();
        int getValue();
	bool getIsAction();

    private:
        string color;
        bool isAction;
	string action;
        int value;
}

#endif
