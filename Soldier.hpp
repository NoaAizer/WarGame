#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace WarGame
{
class Soldier{
protected:
    uint player;
    uint fullHealth;
    uint hp; // Health Points
    uint ppa; // Power Per Activity (Damage/Health)
 

  public:
    Soldier(uint playerID, uint h, uint p=0) : player(playerID), fullHealth(h), hp(h), ppa(p) {}
    double distance(int x1, int y1, int x2, int y2);
    void cure();
    void shoot(uint power);
    uint getPlayerNum(){ return player;}
    uint getHealth(){ return hp;}
    virtual void play(vector<vector<Soldier*>> &board,std::pair<int,int> spot){;}
    virtual void printSoldier();
  };
}