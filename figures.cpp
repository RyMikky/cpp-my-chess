#include "figures.h"

Figure::Figure() = default;

Figure::Figure(std::string label, std::string name, 
	FigureType type, FigureColor color, bool in_game) :
	label_(label), name_(name), type_(type), color_(color), in_game_(in_game) {
};

Figure::Figure(int figure_id, std::string label, std::string name, 
	FigureType type, FigureColor color, bool in_game) :
	figure_id_(figure_id), label_(label), name_(name), type_(type), color_(color), in_game_(in_game) {
};

//std::ostream& operator<<(std::ostream& output, const Figure& unit) {
//	output << unit.label_;
//	return output;
//}
