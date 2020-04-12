#ifndef CARD_HPP
#define CARD_HPP
#include <string>
class Card{
    public:
        Card(string color, string action, int value);
        void setColor(string color);
        void setAction(string action);
        void setValue(int value);
        string getColor();
        string getAction();
        int getValue();

    private:
        string color;
        string action;
        int value;
}
