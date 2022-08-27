#pragma once
#include "figures.h" // Структура фигур
#include "move_check.h" // Проверка ходов
#include "system_defines.h" // Общая библиотека макросов, перечислений и прочих дефайнов

// нужно для расскраски
#include <Windows.h>
//#include <io.h>
//#include <fcntl.h>
//#include <conio.h>
//#include <stdio.h>

#include <vector>
#include <string>
//#include <map>
#include <iostream>

class ChessDeck
{
public:
    ChessDeck() {
		DefaultClearDeck();
		WhiteFiguresAdd();
		BlackFiguresAdd();
	};

    ChessDeck(std::string param) {
        if (param == "тест" || param == "тестовая" || param == "тестовая доска") {
            DefaultClearDeck();
        }
        else {
            DefaultClearDeck();
            WhiteFiguresAdd();
            BlackFiguresAdd();
        }
    }

    explicit ChessDeck(GameStatus status);

	~ChessDeck() {
        std::cout << "\n\n           Спасибо за игру!" << std::endl;
	};

    Figure GetCurrentFigure(std::string label, int x, int y) {
        return deck_[x][y];
    };

    Figure GetCurrentPosition(const int& x, const int& y) {
        return deck_[x][y];
    };

    std::vector<std::vector<Figure>> GetDeck() {
        return deck_;
    }

    void DeckPrint();

    void FigureAdd(Figure unit, const int& x, const int& y);

    bool FigureMove(std::string label, FigureColor color, const int& x1, const int& y1, const int& x2, const int& y2);

private:
	void DefaultClearDeck();

	void BlackFiguresAdd();

	void WhiteFiguresAdd();

    bool EnemyPositionCheck(const Figure& unit, const int& x, const int& y) {
        return unit.color_ == ChessDeck::GetCurrentPosition(x, y).color_ ? false : true;
    }

    void FigureRemove(const int& x, const int& y) {
        deck_[x][y] = dummy_;
    }

    void FigureJump(Figure unit, const int& x, const int& y);

    void DefeatedFigureAdd(Figure unit);

	std::vector<std::vector<Figure>> ToMoveCheck() {
		return deck_;
	}

	std::vector<std::vector<Figure>> deck_ = {};

    Figure dummy_;

    std::vector<Figure> white_figures_;
    std::vector<Figure> black_figures_;

    std::vector<Figure> defeated_white_figures_;
    std::vector<Figure> defeated_black_figures_;

};

