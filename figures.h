#pragma once
#include <string>
#include <iostream> //если отключить то почему-то вылетают ошибки

enum FigureColor {
	grey = 0, white, black
};

enum FigureType {
	zero = 0, solder, tower, officer, horse, queen, king
};

struct Figure
{
	Figure();

	Figure(std::string label, std::string name, 
		FigureType type, FigureColor color, bool in_game);

	Figure(int figure_id, std::string label, std::string name, 
		FigureType type, FigureColor color, bool in_game);
	
	int figure_id_ = 0;
	std::string label_ = ".";
	std::string name_ = "Пустая клетка";
	FigureType type_ = FigureType::zero;
	FigureColor color_ = FigureColor::grey;
	int move_count_ = 0;
	bool in_game_ = false;	
};

//std::ostream& operator<<(std::ostream& output, const Figure& unit);