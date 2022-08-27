#include "chess_deck.h"

ChessDeck::ChessDeck(GameStatus status)
{
	DefaultClearDeck();
}

void ChessDeck::DeckPrint() {

	// цветокоррекция консоли
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//hConsole = GetStdHandle(BACKGROUND_GREEN);

	enum ConsoleColor {
		black_text = 0,
		blue_text = 1,
		green_text = 2,
		l_blue_text = 3,
		red_text = 4,
		purple_text = 5,
		yellow_text = 6,
		white_text = 7,
		grey_text = 8,
		d_blue_text = 9,
		l_green_text = 10
	};

	SetConsoleTextAttribute(hConsole, yellow_text);



	// Печать шапки с буквами
	{
		std::cout << "     ";
		for (char c = 'A'; c < 'I'; c++) {
			std::cout << " " << c << "  ";
		}
		std::cout << std::endl << std::endl;
	}

	// Основаня печать доски
	{
		int line = 8;
		for (const auto& line_ : deck_) {
			std::cout << "  " << line << "  ";
			for (const auto& point_ : line_) {
				if (point_.color_ == FigureColor::black) {
					std::cout << "[";
					//SetConsoleTextAttribute(hConsole, red_text);
					// попытка закрасить поле
					//SetConsoleTextAttribute(hConsole, (WORD)((yellow_text << 4) | red_text));

					SetConsoleTextAttribute(hConsole, red_text);
					std::cout << point_.label_; 
					// попытка закрасить поле
					//SetConsoleTextAttribute(hConsole, (WORD)((black_text << 4) | yellow_text));
					SetConsoleTextAttribute(hConsole, yellow_text);
					std::cout << "]" << " ";
				}
				else if (point_.color_ == FigureColor::white) {
					std::cout << "[";
					SetConsoleTextAttribute(hConsole, white_text);
					std::cout << point_.label_;
					SetConsoleTextAttribute(hConsole, yellow_text);
					std::cout << "]" << " ";
				}
				else {
					std::cout << "[";
					SetConsoleTextAttribute(hConsole, grey_text);
					std::cout << point_.label_;
					SetConsoleTextAttribute(hConsole, yellow_text);
					std::cout << "]" << " ";
				}
			}
			std::cout << " " << line-- << std::endl << std::endl;
		}
	}

	// Печать подвала с буквами
	{
		std::cout << " " << " " << " " << " " << " ";
		for (char c = 'A'; c < 'I'; c++) {
			std::cout << " " << c << " " << " ";
		}
		std::cout << std::endl << std::endl;
	}
	SetConsoleTextAttribute(hConsole, white_text);
}

// добавление фигуры по координатам
void ChessDeck::FigureAdd(Figure unit, const int& x, const int& y) {
	deck_[x][y] = unit;
}

// ход фигурой
bool ChessDeck::FigureMove(std::string label, FigureColor color,
	const int& x1, const int& y1, const int& x2, const int& y2) {

	// получаем фигуру по начальным координатам
	Figure figure = ChessDeck::GetCurrentFigure(label, x1, y1);

	// надо заменить на try/catch
	if (figure.label_ == label && figure.color_ == color) {
		std::cout << "Выбрана фигура \"" << figure.name_ << "\" "
			<< "Расположенная на " << x1 + 1 << ":" << y1 + 1 << std::endl << std::endl;
	}
	else {
		std::cout << "Что-то пошло не так...(\n\n";
	}

	// ход в зависимости от типа фигуры
	switch (figure.type_)
	{
	case king: {
		if (KingMoveCheck(deck_, x1, y1, x2, y2)) {
			if (ChessDeck::EnemyPositionCheck(figure, x2, y2)) {
				ChessDeck::DefeatedFigureAdd(ChessDeck::GetCurrentPosition(x2, y2));
			}

			/*if (GetCurrentPosition(x2, y2).color_ != FigureColor::grey
				&& GetCurrentPosition(x2, y2).color_ != color) {
				DefeatedFigureAdd(GetCurrentPosition(x2, y2));
			}*/

			figure.move_count_++;
			ChessDeck::FigureRemove(x1, y1);
			ChessDeck::FigureJump(figure, x2, y2);
			return true;
		}
		else {
			std::cout << "Такой ход, увы, невозможен!\n\n";
			return false;
		};
		break;
	}
	case queen: {
		if (QueenMoveCheck(deck_, x1, y1, x2, y2)) {
			if (ChessDeck::EnemyPositionCheck(figure, x2, y2)) {
				ChessDeck::DefeatedFigureAdd(ChessDeck::GetCurrentPosition(x2, y2));
			}
			/*if (GetCurrentPosition(x2, y2).color_ != FigureColor::grey
				&& GetCurrentPosition(x2, y2).color_ != color) {
				DefeatedFigureAdd(GetCurrentPosition(x2, y2));
			}*/

			figure.move_count_++;
			ChessDeck::FigureRemove(x1, y1);
			ChessDeck::FigureJump(figure, x2, y2);
			return true;
		}
		else {
			std::cout << "Такой ход, увы, невозможен!\n\n";
			return false;
		};
		break;
	}
	case tower: {
		if (TowerMoveCheck(deck_, x1, y1, x2, y2)) {
			if (ChessDeck::EnemyPositionCheck(figure, x2, y2)) {
				ChessDeck::DefeatedFigureAdd(ChessDeck::GetCurrentPosition(x2, y2));
			}
			/*if (GetCurrentPosition(x2, y2).color_ != FigureColor::grey
				&& GetCurrentPosition(x2, y2).color_ != color) {
				DefeatedFigureAdd(GetCurrentPosition(x2, y2));
			}*/

			figure.move_count_++;
			ChessDeck::FigureRemove(x1, y1);
			ChessDeck::FigureJump(figure, x2, y2);
			return true;
		}
		else {
			std::cout << "Такой ход, увы, невозможен!\n\n";
			return false;
		};
		break;
	}
	case officer: {
		if (OfficerMoveCheck(deck_, x1, y1, x2, y2)) {
			if (ChessDeck::EnemyPositionCheck(figure, x2, y2)) {
				ChessDeck::DefeatedFigureAdd(ChessDeck::GetCurrentPosition(x2, y2));
			}
			/*if (GetCurrentPosition(x2, y2).color_ != FigureColor::grey
				&& GetCurrentPosition(x2, y2).color_ != color) {
				DefeatedFigureAdd(GetCurrentPosition(x2, y2));
			}*/

			figure.move_count_++;
			ChessDeck::FigureRemove(x1, y1);
			ChessDeck::FigureJump(figure, x2, y2);
			return true;
		}
		else {
			std::cout << "Такой ход, увы, невозможен!\n\n";
			return false;
		};
		break;
	}
	case horse: {
		if (HorseMoveCheck(deck_, x1, y1, x2, y2)) {
			if (ChessDeck::EnemyPositionCheck(figure, x2, y2)) {
				ChessDeck::DefeatedFigureAdd(ChessDeck::GetCurrentPosition(x2, y2));
			}
			/*if (GetCurrentPosition(x2, y2).color_ != FigureColor::grey
				&& GetCurrentPosition(x2, y2).color_ != color) {
				DefeatedFigureAdd(GetCurrentPosition(x2, y2));
			}*/

			figure.move_count_++;
			ChessDeck::FigureRemove(x1, y1);
			ChessDeck::FigureJump(figure, x2, y2);
			return true;
		}
		else {
			std::cout << "Такой ход, увы, невозможен!\n\n";
			return false;
		};
		break;
	}
	case solder: {
		if (SolderMoveCheck(deck_, color, x1, y1, x2, y2)) { // Проверка возможности хода
			if (ChessDeck::EnemyPositionCheck(figure, x2, y2)) {
				ChessDeck::DefeatedFigureAdd(ChessDeck::GetCurrentPosition(x2, y2));
			}
			/*if (GetCurrentPosition(x2, y2).color_ != FigureColor::grey
				&& GetCurrentPosition(x2, y2).color_ != color) {
				DefeatedFigureAdd(GetCurrentPosition(x2, y2));
			}*/

			figure.move_count_++;
			ChessDeck::FigureRemove(x1, y1);
			ChessDeck::FigureJump(figure, x2, y2);

			return true;
		}
		else {
			std::cout << "Такой ход, увы, невозможен!\n\n";
			return false;
		};
		break;
	}
	default:
		return false;
		break;
	}
}

//создаём пустую доску без фигур
void ChessDeck::DefaultClearDeck() {
	deck_.reserve(8);
	for (int c = 0; c < 8; c++) {
		std::vector<Figure> line_(8, Figure());
		deck_.push_back(line_);
	}
}

// заполняем доску черными фигурами
void ChessDeck::BlackFiguresAdd() {
	// Добавляем Короля и Королеву
	Figure black_king(1, "К", "Король", FigureType::king, FigureColor::black, true);
	Figure black_queen(2, "Ш", "Ферзь", FigureType::queen, FigureColor::black, true);
	deck_[0].at(4) = black_king;
	deck_[0].at(3) = black_queen;
	black_figures_.push_back(black_king);
	black_figures_.push_back(black_queen);

	// Добавляем Ладьи
	Figure black_tower_l(3, "Л", "Ладья", FigureType::tower, FigureColor::black, true);
	Figure black_tower_r(4, "Л", "Ладья", FigureType::tower, FigureColor::black, true);
	deck_[0].at(0) = black_tower_l;
	deck_[0].at(7) = black_tower_r;
	black_figures_.push_back(black_tower_l);
	black_figures_.push_back(black_tower_r);

	// Добавляем Слонов
	Figure black_officer_l(5, "С", "Слон", FigureType::officer, FigureColor::black, true);
	Figure black_officer_r(6, "С", "Слон", FigureType::officer, FigureColor::black, true);
	deck_[0].at(2) = black_officer_l;
	deck_[0].at(5) = black_officer_r;
	black_figures_.push_back(black_officer_l);
	black_figures_.push_back(black_officer_r);

	// Добавляем Коней
	Figure black_horse_l(7, "Г", "Конь", FigureType::horse, FigureColor::black, true);
	Figure black_horse_r(8, "Г", "Конь", FigureType::horse, FigureColor::black, true);

	deck_[0].at(1) = black_horse_l;
	deck_[0].at(6) = black_horse_r;

	black_figures_.push_back(black_horse_l);
	black_figures_.push_back(black_horse_r);

	// Добавляем Пешки
	std::vector<Figure> black_solder_line_ = {};
	for (int i = 9; i < 17; i++) {
		Figure black_solder(i, "П", "Пешка", FigureType::solder, FigureColor::black, true);
		black_solder_line_.push_back(black_solder);
		black_figures_.push_back(black_solder);
	}
	std::swap(deck_[1], black_solder_line_);
}

// заполняем доску белыми фигурами
void ChessDeck::WhiteFiguresAdd() {
	// Добавляем Короля и Королеву
	Figure white_king(1, "К", "Король", FigureType::king, FigureColor::white, true);
	Figure white_queen(2, "Ш", "Ферзь", FigureType::queen, FigureColor::white, true);
	deck_[7].at(4) = white_king;
	deck_[7].at(3) = white_queen;
	white_figures_.push_back(white_king);
	white_figures_.push_back(white_queen);

	// Добавляем Ладьи
	Figure white_tower_l(3, "Л", "Ладья", FigureType::tower, FigureColor::white, true);
	Figure white_tower_r(4, "Л", "Ладья", FigureType::tower, FigureColor::white, true);
	deck_[7].at(0) = white_tower_l;
	deck_[7].at(7) = white_tower_r;
	white_figures_.push_back(white_tower_l);
	white_figures_.push_back(white_tower_r);

	// Добавляем Слонов
	Figure white_officer_l(5, "С", "Слон", FigureType::officer, FigureColor::white, true);
	Figure white_officer_r(6, "С", "Слон", FigureType::officer, FigureColor::white, true);
	deck_[7].at(2) = white_officer_l;
	deck_[7].at(5) = white_officer_r;
	white_figures_.push_back(white_officer_l);
	white_figures_.push_back(white_officer_r);

	// Добавляем Коней
	Figure white_horse_l(7, "Г", "Конь", FigureType::horse, FigureColor::white, true);
	Figure white_horse_r(8, "Г", "Конь", FigureType::horse, FigureColor::white, true);
	deck_[7].at(1) = white_horse_l;
	deck_[7].at(6) = white_horse_r;
	white_figures_.push_back(white_horse_l);
	white_figures_.push_back(white_horse_r);
	
	// Добавляем пешки
	std::vector<Figure> white_solder_line_ = {};
	for (int i = 9; i < 17; i++) {
		Figure white_solder(i, "П", "Пешка", FigureType::solder, FigureColor::white, true);
		white_solder_line_.push_back(white_solder);
		white_figures_.push_back(white_solder);
	}
	std::swap(deck_[6], white_solder_line_);
}

// занятие позиции фигурой
// завершающая часть функции FigereMove()
void ChessDeck::FigureJump(Figure unit, const int& x, const int& y) {
	deck_[x][y] = unit;

	if (unit.color_ == FigureColor::white) {
		white_figures_[unit.figure_id_ - 1] = unit;
	}
	else if (unit.color_ == FigureColor::black) {
		black_figures_[unit.figure_id_ - 1] = unit;
	}
	else {
		return;
	}
}

// добавление фигуры в список побежденных
// завершающая часть функции FigureMove()
void ChessDeck::DefeatedFigureAdd(Figure unit) {
	if (unit.color_ == FigureColor::grey) {
		std::cout << "Невозможно добавить в побежденные \"пустую\" клетку" << std::endl;
	}
	else {
		unit.in_game_ = false;
		if (unit.color_ == FigureColor::white) {
			white_figures_[unit.figure_id_ - 1] = unit;
			defeated_white_figures_.push_back(unit);
		}
		else {
			black_figures_[unit.figure_id_ - 1] = unit;
			defeated_black_figures_.push_back(unit);
		}
	}
}