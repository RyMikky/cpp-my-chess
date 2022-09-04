#include "move_check.h"

//  оллизи€ диагонального пути
bool DialineColision(std::vector<std::vector<BaseFigure>>& deck,
	const int& x1, const int& y1, const int& x2, const int& y2) {
	// колизи€ провер€ет не наход€тс€ ли на пути
	// считаем четверти по часовой стрелке с верхнего левого угла
	if (x2 < x1 && y2 < y1) { // в первую четверть - x2 уменьшаетс€, y2 уменьшаетс€
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
	else if (x2 < x1 && y2 > y1) { // во вторую четверть - x2 уменьшаетс€, y2 увеличиваетс€
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
	else if (x2 > x1 && y2 > y1) { // в третью четверть - x2 увеличиваетс€, y2 увеличиваетс€
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
	else if (x2 > x1 && y2 < y1) { // в четвертую четверть - x2 увеличиветс€, y2 уменьшаетс€
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

//  оллизи€ пр€мого пути
bool DirectlineColision(std::vector<std::vector<BaseFigure>>& deck,
	const int& x1, const int& y1, const int& x2, const int& y2) {
	if (x1 != x2 && y1 == y2) {
		if (x1 < x2) { // движение вниз
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
		else { // движение вверх
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
		if (y1 < y2) { // движение вправо
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
		else { // движение влево
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

// проверка движени€ корол€
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

// ѕроверка движени€ королевы
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

// ѕроверка движени€ ладьи
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

// ѕроверка движени€ офицера
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

// ѕроверка движени€ кон€
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

// ѕроверка движени€ пешки
bool SolderMoveCheck(std::vector<std::vector<BaseFigure>>& deck, 
	const BaseFigureColor& color, const int& x1, const int& y1, const int& x2, const int& y2) {
	if (color == BaseFigureColor::white) {
		if (y1 == y2) {
			if (x1 == 6 && x2 == 4 // ѕервый ход
				&& deck[x1 - 1][y2].type_ == BaseFigureType::zero
				&& deck[x2][y2].type_ == BaseFigureType::zero) { 
				return true;
			} 
			else if (x1 - x2 == 1 // ќбычный ход
				&& deck[x2][y2].type_ == BaseFigureType::zero) { 
				return true;
			} 
			else {
				return false;
			}
		} 
		else if (y1 - y2 == 1 || y1 - y2 == -1 && x1 - x2 == 1) { // поедание фигуры
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
			if (x1 == 1 && x2 == 3 // ѕервый ход
				&& deck[x1 + 1][y2].type_ == BaseFigureType::zero
				&& deck[x2][y2].type_ == BaseFigureType::zero) {
				return true;
			}
			else if (x2 - x1 == 1 // ќбычный ход
				&& deck[x2][y2].type_ == BaseFigureType::zero) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (y1 - y2 == 1 || y1 - y2 == -1 && x2 - x1 == 1) { // поедание фигуры
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