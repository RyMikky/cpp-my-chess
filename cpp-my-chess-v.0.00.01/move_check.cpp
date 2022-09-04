#include "move_check.h"

// �������� ������������� ����
bool DialineColision(std::vector<std::vector<BaseFigure>>& deck,
	const int& x1, const int& y1, const int& x2, const int& y2) {
	// ������� ��������� �� ��������� �� �� ����
	// ������� �������� �� ������� ������� � �������� ������ ����
	if (x2 < x1 && y2 < y1) { // � ������ �������� - x2 �����������, y2 �����������
		for (int x = x1 - 1, y = y1 - 1; x >= x2/*, y >= y2*/; x--, y--) {
			if (x == x2 && y == y2) {
				if (deck[x][y].color_ == BaseFigureColor::grey || deck[x][y].color_ != deck[x1][y1].color_) {
					return true;
				}
				return false;
			}
			else {
				if (deck[x][y].color_ != BaseFigureColor::grey || deck[x][y].color_ == deck[x1][y1].color_) {
					return false;
				}
			}
		}
		return true;
	}
	else if (x2 < x1 && y2 > y1) { // �� ������ �������� - x2 �����������, y2 �������������
		for (int x = x1 - 1, y = y1 + 1; x >= x2/*, y <= y2*/; x--, y++) {
			if (x == x2 && y == y2) {
				if (deck[x][y].color_ == BaseFigureColor::grey || deck[x][y].color_ != deck[x1][y1].color_) {
					return true;
				}
				return false;
			}
			else {
				if (deck[x][y].color_ != BaseFigureColor::grey || deck[x][y].color_ == deck[x1][y1].color_) {
					return false;
				}
			}
		}
		return true;
	}
	else if (x2 > x1 && y2 > y1) { // � ������ �������� - x2 �������������, y2 �������������
		for (int x = x1 + 1, y = y1 + 1; x <= x2/*, y <= y2*/; x++, y++) {
			if (x == x2 && y == y2) {
				if (deck[x][y].color_ == BaseFigureColor::grey || deck[x][y].color_ != deck[x1][y1].color_) {
					return true;
				}
				return false;
			}
			else {
				if (deck[x][y].color_ != BaseFigureColor::grey || deck[x][y].color_ == deck[x1][y1].color_) {
					return false;
				}
			}
		}
		return true;
	}
	else if (x2 > x1 && y2 < y1) { // � ��������� �������� - x2 ������������, y2 �����������
		for (int x = x1 + 1, y = y1 - 1; x <= x2/*, y >= y2*/; x++, y--) {
			if (x == x2 && y == y2) {
				if (deck[x][y].color_ == BaseFigureColor::grey || deck[x][y].color_ != deck[x1][y1].color_) {
					return true;
				}
				return false;
			}
			else {
				if (deck[x][y].color_ != BaseFigureColor::grey || deck[x][y].color_ == deck[x1][y1].color_) {
					return false;
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
}

// �������� ������� ����
bool DirectlineColision(std::vector<std::vector<BaseFigure>>& deck,
	const int& x1, const int& y1, const int& x2, const int& y2) {
	if (x1 != x2 && y1 == y2) {
		if (x1 < x2) { // �������� ����
			for (int x = x1 + 1; x <= x2; x++) {
				if (x == x2) {
					if (deck[x][y1].color_ == BaseFigureColor::grey || deck[x][y1].color_ != deck[x1][y1].color_) {
						return true;
					}
					return false;
				}
				else {
					if (deck[x][y1].color_ != BaseFigureColor::grey || deck[x][y1].color_ == deck[x1][y1].color_) {
						return false;
					}
				}
			}
			return true;
		}
		else { // �������� �����
			for (int x = x1 - 1; x >= x2; x--) {
				if (x == x2) {
					if (deck[x][y1].color_ == BaseFigureColor::grey || deck[x][y1].color_ != deck[x1][y1].color_) {
						return true;
					}
					return false;
				}
				else {
					if (deck[x][y1].color_ != BaseFigureColor::grey || deck[x][y1].color_ == deck[x1][y1].color_) {
						return false;
					}
				}
			}
			return true;
		}
	}
	else if (x1 == x2 && y1 != y2) {
		if (y1 < y2) { // �������� ������
			for (int y = y1 + 1; y <= x2; y++) {
				if (y == y2) {
					if (deck[x1][y].color_ == BaseFigureColor::grey || deck[x1][y].color_ != deck[x1][y1].color_) {
						return true;
					}
					return false;
				}
				else {
					if (deck[x1][y].color_ != BaseFigureColor::grey || deck[x1][y].color_ == deck[x1][y1].color_) {
						return false;
					}
				}
			}
			return true;
		}
		else { // �������� �����
			for (int y = y1 - 1; y >= y2; y--) {
				if (y == y2) {
					if (deck[x1][y].color_ == BaseFigureColor::grey || deck[x1][y].color_ != deck[x1][y1].color_) {
						return true;
					}
					return false;
				}
				else {
					if (deck[x1][y].color_ != BaseFigureColor::grey || deck[x1][y].color_ == deck[x1][y1].color_) {
						return false;
					}
				}
			}
			return true;
		}
	}
	else {
		return false;
	}
}

// �������� �������� ������
bool KingMoveCheck(std::vector<std::vector<BaseFigure>>& deck, 
	const int& x1, const int& y1, const int& x2, const int& y2) {
	if ((x1 - 1) == x2 || x2 == (x1 + 1) || x2 == x1) {
		if ((y1 - 1) == y2 || y2 == (y1 + 1) || y2 == y1 
			&& DirectlineColision(deck, x1, y1, x2, y2)
			&& DialineColision(deck, x1, y1, x2, y2)) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

// �������� �������� ��������
bool QueenMoveCheck(std::vector<std::vector<BaseFigure>>& deck, 
	const int& x1, const int& y1, const int& x2, const int& y2) {
	int kx = x2 - x1;
	int ky = y2 - y1;

	if (kx == ky || kx == -ky || -kx == -ky || -kx == ky 
		|| (x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2)
		&& DirectlineColision(deck, x1, y1, x2, y2) 
		&& DialineColision(deck, x1, y1, x2, y2)) {
		return true;
	} else {
		return false;
	}
}

// �������� �������� �����
bool TowerMoveCheck(std::vector<std::vector<BaseFigure>>& deck, 
	const int& x1, const int& y1, const int& x2, const int& y2) {
	if (x1 != x2) {
		if (y1 == y2 && DirectlineColision(deck, x1, y1, x2, y2)) {
			return true;
		} else {
			return false;
		}
	} else if (y1 != y2 && DirectlineColision(deck, x1, y1, x2, y2)) {
		return true;
	} else {
		return false;
	}
}

// �������� �������� �������
bool OfficerMoveCheck(std::vector<std::vector<BaseFigure>>& deck,
	const int& x1, const int& y1, const int& x2, const int& y2) {
	int kx = x2 - x1;
	int ky = y2 - y1;

	if ((kx == ky || kx == -ky || -kx == -ky || -kx == ky) 
		&& DialineColision(deck, x1, y1, x2, y2)) {
		return true;
	} else {
		return false;
	}
}

// �������� �������� ����
bool HorseMoveCheck(std::vector<std::vector<BaseFigure>>& deck,
	const int& x1, const int& y1, const int& x2, const int& y2) {
	if (deck[x2][y2].color_ == deck[x1][y1].color_) {
		return false;
	}
	else {
		if (
			((x2 == x1 + 2 || x2 == x1 - 2) && (y2 == y1 + 1 || y2 == y1 - 1)) ||
			((y2 == y1 + 2 || y2 == y1 - 2) && (x2 == x1 + 1 || x2 == x1 - 1))
			) {
			return true;
		}
		else {
			return false;
		}
	}
}

// �������� �������� �����
bool SolderMoveCheck(std::vector<std::vector<BaseFigure>>& deck, 
	const BaseFigureColor& color, const int& x1, const int& y1, const int& x2, const int& y2) {
	if (color == BaseFigureColor::white) {
		if (y1 == y2) {
			if (x1 == 6 && x2 == 4 // ������ ���
				&& deck[x1 - 1][y2].type_ == BaseFigureType::zero
				&& deck[x2][y2].type_ == BaseFigureType::zero) { 
				return true;
			} 
			else if (x1 - x2 == 1 // ������� ���
				&& deck[x2][y2].type_ == BaseFigureType::zero) { 
				return true;
			} 
			else {
				return false;
			}
		} 
		else if (y1 - y2 == 1 || y1 - y2 == -1 && x1 - x2 == 1) { // �������� ������
			if (deck[x2][y2].color_ == BaseFigureColor::black) {
				return true;
			} 
			else {
				return false;
			}
		} 
		else {
			return false;
		}
		
	} else if (color == BaseFigureColor::black) {
		if (y1 == y2) {
			if (x1 == 1 && x2 == 3 // ������ ���
				&& deck[x1 + 1][y2].type_ == BaseFigureType::zero
				&& deck[x2][y2].type_ == BaseFigureType::zero) {
				return true;
			}
			else if (x2 - x1 == 1 // ������� ���
				&& deck[x2][y2].type_ == BaseFigureType::zero) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (y1 - y2 == 1 || y1 - y2 == -1 && x2 - x1 == 1) { // �������� ������
			if (deck[x2][y2].color_ == BaseFigureColor::white) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}