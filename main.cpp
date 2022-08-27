//#include "chess_deck.h" // Движок доски
//#include "chess_game.h" // Движок игры
#include "game_menu.h" // Меню игры

int main() {
	
	setlocale(LC_ALL, "Russian");
	/*
	{
		ChessGame new_game;

		new_game.Print();

		new_game.PlayerMove("П", FigureColor::white, 6, 2, 4, 2);

		new_game.PlayerMove("Пешка", FigureColor::black, 1, 3, 3, 3);

		new_game.PlayerMove("П", FigureColor::white, 4, 2, 3, 3);

		new_game.GetPlayerTotalMoveCount(FigureColor::white);
		new_game.GetPlayerTotalMoveCount(FigureColor::black);

		//new_game.GameReset();

		new_game.PlayerMove("Конь", FigureColor::black, 0, 1, 0, 3); //0

		new_game.PlayerMove("Конь", FigureColor::black, 0, 1, 2, 3); //0

		new_game.PlayerMove("Конь", FigureColor::black, 0, 1, 1, 3); //1

		new_game.PlayerMove("Конь", FigureColor::black, 1, 3, 0, 5); //0

		new_game.PlayerMove("Конь", FigureColor::black, 1, 3, 2, 1); //1

		new_game.PlayerMove("Конь", FigureColor::black, 2, 1, 3, 3); //1

		//new_game.PlayerMove("Конь", FigureColor::black, 3, 2, 3, 2); //0

		new_game.GetPlayerTotalMoveCount(FigureColor::white);
		new_game.GetPlayerTotalMoveCount(FigureColor::black);

		new_game.Print();

		new_game.PlayerMove("Офицер", FigureColor::white, 7, 2, 5, 4); //0
		new_game.PlayerMove("Офицер", FigureColor::black, 0, 2, 4, 6); //1
		new_game.PlayerMove("Пешка", FigureColor::white, 6, 5, 5, 5); //1
		new_game.PlayerMove("Офицер", FigureColor::black, 4, 6, 5, 5); //1
		new_game.PlayerMove("Пешка", FigureColor::white, 6, 4, 5, 5); //1

		ChessGame test_game("тест");

		ChessGame test_game1("абракадабра");

		ChessGame test_game2;
	}
	*/

	//ChessGame new_game_;

	GameMenu start;

 	return 0;
}