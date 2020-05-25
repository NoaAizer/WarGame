#include <math.h>
#include <string>
#include <vector>
#include <iostream>  
#include "Soldier.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"


namespace WarGame{
   void ParamedicCommander::play(vector<vector<Soldier*>> &board,std::pair<int,int> spot){
        Soldier* sol;
        int row,col;
        uint currHealth;
        for(row=0; row < board.size();row++){
            for(col=0;col<board[0].size();col++){
                Soldier* sol = board[row][col];
                if(sol != nullptr) {        
                if(sol->getPlayerNum() == player){
                    sol->printSoldier();
                    if(Paramedic* ps=dynamic_cast<Paramedic*>(sol)){
				    	ps->play(board,{row,col});
                	}	}}
            }
        }
    }

    void ParamedicCommander::printSoldier()
    {
        cout << "("
             << "ParamedicCommander:";
        Soldier::printSoldier();
        cout << ")";
    }
}


