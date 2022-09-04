#include "game_resource.h"
#include "unit_test_frame.h"

int main() {
	
	setlocale(LC_ALL, "Russian");

	chess::test_frame::RunAllTestes();

 	return 0;
}