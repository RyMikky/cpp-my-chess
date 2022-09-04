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

    BaseFigure GetCurrentFigure(std::string label, int x, int y) {
        return deck_[x][y];
    };

    BaseFigure GetCurrentPosition(const int& x, const int& y) {
        return deck_[x][y];
    };

    std::vector<std::vector<BaseFigure>> GetDeck() {
        return deck_;
    }

    void DeckPrint();

    void FigureAdd(BaseFigure unit, const int& x, const int& y);

    bool FigureMove(std::string label, BaseFigureColor color, const int& x1, const int& y1, const int& x2, const int& y2);

private:
	void DefaultClearDeck();

	void BlackFiguresAdd();

	void WhiteFiguresAdd();

    bool EnemyPositionCheck(const BaseFigure& unit, const int& x, const int& y) {
        return unit.color_ == ChessDeck::GetCurrentPosition(x, y).color_ ? false : true;
    }

    void FigureRemove(const int& x, const int& y) {
        deck_[x][y] = dummy_;
    }

    void FigureJump(BaseFigure unit, const int& x, const int& y);

    void DefeatedFigureAdd(BaseFigure unit);

	std::vector<std::vector<BaseFigure>> ToMoveCheck() {
		return deck_;
	}

	std::vector<std::vector<BaseFigure>> deck_ = {};

    BaseFigure dummy_;

    std::vector<BaseFigure> white_figures_;
    std::vector<BaseFigure> black_figures_;

    std::vector<BaseFigure> defeated_white_figures_;
    std::vector<BaseFigure> defeated_black_figures_;

};

