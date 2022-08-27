#pragma once
#include <Windows.h>
#include <iostream>

#include "system_defines.h" //общая библиотека макросов, перечислений и прочих дефайнов


void MainMenuPrint() {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, white_text);
	system("cls");
	std::cout << "   Добро пожаловать в Шахматы" << std::endl << std::endl;
	std::cout << "   Выберете интересующий Вас пункт меню" << std::endl;
	std::cout << "   " << MenuPoint::game_start << " - Начать новую игру " << std::endl;
	std::cout << "   " << MenuPoint::game_sleep << " - Остановить теущую игру " << std::endl;
	std::cout << "   " << MenuPoint::game_resume << " - Продолжить теущую игру " << std::endl;
	std::cout << "   " << MenuPoint::game_save << " - Сохранить теущую игру " << std::endl;
	std::cout << "   " << MenuPoint::game_load << " - Загрузить теущую игру " << std::endl;
	std::cout << "   " << MenuPoint::game_stats << " - Показать статистику текущей игры " << std::endl << std::endl;
	std::cout << "   " << MenuPoint::game_test << " - Запустить тест-систему " << std::endl;
	std::cout << "   " << MenuPoint::game_about << " - О программе " << std::endl << std::endl;
	std::cout << "   " << MenuPoint::game_exit << " - Выход из игры " << std::endl << std::endl;
}

void GameStartPrint() {

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	

	system("cls");
	// в команде первое значение бекгрануд, второе - цвет текста
	SetConsoleTextAttribute(hConsole, (WORD)((black_text << 4/*background*/) | white_text/*text*/));
	std::cout << std::endl; 
	WAIT(300);
	
	{
		std::cout << "   Роемся на чердаке";
		WAIT(50);
		for (int i = 0; i < 46; i++) {
			WAIT(rand() % 150)

				std::cout << ".";
		}
		std::cout << " /" << std::endl;
	}
	
	{
		std::cout << "   Протираем доску от пыли";
		WAIT(50);
		for (int i = 0; i < 40; i++) {
			WAIT(rand() % 250);
			std::cout << ".";
		}
		std::cout << " /" << std::endl;
	}

	{
		std::cout << "   Распологаемся за столом";
		WAIT(50);
		for (int i = 0; i < 40; i++) {
			WAIT(rand() % 140);
			std::cout << ".";
		}
		std::cout << " /" << std::endl;
	}
	
	{
		std::cout << "   Вспоминаем правила игры";
		WAIT(50);
		for (int i = 0; i < 40; i++) {
			WAIT(rand() % 100);
			std::cout << ".";
		}
		std::cout << " /" << std::endl;
	}

	{
		std::cout << "   Расставляем фигурки";
		WAIT(50);
		for (int i = 0; i < 44; i++) {
			WAIT(rand() % 50);
			std::cout << ".";
		}
		std::cout << " /" << std::endl;
	}

	WAIT(1000);
	std::cout << "   Хорошей игры!" << std::endl;
	WAIT(1000);
}

void GameSavePrint() {

}