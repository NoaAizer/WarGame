#include "doctest.h"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"



using namespace std;

namespace WarGame{

    
    

TEST_CASE("Test 1") {
    Board board(10,10);
    CHECK(board.has_soldiers(2)== false);
    CHECK(board.has_soldiers(3)== false);
    CHECK(board.has_soldiers(4)== false);
    CHECK(board.has_soldiers(8)== false);
    CHECK(board.has_soldiers(9)== false);
    CHECK(board.has_soldiers(1)== false);
	board[{0,1}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1)== true);
    board[{0,3}] = new FootCommander(1);
	board[{0,5}] = new Sniper(1);
    board[{0,6}] = new SniperCommander(1);
    board[{0,7}] = new Paramedic(1);
    board[{0,8}] = new ParamedicCommander(1);
	CHECK(board.has_soldiers(2)== false);
    CHECK(board.has_soldiers(7)== false);
	board[{9,1}] = new FootSoldier(2);
	board[{9,3}] = new FootCommander(2);
	board[{9,5}] = new FootSoldier(2);
	CHECK(board.has_soldiers(2)== true);
    board[{9,6}] = new SniperCommander(2);
    board[{9,7}] = new Paramedic(2);
    board[{9,8}] = new ParamedicCommander(2);
    CHECK_THROWS_AS(board.move(1, {0,2}, Board::MoveDIR::Left),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {0,2}, Board::MoveDIR::Left),std::invalid_argument);
    board.move(1, {0,1}, Board::MoveDIR::Right);
    CHECK_THROWS_AS(board.move(1, {0,2}, Board::MoveDIR::Right),std::invalid_argument);
    CHECK_THROWS_AS(board.move(1, {0,1}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {0,5}, Board::MoveDIR::Up),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {9,7}, Board::MoveDIR::Right),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {9,2}, Board::MoveDIR::Right),std::invalid_argument);
    CHECK_THROWS_AS(board.move(1, {9,5}, Board::MoveDIR::Up),std::invalid_argument);
    CHECK_THROWS_AS(board.move(1, {9,1}, Board::MoveDIR::Down),std::invalid_argument);
    board.move(2,{9,1},Board::MoveDIR::Down);
    CHECK_THROWS_AS(board.move(2, {9,1}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(1, {8,1}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{8,1},Board::MoveDIR::Down);
    CHECK_THROWS_AS(board.move(1, {7,1}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {8,1}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{7,1},Board::MoveDIR::Down);
    CHECK_THROWS_AS(board.move(1, {6,1}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {7,1}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{6,1},Board::MoveDIR::Right);
    CHECK_THROWS_AS(board.move(1, {6,2}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {6,1}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{6,2},Board::MoveDIR::Right);
    CHECK_THROWS_AS(board.move(1, {6,3}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {6,2}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{6,3},Board::MoveDIR::Left);
    CHECK_THROWS_AS(board.move(1, {6,2}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {6,3}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{6,2},Board::MoveDIR::Right);
    CHECK_THROWS_AS(board.move(1, {6,3}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {6,2}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{6,3},Board::MoveDIR::Down);
    CHECK_THROWS_AS(board.move(1, {5,3}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {6,3}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{5,3},Board::MoveDIR::Right);
    CHECK_THROWS_AS(board.move(2, {6,3}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {8,1}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(1, {9,5}, Board::MoveDIR::Right),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(1, {0,3}, Board::MoveDIR::Up);
    CHECK_THROWS_AS(board.move(1, {0,3}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {1,3}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(1, {1,3}, Board::MoveDIR::Up);
    CHECK_THROWS_AS(board.move(1, {1,3}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {2,3}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(1, {2,3}, Board::MoveDIR::Right);
    CHECK_THROWS_AS(board.move(1, {2,3}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {2,4}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(1, {2,4}, Board::MoveDIR::Up);
    CHECK_THROWS_AS(board.move(1, {2,4}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {3,4}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(1,{3,4},Board::MoveDIR::Up);
    CHECK_THROWS_AS(board.move(1, {3,4}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {4,4}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(1, {4,4}, Board::MoveDIR::Up),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(1,{4,4},Board::MoveDIR::Left);
    CHECK_THROWS_AS(board.move(1, {4,4}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {4,3}, Board::MoveDIR::Up),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{9,6},Board::MoveDIR::Down);
    CHECK_THROWS_AS(board.move(1, {8,6}, Board::MoveDIR::Left),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {9,6}, Board::MoveDIR::Right),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{8,6},Board::MoveDIR::Down);
    CHECK_THROWS_AS(board.move(1, {7,6}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {8,6}, Board::MoveDIR::Up),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{7,6},Board::MoveDIR::Left);
    CHECK_THROWS_AS(board.move(1, {7,5}, Board::MoveDIR::Down),std::invalid_argument);
    CHECK_THROWS_AS(board.move(2, {7,6}, Board::MoveDIR::Up),std::invalid_argument);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{7,5},Board::MoveDIR::Left);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{7,4},Board::MoveDIR::Left);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{7,3},Board::MoveDIR::Left);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{7,2},Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{6,2},Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1)== true);
    CHECK(board.has_soldiers(2)== true);
    board.move(2,{5,2},Board::MoveDIR::Right);
    CHECK_THROWS_AS(board.move(1, {0,2}, Board::MoveDIR::Down),std::invalid_argument);
    board.move(2,{9,8},Board::MoveDIR::Down);
    

}
}