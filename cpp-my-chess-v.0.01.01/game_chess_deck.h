#pragma once

#include <vector>
#include <variant>
#include <cassert>

#include "game_resource.h"

namespace chess {

	namespace deck {

		using Figures = std::variant<chess::resource::Figure, chess::resource::Empty, chess::resource::King, 
			chess::resource::Queen, chess::resource::Tower, chess::resource::Officer, chess::resource::Horse, chess::resource::Solder>;

		using FiguresPtr = Figures*;
		using FigurePtr = chess::resource::Figure*;

		struct FiguresPtrUnpack
		{
			chess::resource::Figure* operator()(const chess::resource::Figure& unit) {
				return unit.get_pointer();
			}

			chess::resource::Empty* operator()(const chess::resource::Empty& unit) {
				return unit.get_pointer();
			}

			chess::resource::King* operator()(const chess::resource::King& unit) {
				return unit.get_pointer();
			}

			chess::resource::Queen* operator()(const chess::resource::Queen& unit) {
				return unit.get_pointer();
			}

			chess::resource::Tower* operator()(const chess::resource::Tower& unit) {
				return unit.get_pointer();
			}

			chess::resource::Officer* operator()(const chess::resource::Officer& unit) {
				return unit.get_pointer();
			}

			chess::resource::Horse* operator()(const chess::resource::Horse& unit) {
				return unit.get_pointer();
			}

			chess::resource::Solder* operator()(const chess::resource::Solder& unit) {
				return unit.get_pointer();
			}
		};

		struct GameField {
			GameField(size_t x, size_t y) {

				field_.resize(x);

				for (size_t i = 0; i < x; ++i) {
					field_[i].resize(y);
				}
			}

			~GameField() {
				for (size_t x = 0; x < field_.size(); ++x) {
					
					for (size_t y = 0; y < field_[x].size(); ++y) {
						field_[x][y].reset();
					}
				}
			}

			std::vector<std::vector<std::shared_ptr<chess::resource::Figure>>> field_;
		};

		class Deck {
		public:
			Deck() = default;

			~Deck();

			// ------------------------ методы-сеттеры параметров игрового поля -------------------------------------------

			Deck& set_clear_deck();                                       // задать пустое игровое поле
			Deck& set_default_figures();                                  // задать игровое поле со страндартной расстановкой
			Deck& set_gamefield(GameField&&);                             // загрузить сконфигурированное игровое поле

			// ------------------------ методы-геттеры состояния игрового поля --------------------------------------------

			const GameField get_gamefield();                              // получить текущее игровое поле

		private:

			// ------------------------ флаги состояний игрового поля -----------------------------------------------------

			bool IsCheck = false;                                                            // состояние - шах
			bool IsMate = false;                                                             // состояние - мат
			bool IsSaved = false;                                                            // состояние - сохранено
			bool IsEmpty = false;                                                            // состояние - поле пусто

			size_t figures_id_ = 0;                                                          // счётчик id фигур
			std::unique_ptr<GameField> deck_ = nullptr;                                      // игровое поле

			std::vector<std::shared_ptr<chess::resource::Figure>> defeated_whites_;          // список поверженных белых фигур
			std::vector<std::shared_ptr<chess::resource::Figure>> defeated_blacks_;          // список поверженных черных фигур

			Deck& set_white_figures();                                    // установка белых фигур
			Deck& set_black_figures();                                    // установка черных фигур
			
		};

	} // namespace deck

} // namespace chess