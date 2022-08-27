#include "game_test_system.h"

void GlobalTest() {
	ChessDeck deck_("тест");
	system("cls");
	{
		std::cerr << "Запущена система основного тестирования" << std::endl;
		std::cerr << "Создание доски без расставленных фигур";

		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				assert(deck_.GetCurrentPosition(x, y).type_ == FigureType::zero);
				Sleep(rand() % 20);
				std::cerr << ".";
			}
		}
		Sleep(300);
		std::cerr << "Успешно" << std::endl << std::endl;
	}

	{
		Sleep(500);
		std::cerr << "Создание фигуры и установка фигуры на доску" << std::endl;
		std::cerr << "Размещение фигуры {";
		Figure queen(1, "Ш", "Ферзь", FigureType::queen, FigureColor::black, true);
		std::cerr << queen.name_;

		deck_.FigureAdd(queen, 2, 1);
		std::cerr << "} по коордиатам B6";
		assert(deck_.GetCurrentPosition(2, 1).type_ == FigureType::queen);

		for (int i = 0; i < 60; i++) {
			Sleep(rand() % 5);
			std::cerr << ".";
		}

		Sleep(200);
		std::cerr << "Успешно" << std::endl << std::endl;
	}

	{
		Sleep(500);
		std::cerr << "Отображение игрового поля" << std::endl << std::endl;
		deck_.DeckPrint();
		Sleep(2000);

		//Затираем ранее выведенное
		HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cd{};
		
		cd.X = 0;
		cd.Y = 6;
		SetConsoleCursorPosition(hd, cd);	

		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 40; j++) {
				std::cout << " ";
			}
			std::cout << std::endl;
		}

		SetConsoleCursorPosition(hd, cd);
	}
	
	{
		ChessDeck deck_2;
		Sleep(500);
		std::cerr << "Создание типового игрового поля" << std::endl;
		std::cerr << "Размещение фигур";
		for (int i = 0; i < 60; i++) {
			Sleep(rand() % 5);
			std::cerr << ".";
		}

		Sleep(200);
		std::cerr << "Успешно" << std::endl << std::endl;

		system("pause");
	}

}

void MainTest(ChessDeck& deck_) {
	system("cls");
	{
		std::cerr << "Запущена система основного тестирования" << std::endl;
		std::cerr << "Создание доски без расставленных фигур";

		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				assert(deck_.GetCurrentPosition(x, y).type_ == FigureType::zero);
				Sleep(rand() % 50);
				std::cerr << ".";
			}
		}
		Sleep(500);
		std::cerr << "Успешно" << std::endl << std::endl;
	}
	
	{
		Sleep(500);
		std::cerr << "Создание фигуры и установка фигуры на доску" << std::endl;
		std::cerr << "Размещение фигуры {";
		Figure queen(1, "Ш", "Ферзь", FigureType::queen, FigureColor::black, true);
		std::cerr << queen.name_;

		deck_.FigureAdd(queen, 2, 1);
		std::cerr << "} по коордиатам B6";
		assert(deck_.GetCurrentPosition(2, 1).type_ == FigureType::queen);

		for (int i = 0; i < 60; i++) {
			Sleep(rand() % 10);
			std::cerr << ".";
		}

		Sleep(500);
		std::cerr << "Успешно" << std::endl << std::endl;
	}

	Sleep(500);
	std::cerr << "Отображение игрового поля" << std::endl;
	deck_.DeckPrint();

}