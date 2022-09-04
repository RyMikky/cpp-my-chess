#pragma once
#include <string>
#include <iostream> //если отключить то почему-то вылетают ошибки

enum BaseFigureColor {
	grey = 0, white, black
};

enum BaseFigureType {
	zero = 0, solder, tower, officer, horse, queen, king
};

struct BaseFigure
{
	BaseFigure();

	BaseFigure(std::string label, std::string name, 
		BaseFigureType type, BaseFigureColor color, bool in_game);

	BaseFigure(int figure_id, std::string label, std::string name, 
		BaseFigureType type, BaseFigureColor color, bool in_game);
	
	int figure_id_ = 0;
	std::string label_ = ".";
	std::string name_ = "Пустая клетка";
	BaseFigureType type_ = BaseFigureType::zero;
	BaseFigureColor color_ = BaseFigureColor::grey;
	int move_count_ = 0;
	bool in_game_ = false;	
};

//std::ostream& operator<<(std::ostream& output, const Figure& unit);

namespace chess {

	namespace resource {

		enum FigureColor {
			grey = 0, white, black
		};

		enum FigureType {
			zero = 0, solder, tower, officer, horse, queen, king
		};

		// базовый класс Фигура
		// реализует интерфейс работы игрового юнита
		class Figure {
		public:
			Figure() = default;
			virtual ~Figure() = default;

			virtual void render_figure() = 0;

			// Увеличить количество шагов на единицу
			Figure& move_count_up();

			// Увеличить количество шагов на "N"
			Figure& move_count_up(const size_t&);

			// Задать статус фигуры "в игре"
			Figure& set_in_game();

			// Задать статус фигуры "вне игры"
			Figure& set_out_game();

			// Задать цвет фигруы
			Figure& set_color(FigureColor);

			// Задать id фигуры
			Figure& set_id(size_t);

			size_t figure_id_ = 0;
			size_t move_count_ = 0;
			FigureColor color_ = FigureColor::grey;
			bool in_game_ = false;
		};

		class King : public Figure {
		public:

			void render_figure() override;

		private:
			std::string label_ = "К";
			std::string name_ = "Король";
			FigureType type_ = FigureType::king;
		};


		class Solder : public Figure {
		public:

			void render_figure() override;

			Solder& exchange_figure(FigureType);

		private:
			std::string label_ = "П";
			std::string name_ = "Пешка";
			FigureType type_ = FigureType::solder;
		};

	} // namespace resource

} // namespace chess_game