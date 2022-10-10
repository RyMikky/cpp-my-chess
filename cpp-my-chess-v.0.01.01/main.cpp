//#include "chess_deck.h" // Движок доски
//#include "chess_game.h" // Движок игры
#include "game_menu.h" // Меню игры
#include "game_resource.h"
#include "unit_test_frame.h"

int main() {
	
	setlocale(LC_ALL, "Russian");

	chess::test_frame::RunAllTestes();

 	return 0;
}