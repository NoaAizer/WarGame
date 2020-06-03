#pragma once

#include "Soldier.hpp"

using namespace WarGame;

    class ParamedicCommander: public Soldier{

        public:
            ParamedicCommander(uint playerID) : Soldier(playerID,200){}
            void play(vector<vector<Soldier*>> &board,std::pair<int,int> spot);
            virtual void printSoldier();
    };
