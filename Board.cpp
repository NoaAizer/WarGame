#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include "Board.hpp"

using namespace std;

namespace WarGame{
  
    // operator for putting soldiers on the game-board during initialization.
   Soldier*& Board::operator[](std::pair<int,int> location){
       return board[location.first][location.second];
    }
    // operator for reading which soldiers are on the game-board.
    Soldier* Board::operator[](std::pair<int,int> location) const{
        return board[location.first][location.second];
    }

    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument". 
    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
         Soldier *s = board[ source.first][source.second];
        if(s == nullptr)
            throw invalid_argument("ERR: No soldier on the spot");
        if(s->getPlayerNum()!= player_number)
            throw invalid_argument("ERR: This is not your soldier");
        if (s->getHealth() ==0)
        {
            throw invalid_argument("ERR: This soldier is dead");
        }

        std::pair<int,int> target;
        if(direction == Left){
            target =std::make_pair( source.first,source.second-1);
        }
          if(direction == Right){
            target =std::make_pair( source.first,source.second+1);
        }
          if(direction == Up){
            target =std::make_pair( source.first+1,source.second);
        }
          if(direction == Down){
            target =std::make_pair( source.first-1,source.second);
        }
        if(target.first<0 || target.first>=board.size() || target.second<0 || target.second >=board[0].size())
             throw invalid_argument("ERR: Try to move out of the board");
        if(board[target.first][target.second]!=nullptr)
             throw invalid_argument("ERR: The location is already taken");
        board [target.first][target.second]=s;
        board[ source.first][ source.second]=nullptr;
        s->play(board, target);
    }

    // returns true iff the board contains one or more soldiers of the given player.
    bool Board::has_soldiers(uint player_number) const{
        for(int row=0; row < board.size();row++){
            for(int col=0;col<board[0].size();col++)
                if(board[row][col] != nullptr && board[row][col]->getPlayerNum() == player_number && board[row][col]->getHealth()!=0)
                    return true;
        }
        return false;
    }

}