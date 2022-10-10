#pragma once
#include <type_traits>

namespace chess {

	namespace geo {

		struct Coordinates {

			Coordinates() = default;
			Coordinates(double x, double y) : x_(std::move(x)), y_(std::move(y)) {
			}

			bool operator==(const Coordinates& other) {
				return this->x_ == other.x_ && this->y_ == other.y_;
			}

			bool operator!=(const Coordinates& other) {
				return this->x_ != other.x_ && this->y_ != other.y_;
			}

			double x_;
			double y_;
		};

	} // namespace geo

} // namespace chess
