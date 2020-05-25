
#include <string>
#include <vector>
#include <iostream>  
#include "Soldier.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
using namespace std;

namespace WarGame{
   void SniperCommander::play(vector<vector<Soldier*>> &board,std::pair<int,int> spot){
        pair<uint, Soldier*> toAttack =make_pair( 0 , nullptr);
        Soldier* sol;
        int row,col;
        uint currHealth;
        for(row=0; row < board.size();row++){
            for(col=0;col<board[0].size();col++){
                Soldier* sol = board[row][col];
                if(sol!=nullptr){
                  if(sol->getPlayerNum()!= this->player){
                        currHealth= sol->getHealth();
                    if(currHealth>= toAttack.first){ // The closest soldier
                        toAttack.first=currHealth;
                        toAttack.second=sol;
                        printSoldier();
                        cout << "Shoot:";
                        toAttack.second->printSoldier();
                        cout << endl;
                    }
                 }
                 else if(Sniper* ps=dynamic_cast<Sniper*>(sol)){
				    	ps->play(board,{row,col});
                	}
                }
            }
        }
    
    toAttack.second->shoot(ppa);
    if(toAttack.second->getHealth()==0){
        delete toAttack.second;
       toAttack.second=nullptr;
    }
    }
    void SniperCommander::printSoldier()
    {
        cout << "("
             << "SniperCommander:";
        Soldier::printSoldier();
        cout << ")";
    }
}


