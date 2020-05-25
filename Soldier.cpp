#include <math.h>  
#include "Soldier.hpp"

namespace WarGame
{
    double Soldier::distance(uint x1, uint y1, uint x2, uint y2){
        return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    }
    void Soldier::cure(){
        hp=fullHealth;
    }
    void Soldier::shoot(uint power){
        hp-=power;
        if(hp<=0){
            cout<<"dead"<<endl;
            hp=0;
        }
        
    }
    
    void Soldier::printSoldier(){
            cout << player << ", Health Points:" << hp;
    }
  
}