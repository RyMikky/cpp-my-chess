#include "game_test_system.h"

void GlobalTest() {
	ChessDeck deck_("����");
	system("cls");
	{
		std::cerr << "�������� ������� ��������� ������������" << std::endl;
		std::cerr << "�������� ����� ��� ������������� �����";

		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				assert(deck_.GetCurrentPosition(x, y).type_ == FigureType::zero);
				Sleep(rand() % 20);
				std::cerr << ".";
			}
		}
		Sleep(300);
		std::cerr << "�������" << std::endl << std::endl;
	}

	{
		Sleep(500);
		std::cerr << "�������� ������ � ��������� ������ �� �����" << std::endl;
		std::cerr << "���������� ������ {";
		Figure queen(1, "�", "�����", FigureType::queen, FigureColor::black, true);
		std::cerr << queen.name_;

		deck_.FigureAdd(queen, 2, 1);
		std::cerr << "} �� ���������� B6";
		assert(deck_.GetCurrentPosition(2, 1).type_ == FigureType::queen);

		for (int i = 0; i < 60; i++) {
			Sleep(rand() % 5);
			std::cerr << ".";
		}

		Sleep(200);
		std::cerr << "�������" << std::endl << std::endl;
	}

	{
		Sleep(500);
		std::cerr << "����������� �������� ����" << std::endl << std::endl;
		deck_.DeckPrint();
		Sleep(2000);

		//�������� ����� ����������
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
		std::cerr << "�������� �������� �������� ����" << std::endl;
		std::cerr << "���������� �����";
		for (int i = 0; i < 60; i++) {
			Sleep(rand() % 5);
			std::cerr << ".";
		}

		Sleep(200);
		std::cerr << "�������" << std::endl << std::endl;

		system("pause");
	}

}

void MainTest(ChessDeck& deck_) {
	system("cls");
	{
		std::cerr << "�������� ������� ��������� ������������" << std::endl;
		std::cerr << "�������� ����� ��� ������������� �����";

		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				assert(deck_.GetCurrentPosition(x, y).type_ == FigureType::zero);
				Sleep(rand() % 50);
				std::cerr << ".";
			}
		}
		Sleep(500);
		std::cerr << "�������" << std::endl << std::endl;
	}
	
	{
		Sleep(500);
		std::cerr << "�������� ������ � ��������� ������ �� �����" << std::endl;
		std::cerr << "���������� ������ {";
		Figure queen(1, "�", "�����", FigureType::queen, FigureColor::black, true);
		std::cerr << queen.name_;

		deck_.FigureAdd(queen, 2, 1);
		std::cerr << "} �� ���������� B6";
		assert(deck_.GetCurrentPosition(2, 1).type_ == FigureType::queen);

		for (int i = 0; i < 60; i++) {
			Sleep(rand() % 10);
			std::cerr << ".";
		}

		Sleep(500);
		std::cerr << "�������" << std::endl << std::endl;
	}

	Sleep(500);
	std::cerr << "����������� �������� ����" << std::endl;
	deck_.DeckPrint();

}