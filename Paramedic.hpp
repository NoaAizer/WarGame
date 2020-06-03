#pragma once
#include "Soldier.hpp"

using namespace WarGame;

class Paramedic: public Soldier{

    public:
        Paramedic(uint playerID) : Soldier(playerID,100){}
        void play(vector<vector<Soldier*>> &board,std::pair<int,int> spot);
        virtual void printSoldier();
};
