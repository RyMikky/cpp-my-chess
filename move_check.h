#pragma once
#include "figures.h"

#include <vector>

// �������� ������������� ����
bool DialineColision(std::vector<std::vector<Figure>>& deck,
	const int& x1, const int& y1, const int& x2, const int& y2);

// �������� ������� ����
bool DirectlineColision(std::vector<std::vector<Figure>>& deck,
	const int& x1, const int& y1, const int& x2, const int& y2);

// �������� �������� ������
bool KingMoveCheck(std::vector<std::vector<Figure>>& deck, 
	const int& x1, const int& y1, const int& x2, const int& y2);

// �������� �������� ��������
bool QueenMoveCheck(std::vector<std::vector<Figure>>& deck, 
	const int& x1, const int& y1, const int& x2, const int& y2);

// �������� �������� �����
bool TowerMoveCheck(std::vector<std::vector<Figure>>& deck, 
	const int& x1, const int& y1, const int& x2, const int& y2);

// �������� �������� �������
bool OfficerMoveCheck(std::vector<std::vector<Figure>>& deck,
	const int& x1, const int& y1, const int& x2, const int& y2);

// �������� �������� ����
bool HorseMoveCheck(std::vector<std::vector<Figure>>& deck,
	const int& x1, const int& y1, const int& x2, const int& y2);

// �������� �������� �����
bool SolderMoveCheck(std::vector<std::vector<Figure>>& deck,
	const FigureColor& color, const int& x1, const int& y1, const int& x2, const int& y2);


