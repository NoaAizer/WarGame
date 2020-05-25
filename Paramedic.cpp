#include <math.h>
#include <string>
#include <vector>
#include <iostream>  
#include "Soldier.hpp"
#include "Paramedic.hpp"

using namespace std;

namespace WarGame{
   void Paramedic::play(vector<vector<Soldier*>> &board,std::pair<int,int> spot){
       int i=spot.first;
       int j= spot.second;
        printSoldier();
        cout << "Cure:"; 
        bool flag=false;
    
        if( (i-1)>=0 && board[i-1][j] != nullptr){
            if(board[i-1][j]->getPlayerNum()== player ) {
                board[i-1][j]->printSoldier(); cout << endl;
                flag=true;
                board[i-1][j]->cure();}
        }
        
        if( (j+1)<=(board[0].size()-1) && board[i][j+1] != nullptr){
            if(board[i][j+1]->getPlayerNum()== player ) {
                board[i][j+1]->printSoldier(); cout << endl;
                flag=true;
                board[i][j+1]->cure();}
        }
        if((j-1)>=0 && board[i][j-1] != nullptr){
        if(board[i][j-1]->getPlayerNum()== player){
                board[i][j-1]->printSoldier(); cout << endl;
                flag=true;
                board[i][j-1]->cure();}
        }
        if((i+1)<=(board[0].size()-1)&& board[i+1][j] != nullptr){
            if(board[i+1][j]->getPlayerNum()== player){
                board[i+1][j]->printSoldier(); cout << endl; 
                flag=true;
                board[i+1][j]->cure();}
        }

         cout << "No one"<<endl; 
   

    }


    void Paramedic::printSoldier()
    {
        cout << "("
             << "Paramedic:";
        Soldier::printSoldier();
        cout << ")";
    }
}


