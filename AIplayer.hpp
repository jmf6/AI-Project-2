#pragma once
#include "player.hpp"
#include "Rules.hpp"
#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP

class AIplayer : public Player{
    public:
        AIplayer();
        Card play(Card discard) override; //put all the AI magic here
};

#endif

