#pragma once

#include "Soldier.hpp"

using namespace WarGame;

class Sniper: public Soldier{

    public:
        Sniper(uint playerID) : Soldier(playerID,100,50){}
        void play(vector<vector<Soldier*>> &board,std::pair<int,int> spot);
        virtual void printSoldier();
};
