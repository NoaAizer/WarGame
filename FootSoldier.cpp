#include <math.h>
#include <string>
#include <vector>
#include <iostream>  
#include "Soldier.hpp"
#include "FootSoldier.hpp"
using namespace std;
using namespace WarGame;


   void FootSoldier::play(vector<vector<Soldier*>> &board,std::pair<int,int> spot){
        pair<double, Soldier*> toAttack =make_pair( __DBL_MAX__, nullptr);
        Soldier* sol;
        int row,col;
        double currDis;
        for(row=0; row < board.size();row++){
            for(col=0;col<board[0].size();col++){
                Soldier* sol = board[row][col];
                 if(sol!=nullptr && sol->getPlayerNum()!= this->player){
                    currDis= distance(spot.first,spot.second,row,col);
                    if(currDis< toAttack.first){ // The closest soldier
                        printSoldier();
                        cout << "Shoot:";
                        toAttack.first=currDis;
                        toAttack.second=sol;
                        
                    }
                 }
            }
        }
    if(toAttack.second!=nullptr){
        //toAttack.second->printSoldier(); cout << endl;
        toAttack.second->shoot(ppa);
        if(toAttack.second->getHealth()==0){
            delete toAttack.second;
            toAttack.second=nullptr;
        }
    }
    }
    void FootSoldier::printSoldier()
    {
        cout << "("
             << "FootSoldier:";
        Soldier::printSoldier();
        cout << ")";
    }



