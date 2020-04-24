#pragma once
#include "player.hpp"
#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP

class AIplayer : public Player{
    public:
        AIplayer();
        int play() override; //put all the AI magic here
};

#endif
