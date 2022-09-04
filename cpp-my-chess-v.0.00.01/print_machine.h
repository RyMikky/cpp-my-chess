#pragma once
#include <Windows.h>
#include <iostream>

#include "system_defines.h" //����� ���������� ��������, ������������ � ������ ��������


void MainMenuPrint() {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, white_text);
	system("cls");
	std::cout << "   ����� ���������� � �������" << std::endl << std::endl;
	std::cout << "   �������� ������������ ��� ����� ����" << std::endl;
	std::cout << "   " << MenuPoint::game_start << " - ������ ����� ���� " << std::endl;
	std::cout << "   " << MenuPoint::game_sleep << " - ���������� ������ ���� " << std::endl;
	std::cout << "   " << MenuPoint::game_resume << " - ���������� ������ ���� " << std::endl;
	std::cout << "   " << MenuPoint::game_save << " - ��������� ������ ���� " << std::endl;
	std::cout << "   " << MenuPoint::game_load << " - ��������� ������ ���� " << std::endl;
	std::cout << "   " << MenuPoint::game_stats << " - �������� ���������� ������� ���� " << std::endl << std::endl;
	std::cout << "   " << MenuPoint::game_test << " - ��������� ����-������� " << std::endl;
	std::cout << "   " << MenuPoint::game_about << " - � ��������� " << std::endl << std::endl;
	std::cout << "   " << MenuPoint::game_exit << " - ����� �� ���� " << std::endl << std::endl;
}

void GameStartPrint() {

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	

	system("cls");
	// � ������� ������ �������� ���������, ������ - ���� ������
	SetConsoleTextAttribute(hConsole, (WORD)((black_text << 4/*background*/) | white_text/*text*/));
	std::cout << std::endl; 
	WAIT(300);
	
	{
		std::cout << "   ������ �� �������";
		WAIT(50);
		for (int i = 0; i < 46; i++) {
			WAIT(rand() % 150)

				std::cout << ".";
		}
		std::cout << " /" << std::endl;
	}
	
	{
		std::cout << "   ��������� ����� �� ����";
		WAIT(50);
		for (int i = 0; i < 40; i++) {
			WAIT(rand() % 250);
			std::cout << ".";
		}
		std::cout << " /" << std::endl;
	}

	{
		std::cout << "   ������������� �� ������";
		WAIT(50);
		for (int i = 0; i < 40; i++) {
			WAIT(rand() % 140);
			std::cout << ".";
		}
		std::cout << " /" << std::endl;
	}
	
	{
		std::cout << "   ���������� ������� ����";
		WAIT(50);
		for (int i = 0; i < 40; i++) {
			WAIT(rand() % 100);
			std::cout << ".";
		}
		std::cout << " /" << std::endl;
	}

	{
		std::cout << "   ����������� �������";
		WAIT(50);
		for (int i = 0; i < 44; i++) {
			WAIT(rand() % 50);
			std::cout << ".";
		}
		std::cout << " /" << std::endl;
	}

	WAIT(1000);
	std::cout << "   ������� ����!" << std::endl;
	WAIT(1000);
}

void GameSavePrint() {

}