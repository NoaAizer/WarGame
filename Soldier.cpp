#include <math.h>  
#include "Soldier.hpp"

namespace WarGame
{
    double Soldier::distance(int x1, int y1, int x2, int y2){
        return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    }
    void Soldier::cure(){
            hp=fullHealth;
    }
    void Soldier::shoot(uint power){
        hp-=power;
        if(hp<0)
            hp=0;
    }
    
    void Soldier::printSoldier(){
        cout << player << ", Health Points:" << hp;
    }
  
}