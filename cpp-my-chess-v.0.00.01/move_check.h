#pragma once
#include "figures.h"

#include <vector>

// Коллизия диагонального пути
bool DialineColision(std::vector<std::vector<BaseFigure>>& deck,
	const int& x1, const int& y1, const int& x2, const int& y2);

// Коллизия прямого пути
bool DirectlineColision(std::vector<std::vector<BaseFigure>>& deck,
	const int& x1, const int& y1, const int& x2, const int& y2);

// Проверка движения короля
bool KingMoveCheck(std::vector<std::vector<BaseFigure>>& deck, 
	const int& x1, const int& y1, const int& x2, const int& y2);

// Проверка движения королевы
bool QueenMoveCheck(std::vector<std::vector<BaseFigure>>& deck, 
	const int& x1, const int& y1, const int& x2, const int& y2);

// Проверка движения ладьи
bool TowerMoveCheck(std::vector<std::vector<BaseFigure>>& deck, 
	const int& x1, const int& y1, const int& x2, const int& y2);

// Проверка движения офицера
bool OfficerMoveCheck(std::vector<std::vector<BaseFigure>>& deck,
	const int& x1, const int& y1, const int& x2, const int& y2);

// Проверка движения коня
bool HorseMoveCheck(std::vector<std::vector<BaseFigure>>& deck,
	const int& x1, const int& y1, const int& x2, const int& y2);

// Проверка движения пешки
bool SolderMoveCheck(std::vector<std::vector<BaseFigure>>& deck,
	const BaseFigureColor& color, const int& x1, const int& y1, const int& x2, const int& y2);