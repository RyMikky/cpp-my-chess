#pragma once

#include <thread>
#include <chrono>
#include <iostream>

//макрос для быстрой записи паузы
#define WAIT(cout) std::this_thread::sleep_for(std::chrono::milliseconds(cout));

enum ConsoleColor {
	black_text = 0, blue_text = 1, green_text, l_blue_text, red_text,
	purple_text, yellow_text, white_text, grey_text, d_blue_text, l_green_text
};

enum MenuPoint {
	game_exit = 0, game_start, game_sleep, game_resume, game_save, game_load,
	game_stats, game_test, game_about, game_standbye, in_the_game
};

enum SavePoint {
	save0 = 0, save1, save2, save3, save4,
	save5, save6, save7, save8, save9
};

enum GameStatus {
	standby = 0, in_process, on_pause, saved, paramed
};