#include "game_resource.h"

namespace chess {

	namespace resource {

		using namespace chess::resource;
		using namespace chess::geo;


		Figure& Figure::render_figure() {
			std::cerr << "бла-бла-бла" << std::endl;
			return *this;
		}

		Figure& Figure::figure_declaration() {
			this->set_label(".").set_name("Пусто").set_type(zero);
			return *this;
		}

		Figure& Figure::move_count_up() {
			move_count_++;
			return *this;
		}

		Figure& Figure::move_count_up(const size_t& count) {
			move_count_ += count;
			return *this;
		}

		Figure& Figure::set_coordinates(double x, double y) {
			coord_.x_ = std::move(x);
			coord_.y_ = std::move(y);
			return *this;
		}

		Figure& Figure::set_in_game() {
			in_game_ = true;
			return *this;
		}

		Figure& Figure::set_out_game() {
			in_game_ = false;
			return *this;
		}

		Figure& Figure::set_color(FigureColor color) {
			color_ = std::move(color);
			return *this;
		}

		Figure& Figure::set_id(size_t id) {
			figure_id_ = std::move(id);
			return *this;
		}

		Figure& Figure::set_label(std::string label) {
			label_ = std::move(label);
			return *this;
		}

		Figure& Figure::set_name(std::string name) {
			name_ = std::move(name);
			return *this;
		}

		Figure& Figure::set_type(FigureType type) {
			type_ = std::move(type);
			return *this;
		}

		bool Figure::in_game() const {
			return in_game_;
		}

		size_t Figure::get_id() const {
			return figure_id_;
		}

		size_t Figure::get_move_count() const {
			return move_count_;
		}

		FigureColor Figure::get_color() const {
			return color_;
		}

		Coordinates Figure::get_coordinates() const {
			return coord_;
		}

		std::string Figure::get_label() const {
			return label_;
		}

		std::string Figure::get_name() const {
			return name_;
		}

		FigureType Figure::get_type() const {
			return type_;
		}

		Figure& Figure::get_figure() const {
			return const_cast<Figure&>(*this) ;
		}

		Figure* Figure::get_pointer() const {
			return const_cast<Figure*>(this);
		}


		// -------------------------- class King ---------------------------------------
		
		King& King::render_figure() {
			if (this->get_color() == FigureColor::white) {
				std::cerr << "Белый ";
			}
			else {
				std::cerr << "Черный ";
			}

			std::cerr << "Король | id: " << this->get_id();

			if (this->in_game()) {
				std::cerr << " | находится в игре";
				std::cerr << " | по координатам {" << this->get_coordinates().x_ << ", " << this->get_coordinates().y_ << "}";
			}

			std::cerr << std::endl;
			return *this;
		}

		King& King::figure_declaration() {
			this->set_label("К").set_name("Король").set_type(king);
			return *this;
		}

		King& King::get_figure() const {
			return const_cast<King&>(*this);
		}

		King* King::get_pointer() const {
			return const_cast<King*>(this);
		}

		// -------------------------- class King END -----------------------------------


		// -------------------------- class Queen --------------------------------------

		Queen& Queen::render_figure() {
			if (this->get_color() == FigureColor::white) {
				std::cerr << "Белая ";
			}
			else {
				std::cerr << "Черная ";
			}

			std::cerr << "Королева | id: " << this->get_id();

			if (this->in_game()) {
				std::cerr << " | находится в игре";
				std::cerr << " | по координатам {" << this->get_coordinates().x_ << ", " << this->get_coordinates().y_ << "}";
			}

			std::cerr << std::endl;
			return *this;
		}

		Queen& Queen::figure_declaration() {
			this->set_label("Ш").set_name("Королева").set_type(queen);
			return *this;
		}

		Queen& Queen::get_figure() const {
			return const_cast<Queen&>(*this);
		}

		Queen* Queen::get_pointer() const {
			return const_cast<Queen*>(this);
		}

		// -------------------------- class Queen END ----------------------------------


		// -------------------------- class Tower --------------------------------------

		Tower& Tower::render_figure() {
			if (this->get_color() == FigureColor::white) {
				std::cerr << "Белая ";
			}
			else {
				std::cerr << "Черная ";
			}

			std::cerr << "Ладья | id: " << this->get_id();

			if (this->in_game()) {
				std::cerr << " | находится в игре";
				std::cerr << " | по координатам {" << this->get_coordinates().x_ << ", " << this->get_coordinates().y_ << "}";
			}

			std::cerr << std::endl;
			return *this;
		}

		Tower& Tower::figure_declaration() {
			this->set_label("Т").set_name("Ладья").set_type(tower);
			return *this;
		}

		Tower& Tower::get_figure() const {
			return const_cast<Tower&>(*this);
		}

		Tower* Tower::get_pointer() const {
			return const_cast<Tower*>(this);
		}

		// -------------------------- class Tower END ----------------------------------


		// -------------------------- class Officer ------------------------------------

		Officer& Officer::render_figure() {
			if (this->get_color() == FigureColor::white) {
				std::cerr << "Белый ";
			}
			else {
				std::cerr << "Черный ";
			}

			std::cerr << "Слон | id: " << this->get_id();

			if (this->in_game()) {
				std::cerr << " | находится в игре";
				std::cerr << " | по координатам {" << this->get_coordinates().x_ << ", " << this->get_coordinates().y_ << "}";
			}

			std::cerr << std::endl;
			return *this;
		}

		Officer& Officer::figure_declaration() {
			this->set_label("С").set_name("Слон").set_type(officer);
			return *this;
		}

		Officer& Officer::get_figure() const {
			return const_cast<Officer&>(*this);
		}

		Officer* Officer::get_pointer() const {
			return const_cast<Officer*>(this);
		}

		// -------------------------- class Officer END --------------------------------


		// -------------------------- class Horse --------------------------------------

		Horse& Horse::render_figure() {
			if (this->get_color() == FigureColor::white) {
				std::cerr << "Белый ";
			}
			else {
				std::cerr << "Черный ";
			}

			std::cerr << "Конь | id: " << this->get_id();

			if (this->in_game()) {
				std::cerr << " | находится в игре";
				std::cerr << " | по координатам {" << this->get_coordinates().x_ << ", " << this->get_coordinates().y_ << "}";
			}

			std::cerr << std::endl;
			return *this;
		}

		Horse& Horse::figure_declaration() {
			this->set_label("Г").set_name("Конь").set_type(horse);
			return *this;
		}

		Horse& Horse::get_figure() const {
			return const_cast<Horse&>(*this);
		}

		Horse* Horse::get_pointer() const {
			return const_cast<Horse*>(this);
		}

		// -------------------------- class Horse END ------------------------------


		// -------------------------- class Solder -------------------------------------
		
		Solder& Solder::render_figure() {
			if (this->get_color() == FigureColor::white) {
				std::cerr << "Белая ";
			}
			else {
				std::cerr << "Черная ";
			}

			std::cerr << "Пешка | id: " << this->get_id();

			if (this->in_game()) {
				std::cerr << " | находится в игре";
				std::cerr << " | по координатам {" << this->get_coordinates().x_ << ", " << this->get_coordinates().y_ << "}";
			}

			std::cerr << std::endl;
			return *this;
		}

		Solder& Solder::figure_declaration() {
			this->set_label("П").set_name("Пешка").set_type(solder);
			return *this;
		}

		Solder& Solder::exchange_figure(FigureType type) {
			if (type == FigureType::king) {
				std::cerr << "Хочет превратиться в короля!" << std::endl;
			} 
			else if (type == FigureType::queen) {
				std::cerr << "Хочет стать королевой!" << std::endl;
			}
			return *this;
		}

		Solder& Solder::get_figure() const {
			return const_cast<Solder&>(*this);
		}

		Solder* Solder::get_pointer() const {
			return const_cast<Solder*>(this);
		}

		// -------------------------- class Solder END ---------------------------------


		// -------------------------- class Empty --------------------------------------

		Empty& Empty::render_figure() {
			if (this->get_color() == FigureColor::white) {
				std::cerr << "Белая ";
			}
			else {
				std::cerr << "Черная ";
			}

			std::cerr << "Пешка | id: " << this->get_id();

			if (this->in_game()) {
				std::cerr << " | находится в игре";
				std::cerr << " | по координатам {" << this->get_coordinates().x_ << ", " << this->get_coordinates().y_ << "}";
			}

			std::cerr << std::endl;
			return *this;
		}

		Empty& Empty::figure_declaration() {
			this->set_label(".").set_name("Пусто");
			return *this;
		}

		Empty& Empty::exchange_figure(FigureType type) {
			if (type == FigureType::king) {
				std::cerr << "Хочу превратиться в короля!" << std::endl;
			}
			return *this;
		}

		Empty& Empty::get_figure() const {
			return const_cast<Empty&>(*this);
		}

		Empty* Empty::get_pointer() const {
			return const_cast<Empty*>(this);
		}

		// -------------------------- class Empty END ----------------------------------
		

	} // namespace resource

} // namespace chess