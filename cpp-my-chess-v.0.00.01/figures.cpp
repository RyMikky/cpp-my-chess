#include "figures.h"

BaseFigure::BaseFigure() = default;

BaseFigure::BaseFigure(std::string label, std::string name, 
	BaseFigureType type, BaseFigureColor color, bool in_game) :
	label_(label), name_(name), type_(type), color_(color), in_game_(in_game) {
};

BaseFigure::BaseFigure(int figure_id, std::string label, std::string name, 
	BaseFigureType type, BaseFigureColor color, bool in_game) :
	figure_id_(figure_id), label_(label), name_(name), type_(type), color_(color), in_game_(in_game) {
};

//std::ostream& operator<<(std::ostream& output, const Figure& unit) {
//	output << unit.label_;
//	return output;
//}


namespace chess {

	namespace resource {

		chess::resource::Figure& chess::resource::Figure::move_count_up() {
			move_count_++;
			return *this;
		}

		chess::resource::Figure& chess::resource::Figure::move_count_up(const size_t& count) {
			move_count_ += count;
			return *this;
		}

		chess::resource::Figure& chess::resource::Figure::set_in_game() {
			in_game_ = true;
			return *this;
		}

		chess::resource::Figure& chess::resource::Figure::set_out_game() {
			in_game_ = false;
			return *this;
		}

		chess::resource::Figure& chess::resource::Figure::set_color(FigureColor color) {
			color_ = std::move(color);
			return *this;
		}

		chess::resource::Figure& chess::resource::Figure::set_id(size_t id) {
			figure_id_ = std::move(id);
			return *this;
		}



		void chess::resource::King::render_figure(){
			if (color_ == FigureColor::white) {
				std::cerr << "Белый ";
			}
			else {
				std::cerr << "Черный ";
			}

			std::cerr << "Король | id: " << figure_id_;

			if (in_game_) {
				std::cerr << " | находится в игре";
			}

			std::cerr << std::endl;
		}

		void chess::resource::Solder::render_figure() {
			if (color_ == FigureColor::white) {
				std::cerr << "Белая ";
			}
			else {
				std::cerr << "Черная ";
			}

			std::cerr << "Пешка | id: " << figure_id_;

			if (in_game_) {
				std::cerr << " | находится в игре";
			}

			std::cerr << std::endl;
		}

		chess::resource::Solder& chess::resource::Solder::exchange_figure(FigureType type) {
			if (type == FigureType::king) {
				std::cerr << "Хочу превратиться в короля!" << std::endl;
			}
			return *this;
		}

	} // namespace resource

} // namespace chess_game
