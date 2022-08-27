#pragma once
#include "game_menu.h"
#include "print_machine.h"
#include "chess_game.h"
#include "system_defines.h" //общая библиотека макросов, перечислений и прочих дефайнов

#include <thread>
#include <chrono>



void SaveTheGame(const ChessGame& game) {
	//очищаем консоль

	system("cls");
	std::this_thread::sleep_for(std::chrono::milliseconds(500));



	std::cout << "мы сохраняемся!" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}