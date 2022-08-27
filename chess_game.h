#pragma once
#include "chess_deck.h"
#include "game_test_system.h"	
#include "system_defines.h" // Общая библиотека макросов, перечислений и прочих дефайнов

#include <map>
#include <string>

using namespace std::string_literals;

class ChessGame {
public:

	ChessGame() = default;

	explicit ChessGame(std::string param);

	explicit ChessGame(GameStatus status);

	~ChessGame() {
		std::cout << "Вызван деструктор игры" << std::endl;
	};

	void GameReset();

	void GameMainProcess() {

	}

	void Print();

	void GetPlayerTotalMoveCount(FigureColor color);

	void PlayerMove(std::string label, FigureColor color, const int& x1, const int& y1, const int& x2, const int& y2);

private:

	ChessDeck deck_;
	//ChessDeck* deck_inf_ = &deck_;

	int total_white_player_moves_count_ = 0;
	int total_black_player_moves_count_ = 0;
};
