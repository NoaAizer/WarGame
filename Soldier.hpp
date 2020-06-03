#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace WarGame
{
  class Soldier{
  protected:
      uint player;
      int fullHealth;
      int hp; // Health Points
      int ppa; // Power Per Activity (Damage/Health)
  

    public:
      Soldier(uint playerID, int h, int p=0) : player(playerID), fullHealth(h), hp(h), ppa(p) {}
      double distance(uint x1, uint y1, uint x2, uint y2);
      void cure();
      void shoot(int power);
      uint getPlayerNum(){ return player;}
      int getHealth(){ if(hp<=0)return 0; else return hp;}
      virtual void play(vector<vector<Soldier*>> &board,std::pair<int,int> spot){;}
      virtual void printSoldier();
    };
}