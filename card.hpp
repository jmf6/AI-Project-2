#ifndef CARD_HPP
#define CARD_HPP
#include <string>
class Card{
    public:
	Card(std::string color, int value);
        Card(std::string color, int value, std::string action);
        void setColor(std::string color);
	void setIsAction(bool isAction);
        void setAction(std::string action);
        void setValue(int value);
	std::string getColor();
	std::string getAction();
        int getValue();
	bool getIsAction();

    private:
	std::string color;
        bool isAction;
	std::string action;
        int value;
};

#endif
