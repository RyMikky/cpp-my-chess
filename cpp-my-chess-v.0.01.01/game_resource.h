/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//  �������� ��� ���������� ��������� ��������� ��� ����                                       //
//  �� ������� ������ ���������� ����������� ����� ������ � ��� �������� ������                //
//                                                                                             //
//  TODO:                                                                                      //
//  1. �������� ����������� ������������ �����. �������������� ������� ������ ����������       //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once

#include "game_geo_libary.h"   // ��������� ��� ����������� ���������

#include <string>
#include <iostream> // ���������� ��������, ����� ���� ���-�� ���������� �������� render_figure()

namespace chess { // ������� ������� ���������

	namespace resource { // ��������� �������� ����

		using namespace chess::geo;

		enum FigureColor {
			grey = 0, white, black
		};

		enum FigureType {
			zero = 0, solder, tower, officer, horse, queen, king
		};

		// ������� ����������� ����� ������
		// ��������� ��������� ������ �������� �����
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

			virtual Figure& render_figure();                                // ����� �� ������
			virtual Figure& figure_declaration();                           // ���������� ������

			Figure& move_count_up();                                        // ��������� ���������� ����� �� �������
			Figure& move_count_up(const size_t&);                           // ��������� ���������� ����� �� "N"

			// ------------------------ ������ ������ ���������� ������ --------------------------------------------

			Figure& set_coordinates(double, double);                        // ������ ���������� ������
			Figure& set_in_game();                                          // ������ ������ ������ "� ����"
			Figure& set_out_game();                                         // ������ ������ ������ "��� ����"
			Figure& set_color(FigureColor);                                 // ������ ���� ������
			Figure& set_id(size_t);                                         // ������ id ������
			Figure& set_label(std::string);                                 // ������ ������ ������
			Figure& set_name(std::string);                                  // ������ �������� ������
			Figure& set_type(FigureType);                                   // ������ ��� ������

			// ------------------------ ������ ��������� ���������� ������ -----------------------------------------

			bool in_game() const;                                           // ���������� ������ � ��������� � ����
			size_t get_id() const;                                          // ���������� id ������
			size_t get_move_count() const;                                  // ���������� ��������� ����� ������
			FigureColor get_color() const;                                  // ���������� ���� ������
			Coordinates get_coordinates() const;                            // ���������� ���������� ������
			std::string get_label() const;                                  // ���������� ������ ������
			std::string get_name() const;                                   // ���������� �������� ������
			FigureType get_type() const;                                    // ���������� ��� ������
			virtual Figure& get_figure() const;                             // ���������� ������ �� ������
			virtual Figure* get_pointer() const;                            // ���������� ��������� �� ������

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

		// ������ ������
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

		// ������ ��������
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

		// ������ �����
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

		// ������ ����
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

		// ������ ����
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

		// ������ �����
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

		// ������ ������
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
