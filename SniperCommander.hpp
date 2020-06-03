#pragma once
#include "Soldier.hpp"

using namespace WarGame;

    class SniperCommander: public Soldier{

        public:
            SniperCommander(uint playerID) : Soldier(playerID,120,100){}
            void play(vector<vector<Soldier*>> &board,std::pair<int,int> spot);
            virtual void printSoldier();
    };
