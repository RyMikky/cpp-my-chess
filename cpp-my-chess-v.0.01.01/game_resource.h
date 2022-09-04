/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//  Документ для реализации требуемых элементов для игры                                       //
//  На текущий момент реализован абстрактный класс фигура и его дочерние классы                //
//                                                                                             //
//  TODO:                                                                                      //
//  1. Добавить полноценную визаулизацию фигур. Предварительно требует модуль рендеринга       //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once

#include "game_geo_libary.h"   // Требуется для подключения координат

#include <string>
#include <iostream> // Добавленно временно, чтобы хоть что-то выводилось фукциями render_figure()

namespace chess { // Базовый игровой неймспейс

	namespace resource { // Неймспейс ресурсов игры

		using namespace chess::geo;

		enum FigureColor {
			grey = 0, white, black
		};

		enum FigureType {
			zero = 0, solder, tower, officer, horse, queen, king
		};

		// Базовый абстрактный класс Фигура
		// Реализует интерфейс работы игрового юнита
		class Figure {
		public:
			Figure() = default;
			Figure(size_t id) : figure_id_(std::move(id)) {
			}

			Figure(size_t id, FigureColor color)
				: figure_id_(std::move(id))
				, color_(std::move(color)) {
			}

			virtual ~Figure() = default;

			virtual Figure& render_figure();                                // Вывод по фигуре
			virtual Figure& figure_declaration();                           // Объявление фигуры

			Figure& move_count_up();                                        // Увеличить количество шагов на единицу
			Figure& move_count_up(const size_t&);                           // Увеличить количество шагов на "N"

			// ------------------------ методы задачи параметров фигуры --------------------------------------------

			Figure& set_coordinates(double, double);                        // Задать координаты фигуры
			Figure& set_in_game();                                          // Задать статус фигуры "в игре"
			Figure& set_out_game();                                         // Задать статус фигуры "вне игры"
			Figure& set_color(FigureColor);                                 // Задать цвет фигруы
			Figure& set_id(size_t);                                         // Задать id фигуры
			Figure& set_label(std::string);                                 // Задать иконку фигуры
			Figure& set_name(std::string);                                  // Задать название фигуры
			Figure& set_type(FigureType);                                   // Задать тип фигуры

			// ------------------------ методы получения параметров фигуры -----------------------------------------

			bool in_game() const;                                           // Возвращает флажок о состоянии в игре
			size_t get_id() const;                                          // Возвращает id фигуры
			size_t get_move_count() const;                                  // Возвращает количство ходов фигуры
			FigureColor get_color() const;                                  // Возвращает цвет фигуры
			Coordinates get_coordinates() const;                            // Возвращает координаты фигуры
			std::string get_label() const;                                  // Возвращает иконку фигуры
			std::string get_name() const;                                   // Возвращает название фигуры
			FigureType get_type() const;                                    // Возвращает тип фигуры
			virtual Figure& get_figure() const;                             // Возвращает ссылку на фигуру
			virtual Figure* get_pointer() const;                            // Возвращает указатель на фигуру

		private:
			size_t figure_id_ = 0;
			size_t move_count_ = 0;
			std::string label_ = "";
			std::string name_ = "";
			FigureType type_ = FigureType::zero;
			FigureColor color_ = FigureColor::grey;
			Coordinates coord_ = { 0.0, 0.0 };
			bool in_game_ = false;
		};		

		// Фигура Король
		class King : public Figure {
		public:
			King() : Figure() {
				figure_declaration();
			}

			King(size_t id) : Figure(id) {
				figure_declaration();
			}

			King(size_t id, FigureColor color) : Figure(id, color) {
				figure_declaration();
			}

			King& render_figure() override;
			King& figure_declaration() override;

			King& get_figure() const override;
			King* get_pointer() const override;
		};

		// Фигура Королева
		class Queen : public Figure {
		public:
			Queen() : Figure() {
				figure_declaration();
			}

			Queen(size_t id) : Figure(id) {
				figure_declaration();
			}

			Queen(size_t id, FigureColor color) : Figure(id, color) {
				figure_declaration();
			}

			Queen& render_figure() override;
			Queen& figure_declaration() override;

			Queen& get_figure() const override;
			Queen* get_pointer() const override;
		};

		// Фигура Ладья
		class Tower : public Figure {
		public:
			Tower() : Figure() {
				figure_declaration();
			}

			Tower(size_t id) : Figure(id) {
				figure_declaration();
			}

			Tower(size_t id, FigureColor color) : Figure(id, color) {
				figure_declaration();
			}

			Tower& render_figure() override;
			Tower& figure_declaration() override;

			Tower& get_figure() const override;
			Tower* get_pointer() const override;
		};

		// Фигура Слон
		class Officer : public Figure {
		public:
			Officer() : Figure() {
				figure_declaration();
			}

			Officer(size_t id) : Figure(id) {
				figure_declaration();
			}

			Officer(size_t id, FigureColor color) : Figure(id, color) {
				figure_declaration();
			}

			Officer& render_figure() override;
			Officer& figure_declaration() override;

			Officer& get_figure() const override;
			Officer* get_pointer() const override;
		};

		// Фигура Конь
		class Horse : public Figure {
		public:
			Horse() : Figure() {
				figure_declaration();
			}

			Horse(size_t id) : Figure(id) {
				figure_declaration();
			}

			Horse(size_t id, FigureColor color) : Figure(id, color) {
				figure_declaration();
			}

			Horse& render_figure() override;
			Horse& figure_declaration() override;

			Horse& get_figure() const override;
			Horse* get_pointer() const override;
		};

		// Фигура Пешка
		class Solder : public Figure {
		public:
			Solder() : Figure() {
				figure_declaration();
			}

			Solder(size_t id) : Figure(id) {
				figure_declaration();
			}

			Solder(size_t id, FigureColor color) : Figure(id, color) {
				figure_declaration();
			}

			Solder(const Solder&) = default;
			Solder(Solder&&) = default;

			Solder& render_figure() override;
			Solder& figure_declaration() override;

			Solder& exchange_figure(FigureType);

			Solder& get_figure() const override;
			Solder* get_pointer() const override;

		};

		// Пустая фигура
		class Empty : public Figure {
		public:
			Empty() : Figure() {
				figure_declaration();
			}

			Empty(size_t id) : Figure(id) {
				figure_declaration();
			}

			Empty(size_t id, FigureColor color) : Figure(id, color) {
				figure_declaration();
			}

			Empty(double x, double y) : Figure() {
				set_coordinates(x, y).figure_declaration();
			}

			Empty& render_figure() override;
			Empty& figure_declaration() override;

			Empty& exchange_figure(FigureType);

			Empty& get_figure() const override;
			Empty* get_pointer() const override;

		};

	} // namespace resource

} // namespace chess
