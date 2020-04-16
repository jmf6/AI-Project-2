#include "card.hpp"

Card::Card(string color, int value){
	setColor(color);
	setValue(value);
	setIsAction(false);
	setAction(null);
}

Card::Card(string color, int value, string action){
	setColor(color);
	setValue(value);
	setIsAction(true);
	setAction(action);
}

void Card::setColor(string color){
	this->color = color;
}

void Card::setIsAction(bool isAction){
	this->isAction = isAction;
}

void Card::setAction(string action){
	this->action = action;
}

void Card::setValue(int value){
	this->value = value;
}

string Card::getColor(){
	return this->color;
}

string Card::getAction(){
	return this->action;
}

int Card::getValue(){
	return this->value;
}

bool Card::getIsAction(){
	return this->isAction;
}
