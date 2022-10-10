#include "game_chess_deck.h"

namespace chess {

	namespace deck {

		// заполненение поля пустыми клетками
		Deck& Deck::set_clear_deck() {

			if (deck_) {
				deck_.reset();
			}

			deck_ = std::make_unique<GameField>(8, 8);


			for (size_t x = 0; x < 8; ++x) {

				for (size_t y = 0; y < 8; ++y) {
					deck_.get()->field_[x][y] = std::make_shared<chess::resource::Empty>(x, y);
				}
			}

			IsEmpty = true;
			figures_id_ = 0;

			return *this;
		}

		Deck::~Deck() {
			if (deck_) {
				deck_.reset();
			}
		}

		Deck& Deck::set_gamefield(GameField&& field) {
			if (deck_) {
				deck_.reset();
			}

			deck_ = std::make_unique<GameField>(field);
			return *this;
		}

		// заполненение поля согласно стандартной расстановки
		Deck& Deck::set_default_figures() {
			if (IsEmpty) {
				this->set_white_figures();                  // установить на доску белые фигуры
				this->set_black_figures();                  // установить на доску черные фигуры
				IsEmpty = false;
			}
			else {
				std::cerr << "Deck is not Empty" << std::endl;
				assert(false);
			}
			
			return *this;
		}

		// установка белых фигур
		Deck& Deck::set_white_figures() {

			// устанавливаем пешки
			std::vector<std::shared_ptr<chess::resource::Figure>>& white_solder_line_ = deck_.get()->field_[6];

			for (size_t i = 0; i < 8; ++i) {
				white_solder_line_[i].reset();
				white_solder_line_[i] = std::move(std::make_shared<chess::resource::Solder>
					(figures_id_++, chess::resource::white, chess::geo::Coordinates(6, i)));
			}

			// устанавливаем основные фигуры
			std::vector<std::shared_ptr<chess::resource::Figure>>& white_figures_line_ = deck_.get()->field_[7];

			for (size_t i = 0; i < 8; ++i) {
				white_figures_line_[i].reset();
			}

			white_figures_line_[0] = std::move(std::make_shared<chess::resource::Tower>
				(figures_id_++, chess::resource::white, chess::geo::Coordinates(7, 0)));

			white_figures_line_[1] = std::move(std::make_shared<chess::resource::Horse>
				(figures_id_++, chess::resource::white, chess::geo::Coordinates(7, 1)));

			white_figures_line_[2] = std::move(std::make_shared<chess::resource::Officer>
				(figures_id_++, chess::resource::white, chess::geo::Coordinates(7, 2)));

			white_figures_line_[3] = std::move(std::make_shared<chess::resource::Queen>
				(figures_id_++, chess::resource::white, chess::geo::Coordinates(7, 3)));

			white_figures_line_[4] = std::move(std::make_shared<chess::resource::King>
				(figures_id_++, chess::resource::white, chess::geo::Coordinates(7, 4)));

			white_figures_line_[5] = std::move(std::make_shared<chess::resource::Officer>
				(figures_id_++, chess::resource::white, chess::geo::Coordinates(7, 5)));

			white_figures_line_[6] = std::move(std::make_shared<chess::resource::Horse>
				(figures_id_++, chess::resource::white, chess::geo::Coordinates(7, 6)));

			white_figures_line_[7] = std::move(std::make_shared<chess::resource::Tower>
				(figures_id_++, chess::resource::white, chess::geo::Coordinates(7, 7)));

			return *this;
		}

		// установка черных фигур
		Deck& Deck::set_black_figures() {

			// устанавливаем пешки
			std::vector<std::shared_ptr<chess::resource::Figure>>& black_solder_line_ = deck_.get()->field_[1];

			for (size_t i = 0; i < 8; ++i) {
				black_solder_line_[i].reset();
				black_solder_line_[i] = std::move(std::make_shared<chess::resource::Solder>
					(figures_id_++, chess::resource::black, chess::geo::Coordinates(1, i)));
			}

			// устанавливаем основные фигуры
			std::vector<std::shared_ptr<chess::resource::Figure>>& white_figures_line_ = deck_.get()->field_[0];

			for (size_t i = 0; i < 8; ++i) {
				white_figures_line_[i].reset();
			}

			white_figures_line_[0] = std::move(std::make_shared<chess::resource::Tower>
				(figures_id_++, chess::resource::black, chess::geo::Coordinates(0, 0)));

			white_figures_line_[1] = std::move(std::make_shared<chess::resource::Horse>
				(figures_id_++, chess::resource::black, chess::geo::Coordinates(0, 1)));

			white_figures_line_[2] = std::move(std::make_shared<chess::resource::Officer>
				(figures_id_++, chess::resource::black, chess::geo::Coordinates(0, 2)));

			white_figures_line_[3] = std::move(std::make_shared<chess::resource::Queen>
				(figures_id_++, chess::resource::black, chess::geo::Coordinates(0, 3)));

			white_figures_line_[4] = std::move(std::make_shared<chess::resource::King>
				(figures_id_++, chess::resource::black, chess::geo::Coordinates(0, 4)));

			white_figures_line_[5] = std::move(std::make_shared<chess::resource::Officer>
				(figures_id_++, chess::resource::black, chess::geo::Coordinates(0, 5)));

			white_figures_line_[6] = std::move(std::make_shared<chess::resource::Horse>
				(figures_id_++, chess::resource::black, chess::geo::Coordinates(0, 6)));

			white_figures_line_[7] = std::move(std::make_shared<chess::resource::Tower>
				(figures_id_++, chess::resource::black, chess::geo::Coordinates(0, 7)));

			return *this;
		}

	} // namespace deck

} // namespace chess