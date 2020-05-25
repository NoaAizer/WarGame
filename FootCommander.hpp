#include "Soldier.hpp"

namespace WarGame{
    class FootCommander: public Soldier{

        public:
            FootCommander(uint playerID) : Soldier(playerID,150,20){}
            void play(vector<vector<Soldier*>> &board,std::pair<int,int> spot);
             virtual void printSoldier();
    };
}