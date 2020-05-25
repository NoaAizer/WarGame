#include <math.h>
#include <string>
#include <vector>
#include <iostream>  
#include "Soldier.hpp"
#include "Paramedic.hpp"

using namespace std;

namespace WarGame{
   void Paramedic::play(vector<vector<Soldier*>> &board,std::pair<int,int> spot){
        Soldier* sol;
        int row,col;
        uint currHealth;
        for(row=0; row < board.size();row++){
            for(col=0;col<board[0].size();col++){
                Soldier* sol = board[row][col];
                double dis=distance(spot.first, spot.second,row,col);
                 if(sol!=nullptr && sol->getPlayerNum()== this->player 
                 && dis <=sqrt(2) && dis!=0){
                    printSoldier();
                    cout << "Cure:"; 
                    sol->printSoldier(); cout << endl;
                    sol->cure();
                 }
            }
        }
    }


    void Paramedic::printSoldier()
    {
        cout << "("
             << "Paramedic:";
        Soldier::printSoldier();
        cout << ")";
    }
}


