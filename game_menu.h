#pragma once
#include "chess_game.h" // Движок игры
#include "game_test_system.h" // Тестовая система
#include "print_machine.h" // Печатная система
#include "system_defines.h" // Общая библиотека макросов, перечислений и прочих дефайнов

//подсистемы меню
#include "game_menu_save.h" // Функции сохранения

#include <Windows.h>
#include <thread>
#include <chrono>

class GameMenu {
public:

	// точка входа программы
	GameMenu() : this_game_(0, standby, "Старт системы") {
		std::string _user_input; bool g_exit_ = false;
		while (!g_exit_)
		{

			MainMenuPrint();
			try
			{
				std::cout << "   "; // отступ
				std::cin >> _user_input;
				int menu_number_ = std::stoi(_user_input);;

				if (menu_number_ <= 9 && menu_number_ >= 0) {
					switch (menu_number_) {
						case game_start: {
							game.GameReset();
							status = MenuPoint::in_the_game;
							GameStartPrint();

							/*std::thread new_game_;

							new_game_.join();*/
							break;
						}
						case game_sleep: {
							status = MenuPoint::game_sleep;
							break;
						}
						case game_resume: {
							status = MenuPoint::in_the_game;
							break;
						}
						case game_save: {
							std::thread game_saving(SaveTheGame, game);
							game_saving.join();
							break;
						}
						case game_load: {
							break;
						}
						case game_stats: {
							game.GetPlayerTotalMoveCount(FigureColor::white);
							game.GetPlayerTotalMoveCount(FigureColor::black);
							break;
						}
						case game_test: {
							status = MenuPoint::game_test;
							std::thread game_test(GlobalTest);
							game_test.join();
							break;
						}
						case game_about: {
							break;
						}
						case game_exit: {
							system("cls");
							status = MenuPoint::game_exit;
							std::cout << std::endl << std::endl
								<< "   Вы действительно желаете выйти? (\"YES\"/\"NO\")"
								<< std::endl << std::endl;

							std::string _choise;
							std::cout << "   ";
							std::cin >> _choise;

							if (_choise == "YES" || _choise == "yes" || _choise == "Y" || _choise == "y") {
								std::cout << std::endl
									<< "   Спасибо за игру! Будем рады видеть Вас снова!"
									<< std::endl << std::endl;
								WAIT(2000);
								g_exit_ = true;
								break;
							}
							break;
						}
						default: {
							std::cout << "   Вы неверно выбрали пункт меню" << std::endl;
							std::cout << "   Для выбора необходимо указать цифру" << std::endl;
							WAIT(1000);
							break;
						}
					}
				}
				else {
					throw std::invalid_argument("Invalid user input");
				}
			}
			catch (const std::invalid_argument&)
			{
				std::cout << std::endl << "   Oops! Invalid user input" << std::endl;
				WAIT(1000);
			}
		}
	};

private:
	MenuPoint status = MenuPoint::game_standbye;
	ChessGame game;

	struct TheGame_
	{
		TheGame_() = default;

		/*explicit TheGame_(const size_t& id);

		TheGame_(const size_t& id, GameStatus status);*/

		TheGame_(const size_t& id, GameStatus status, const std::string& title) 
			: game_id_(id), game_status_(status), game_title_(title) {
			game_ = ChessGame(status);
		}

		size_t game_id_ = 0;
		GameStatus game_status_ = GameStatus::standby;
		std::string game_title_ = ""s;

		ChessGame game_;

		int total_white_player_moves_count_ = 0;
		int total_black_player_moves_count_ = 0;
	};

	TheGame_ this_game_;

	std::map<size_t, TheGame_> game_massive_;
};