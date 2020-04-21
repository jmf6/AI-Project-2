#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player{                              // Base Player class
    private:                                // No one may access this other than the player

    protected:                              // protected means inherited classes can access this data, as opposed to private
    
    public:
        Player();
        virtual int play();                 // override-able behavior
        void addToHand(Card c);
        vector<Card> hand;

};
#endif
