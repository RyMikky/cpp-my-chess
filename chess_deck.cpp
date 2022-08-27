#include "chess_deck.h"

ChessDeck::ChessDeck(GameStatus status)
{
	DefaultClearDeck();
}

void ChessDeck::DeckPrint() {

	// �������������� �������
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



	// ������ ����� � �������
	{
		std::cout << "     ";
		for (char c = 'A'; c < 'I'; c++) {
			std::cout << " " << c << "  ";
		}
		std::cout << std::endl << std::endl;
	}

	// �������� ������ �����
	{
		int line = 8;
		for (const auto& line_ : deck_) {
			std::cout << "  " << line << "  ";
			for (const auto& point_ : line_) {
				if (point_.color_ == FigureColor::black) {
					std::cout << "[";
					//SetConsoleTextAttribute(hConsole, red_text);
					// ������� ��������� ����
					//SetConsoleTextAttribute(hConsole, (WORD)((yellow_text << 4) | red_text));

					SetConsoleTextAttribute(hConsole, red_text);
					std::cout << point_.label_; 
					// ������� ��������� ����
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

	// ������ ������� � �������
	{
		std::cout << " " << " " << " " << " " << " ";
		for (char c = 'A'; c < 'I'; c++) {
			std::cout << " " << c << " " << " ";
		}
		std::cout << std::endl << std::endl;
	}
	SetConsoleTextAttribute(hConsole, white_text);
}

// ���������� ������ �� �����������
void ChessDeck::FigureAdd(Figure unit, const int& x, const int& y) {
	deck_[x][y] = unit;
}

// ��� �������
bool ChessDeck::FigureMove(std::string label, FigureColor color,
	const int& x1, const int& y1, const int& x2, const int& y2) {

	// �������� ������ �� ��������� �����������
	Figure figure = ChessDeck::GetCurrentFigure(label, x1, y1);

	// ���� �������� �� try/catch
	if (figure.label_ == label && figure.color_ == color) {
		std::cout << "������� ������ \"" << figure.name_ << "\" "
			<< "������������� �� " << x1 + 1 << ":" << y1 + 1 << std::endl << std::endl;
	}
	else {
		std::cout << "���-�� ����� �� ���...(\n\n";
	}

	// ��� � ����������� �� ���� ������
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
			std::cout << "����� ���, ���, ����������!\n\n";
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
			std::cout << "����� ���, ���, ����������!\n\n";
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
			std::cout << "����� ���, ���, ����������!\n\n";
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
			std::cout << "����� ���, ���, ����������!\n\n";
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
			std::cout << "����� ���, ���, ����������!\n\n";
			return false;
		};
		break;
	}
	case solder: {
		if (SolderMoveCheck(deck_, color, x1, y1, x2, y2)) { // �������� ����������� ����
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
			std::cout << "����� ���, ���, ����������!\n\n";
			return false;
		};
		break;
	}
	default:
		return false;
		break;
	}
}

//������ ������ ����� ��� �����
void ChessDeck::DefaultClearDeck() {
	deck_.reserve(8);
	for (int c = 0; c < 8; c++) {
		std::vector<Figure> line_(8, Figure());
		deck_.push_back(line_);
	}
}

// ��������� ����� ������� ��������
void ChessDeck::BlackFiguresAdd() {
	// ��������� ������ � ��������
	Figure black_king(1, "�", "������", FigureType::king, FigureColor::black, true);
	Figure black_queen(2, "�", "�����", FigureType::queen, FigureColor::black, true);
	deck_[0].at(4) = black_king;
	deck_[0].at(3) = black_queen;
	black_figures_.push_back(black_king);
	black_figures_.push_back(black_queen);

	// ��������� �����
	Figure black_tower_l(3, "�", "�����", FigureType::tower, FigureColor::black, true);
	Figure black_tower_r(4, "�", "�����", FigureType::tower, FigureColor::black, true);
	deck_[0].at(0) = black_tower_l;
	deck_[0].at(7) = black_tower_r;
	black_figures_.push_back(black_tower_l);
	black_figures_.push_back(black_tower_r);

	// ��������� ������
	Figure black_officer_l(5, "�", "����", FigureType::officer, FigureColor::black, true);
	Figure black_officer_r(6, "�", "����", FigureType::officer, FigureColor::black, true);
	deck_[0].at(2) = black_officer_l;
	deck_[0].at(5) = black_officer_r;
	black_figures_.push_back(black_officer_l);
	black_figures_.push_back(black_officer_r);

	// ��������� �����
	Figure black_horse_l(7, "�", "����", FigureType::horse, FigureColor::black, true);
	Figure black_horse_r(8, "�", "����", FigureType::horse, FigureColor::black, true);

	deck_[0].at(1) = black_horse_l;
	deck_[0].at(6) = black_horse_r;

	black_figures_.push_back(black_horse_l);
	black_figures_.push_back(black_horse_r);

	// ��������� �����
	std::vector<Figure> black_solder_line_ = {};
	for (int i = 9; i < 17; i++) {
		Figure black_solder(i, "�", "�����", FigureType::solder, FigureColor::black, true);
		black_solder_line_.push_back(black_solder);
		black_figures_.push_back(black_solder);
	}
	std::swap(deck_[1], black_solder_line_);
}

// ��������� ����� ������ ��������
void ChessDeck::WhiteFiguresAdd() {
	// ��������� ������ � ��������
	Figure white_king(1, "�", "������", FigureType::king, FigureColor::white, true);
	Figure white_queen(2, "�", "�����", FigureType::queen, FigureColor::white, true);
	deck_[7].at(4) = white_king;
	deck_[7].at(3) = white_queen;
	white_figures_.push_back(white_king);
	white_figures_.push_back(white_queen);

	// ��������� �����
	Figure white_tower_l(3, "�", "�����", FigureType::tower, FigureColor::white, true);
	Figure white_tower_r(4, "�", "�����", FigureType::tower, FigureColor::white, true);
	deck_[7].at(0) = white_tower_l;
	deck_[7].at(7) = white_tower_r;
	white_figures_.push_back(white_tower_l);
	white_figures_.push_back(white_tower_r);

	// ��������� ������
	Figure white_officer_l(5, "�", "����", FigureType::officer, FigureColor::white, true);
	Figure white_officer_r(6, "�", "����", FigureType::officer, FigureColor::white, true);
	deck_[7].at(2) = white_officer_l;
	deck_[7].at(5) = white_officer_r;
	white_figures_.push_back(white_officer_l);
	white_figures_.push_back(white_officer_r);

	// ��������� �����
	Figure white_horse_l(7, "�", "����", FigureType::horse, FigureColor::white, true);
	Figure white_horse_r(8, "�", "����", FigureType::horse, FigureColor::white, true);
	deck_[7].at(1) = white_horse_l;
	deck_[7].at(6) = white_horse_r;
	white_figures_.push_back(white_horse_l);
	white_figures_.push_back(white_horse_r);
	
	// ��������� �����
	std::vector<Figure> white_solder_line_ = {};
	for (int i = 9; i < 17; i++) {
		Figure white_solder(i, "�", "�����", FigureType::solder, FigureColor::white, true);
		white_solder_line_.push_back(white_solder);
		white_figures_.push_back(white_solder);
	}
	std::swap(deck_[6], white_solder_line_);
}

// ������� ������� �������
// ����������� ����� ������� FigereMove()
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

// ���������� ������ � ������ �����������
// ����������� ����� ������� FigureMove()
void ChessDeck::DefeatedFigureAdd(Figure unit) {
	if (unit.color_ == FigureColor::grey) {
		std::cout << "���������� �������� � ����������� \"������\" ������" << std::endl;
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