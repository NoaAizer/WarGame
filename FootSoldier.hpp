#pragma once
#include "Soldier.hpp"

using namespace WarGame;

    class FootSoldier: public Soldier{

        public:
            FootSoldier(uint playerID) : Soldier(playerID,100,10){}
            void play(vector<vector<Soldier*>> &board,std::pair<int,int> spot);
            virtual void printSoldier();
    };
