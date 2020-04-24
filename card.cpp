#include "card.hpp"

Card Card::turnOver = Card("red", -100);

Card::Card(std::string color, int value){
	setColor(color);
	setValue(value);
	setIsAction(false);
	setAction("none");
}

Card::Card(std::string color, int value, std::string action){
	setColor(color);
	setValue(value);
	setIsAction(true);
	setAction(action);
}

void Card::setColor(std::string color){
	this->color = color;
}

void Card::setIsAction(bool isAction){
	this->isAction = isAction;
}

void Card::setAction(std::string action){
	this->action = action;
}

void Card::setValue(int value){
	this->value = value;
}

std::string Card::getColor(){
	return this->color;
}

std::string Card::getAction(){
	return this->action;
}

int Card::getValue(){
	return this->value;
}

bool Card::getIsAction(){
	return this->isAction;
}
