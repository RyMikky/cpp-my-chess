#include "chess_game.h"

ChessGame::ChessGame(std::string param): deck_(ChessDeck(param)) {
	if (param == "тест") {
		MainTest(deck_);
		
	}
	else {
		std::cerr << "Параметр конструктора задан неверно. Вызван деструктор" << std::endl;
		ChessGame::~ChessGame();
	}
}

ChessGame::ChessGame(GameStatus status) : deck_(status){
}

void ChessGame::GameReset() {
	ChessDeck new_deck;
	deck_ = new_deck;

	total_white_player_moves_count_ = 0;
	total_black_player_moves_count_ = 0;
};

void ChessGame::Print() {
	system("cls");
	deck_.DeckPrint();
}

void ChessGame::GetPlayerTotalMoveCount(FigureColor color) {
	if (FigureColor::white == color) {
		std::cout << "Игрок белыми сделал суммарно " << total_white_player_moves_count_ << " ходов" << std::endl;
	}
	else if (FigureColor::black == color) {
		std::cout << "Игрок черными сделал суммарно " << total_black_player_moves_count_ << " ходов" << std::endl;
	}
	else {
		std::cout << "Неверно указан цвет игрока" << std::endl;
	}
}

void ChessGame::PlayerMove(std::string label, FigureColor color, const int& x1, const int& y1, const int& x2, const int& y2) {
	Figure set = deck_.GetCurrentPosition(x1, y1);
	bool move;
	if (label == set.label_) {
		move = deck_.FigureMove(label, color, x1, y1, x2, y2);
	}
	else {
		move = deck_.FigureMove(set.label_, color, x1, y1, x2, y2);
	}

	if (move) {
		color == FigureColor::white ? total_white_player_moves_count_++ : total_black_player_moves_count_++;
	}

	ChessGame::Print();
}

//ChessGame::TheGame_::TheGame_(const size_t& id)
//	: game_id_(id) {
//}
//
//ChessGame::TheGame_::TheGame_(const size_t& id, GameStatus status)
//	: game_id_(id), game_status_(status) {
//}
//
//ChessGame::TheGame_::TheGame_(const size_t& id, GameStatus status, const std::string& title)
//	: game_id_(id), game_status_(status), game_title_(title) {
//}