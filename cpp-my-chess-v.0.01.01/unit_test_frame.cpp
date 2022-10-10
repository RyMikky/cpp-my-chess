#include "unit_test_frame.h"

using namespace std::literals;

namespace chess {

	namespace test_frame {

		namespace resources_tests {

			namespace figures_tests {

				void FiguresTest::UnitConstructorTest(){

					using namespace chess::resource;

					std::cerr << "Figures constructors test begin"sv << std::endl;

					// Тестирование дефорлтных конструкторов
					{
						chess::resource::Figure simple_figure;
						assert(simple_figure.in_game() == false);
						assert(simple_figure.get_type() == zero);
						assert(simple_figure.get_color() == grey);

						chess::resource::Empty empty_figure;
						assert(empty_figure.in_game() == false);
						assert(empty_figure.get_type() == zero);
						assert(empty_figure.get_color() == grey);

						chess::resource::King king_figure;
						assert(king_figure.in_game() == false);
						assert(king_figure.get_type() == king);
						assert(king_figure.get_color() == grey);

						chess::resource::Queen queen_figure;
						assert(queen_figure.in_game() == false);
						assert(queen_figure.get_type() == queen);
						assert(queen_figure.get_color() == grey);

						chess::resource::Tower tower_figure;
						assert(tower_figure.in_game() == false);
						assert(tower_figure.get_type() == tower);
						assert(tower_figure.get_color() == grey);

						chess::resource::Officer officer_figure;
						assert(officer_figure.in_game() == false);
						assert(officer_figure.get_type() == officer);
						assert(officer_figure.get_color() == grey);

						chess::resource::Horse horse_figure;
						assert(horse_figure.in_game() == false);
						assert(horse_figure.get_type() == horse);
						assert(horse_figure.get_color() == grey);

						chess::resource::Solder solder_figure;
						assert(solder_figure.in_game() == false);
						assert(solder_figure.get_type() == solder);
						assert(solder_figure.get_color() == grey);

						std::cerr << " - Figures default constructors test complete"sv << std::endl;
					}

					// Тестирование параметрических конструкторов
					{
						// Параметрический конструктор с заданым id
						{
							chess::resource::Figure simple_figure(1);
							assert(simple_figure.get_id() == 1);

							chess::resource::Empty empty_figure(2);
							assert(empty_figure.get_id() == 2);

							chess::resource::King king_figure(3);
							assert(king_figure.get_id() == 3);

							chess::resource::Queen queen_figure(4);
							assert(queen_figure.get_id() == 4);

							chess::resource::Tower tower_figure(5);
							assert(tower_figure.get_id() == 5);

							chess::resource::Officer officer_figure(6);
							assert(officer_figure.get_id() == 6);

							chess::resource::Horse horse_figure(7);
							assert(horse_figure.get_id() == 7);

							chess::resource::Solder solder_figure(8);
							assert(solder_figure.get_id() == 8);

							std::cerr << " - Figures parametric(id) constructors test complete"sv << std::endl;
						}

						// Параметрический конструктор с заданым id и color
						{
							chess::resource::Figure simple_figure(11, grey);
							assert(simple_figure.get_id() == 11);
							assert(simple_figure.get_color() == grey);

							chess::resource::Empty empty_figure(21, black);
							assert(empty_figure.get_id() == 21);
							assert(empty_figure.get_color() == black);

							chess::resource::King king_figure(32, white);
							assert(king_figure.get_id() == 32);
							assert(king_figure.get_color() == white);

							chess::resource::Queen queen_figure(45, black);
							assert(queen_figure.get_id() == 45);
							assert(queen_figure.get_color() != white && queen_figure.get_color() == black);

							chess::resource::Tower tower_figure(59, grey);
							assert(tower_figure.get_id() == 59);
							assert(tower_figure.get_color() != white && tower_figure.get_color() != black);

							chess::resource::Officer officer_figure(63, white);
							assert(officer_figure.get_id() == 63);
							assert(officer_figure.get_color() == white);

							chess::resource::Horse horse_figure(71, black);
							assert(horse_figure.get_id() == 71);
							assert(horse_figure.get_color() == black);

							chess::resource::Solder solder_figure(80, black);
							assert(solder_figure.get_id() == 80);
							assert(solder_figure.get_color() == black);

							std::cerr << " - Figures parametric(id, color) constructors test complete"sv << std::endl;
						}

						// Параметрический конструктор с заданым id, color и Coordinates
						{
							chess::resource::Figure simple_figure(11, grey, {2, 1});
							assert(simple_figure.get_id() == 11);
							assert(simple_figure.get_color() == grey);
							assert(simple_figure.get_coordinates() == Coordinates(2, 1));

							chess::resource::Empty empty_figure(21, black, { 2, 1 });
							assert(empty_figure.get_id() == 21);
							assert(empty_figure.get_color() == black);
							assert(empty_figure.get_coordinates() == Coordinates(2, 1));

							chess::resource::King king_figure(32, white, { 2, 1 });
							assert(king_figure.get_id() == 32);
							assert(king_figure.get_color() == white);
							assert(king_figure.get_coordinates() == Coordinates(2, 1));

							chess::resource::Queen queen_figure(45, black, { 2, 1 });
							assert(queen_figure.get_id() == 45);
							assert(queen_figure.get_color() != white && queen_figure.get_color() == black);
							assert(queen_figure.get_coordinates() == Coordinates(2, 1));

							chess::resource::Tower tower_figure(59, grey, { 2, 1 });
							assert(tower_figure.get_id() == 59);
							assert(tower_figure.get_color() != white && tower_figure.get_color() != black);
							assert(tower_figure.get_coordinates() == Coordinates(2, 1));

							chess::resource::Officer officer_figure(63, white, { 2, 1 });
							assert(officer_figure.get_id() == 63);
							assert(officer_figure.get_color() == white);
							assert(officer_figure.get_coordinates() == Coordinates(2, 1));

							chess::resource::Horse horse_figure(71, black, { 2, 1 });
							assert(horse_figure.get_id() == 71);
							assert(horse_figure.get_color() == black);
							assert(horse_figure.get_coordinates() == Coordinates(2, 1));

							chess::resource::Solder solder_figure(80, black, { 2, 1 });
							assert(solder_figure.get_id() == 80);
							assert(solder_figure.get_color() == black);
							assert(solder_figure.get_coordinates() == Coordinates(2, 1));

							std::cerr << " - Figures parametric(id, color, coordinates) constructors test complete"sv << std::endl;
						}
						
					}

					std::cerr << "Figures constructors test complete"sv << std::endl << std::endl;
				}

				void FiguresTest::UnitMethodTest() {

					using namespace chess::resource;

					std::cerr << "Figures method test begin"sv << std::endl;

					// тестирование функций Figure
					{

						chess::resource::Figure unit(1);

						// изменение/получение id фигуры
						{
							unit.set_id(2);
							assert(unit.get_id() == 2);
						}

						// изменение/получение цвета фигуры
						{
							unit.set_color(black);
							assert(unit.get_color() == black);
						}

						// изменение/получение координат фигуры
						{
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 0.0, 0.0 }));
							unit.set_coordinates(1, 4);
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 1.0, 4.0 }));
						}

						// изменение/получение флага "в игре"
						{
							assert(unit.in_game() == false);
							unit.set_in_game();
							assert(unit.in_game() == true);
							unit.set_out_game();
							assert(unit.in_game() == false);
						}

						// изменение/получение иконки фигуры
						{
							assert(unit.get_label() == "");
							unit.set_label("5");
							assert(unit.get_label() == "5" && std::stoi(unit.get_label()) == 5);
						}

						// изменение/получение имени фигуры
						{
							assert(unit.get_name() == "");
							unit.set_name("тест");
							assert(unit.get_name() == "тест");
						}

						// изменение/получение типа фигуры по полю класса
						{
							assert(unit.get_type() == zero);
							unit.set_type(queen);
							assert(unit.get_type() == queen);
						}

						// изменение/получение количества ходов
						{
							assert(unit.get_move_count() == 0);
							unit.move_count_up();
							assert(unit.get_move_count() == 1);
							unit.move_count_up(5);
							assert(unit.get_move_count() == 6);
						}

						std::cerr << " - Figure method test complete"sv << std::endl;
						
					}

					// тестирование функций King
					{

						chess::resource::King unit(1);

						// изменение/получение id фигуры
						{
							unit.set_id(2);
							assert(unit.get_id() == 2);
						}

						// изменение/получение цвета фигуры
						{
							unit.set_color(black);
							assert(unit.get_color() == black);
						}

						// изменение/получение координат фигуры
						{
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 0.0, 0.0 }));
							unit.set_coordinates(1, 4);
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 1.0, 4.0 }));
						}

						// изменение/получение флага "в игре"
						{
							assert(unit.in_game() == false);
							unit.set_in_game();
							assert(unit.in_game() == true);
							unit.set_out_game();
							assert(unit.in_game() == false);
						}

						// изменение/получение иконки фигуры
						{
							assert(unit.get_label() == "К");
							unit.set_label("5");
							assert(unit.get_label() == "5" && std::stoi(unit.get_label()) == 5);
						}

						// изменение/получение имени фигуры
						{
							assert(unit.get_name() == "Король");
							unit.set_name("тест");
							assert(unit.get_name() == "тест");
						}

						// изменение/получение типа фигуры по полю класса
						{
							assert(unit.get_type() == king);
							unit.set_type(queen);
							assert(unit.get_type() == queen);
						}

						// изменение/получение количества ходов
						{
							assert(unit.get_move_count() == 0);
							unit.move_count_up();
							assert(unit.get_move_count() == 1);
							unit.move_count_up(5);
							assert(unit.get_move_count() == 6);
						}

						std::cerr << " - King method test complete"sv << std::endl;

					}

					// тестирование функций Queen
					{

						chess::resource::Queen unit(1);

						// изменение/получение id фигуры
						{
							unit.set_id(2);
							assert(unit.get_id() == 2);
						}

						// изменение/получение цвета фигуры
						{
							unit.set_color(black);
							assert(unit.get_color() == black);
						}

						// изменение/получение координат фигуры
						{
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 0.0, 0.0 }));
							unit.set_coordinates(1, 4);
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 1.0, 4.0 }));
						}

						// изменение/получение флага "в игре"
						{
							assert(unit.in_game() == false);
							unit.set_in_game();
							assert(unit.in_game() == true);
							unit.set_out_game();
							assert(unit.in_game() == false);
						}

						// изменение/получение иконки фигуры
						{
							assert(unit.get_label() == "Ш");
							unit.set_label("5");
							assert(unit.get_label() == "5" && std::stoi(unit.get_label()) == 5);
						}

						// изменение/получение имени фигуры
						{
							assert(unit.get_name() == "Королева");
							unit.set_name("тест");
							assert(unit.get_name() == "тест");
						}

						// изменение/получение типа фигуры по полю класса
						{
							assert(unit.get_type() == queen);
							unit.set_type(zero);
							assert(unit.get_type() == zero);
						}

						// изменение/получение количества ходов
						{
							assert(unit.get_move_count() == 0);
							unit.move_count_up();
							assert(unit.get_move_count() == 1);
							unit.move_count_up(5);
							assert(unit.get_move_count() == 6);
						}

						std::cerr << " - Queen method test complete"sv << std::endl;

					}

					// тестирование функций Tower
					{

						chess::resource::Tower unit(1);

						// изменение/получение id фигуры
						{
							unit.set_id(2);
							assert(unit.get_id() == 2);
						}

						// изменение/получение цвета фигуры
						{
							unit.set_color(black);
							assert(unit.get_color() == black);
						}

						// изменение/получение координат фигуры
						{
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 0.0, 0.0 }));
							unit.set_coordinates(1, 4);
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 1.0, 4.0 }));
						}

						// изменение/получение флага "в игре"
						{
							assert(unit.in_game() == false);
							unit.set_in_game();
							assert(unit.in_game() == true);
							unit.set_out_game();
							assert(unit.in_game() == false);
						}

						// изменение/получение иконки фигуры
						{
							assert(unit.get_label() == "Т");
							unit.set_label("5");
							assert(unit.get_label() == "5" && std::stoi(unit.get_label()) == 5);
						}

						// изменение/получение имени фигуры
						{
							assert(unit.get_name() == "Ладья");
							unit.set_name("тест");
							assert(unit.get_name() == "тест");
						}

						// изменение/получение типа фигуры по полю класса
						{
							assert(unit.get_type() == tower);
							unit.set_type(zero);
							assert(unit.get_type() == zero);
						}

						// изменение/получение количества ходов
						{
							assert(unit.get_move_count() == 0);
							unit.move_count_up();
							assert(unit.get_move_count() == 1);
							unit.move_count_up(5);
							assert(unit.get_move_count() == 6);
						}

						std::cerr << " - Tower method test complete"sv << std::endl;

					}

					// тестирование функций Officer
					{

						chess::resource::Officer unit(1);

						// изменение/получение id фигуры
						{
							unit.set_id(2);
							assert(unit.get_id() == 2);
						}

						// изменение/получение цвета фигуры
						{
							unit.set_color(black);
							assert(unit.get_color() == black);
						}

						// изменение/получение координат фигуры
						{
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 0.0, 0.0 }));
							unit.set_coordinates(1, 4);
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 1.0, 4.0 }));
						}

						// изменение/получение флага "в игре"
						{
							assert(unit.in_game() == false);
							unit.set_in_game();
							assert(unit.in_game() == true);
							unit.set_out_game();
							assert(unit.in_game() == false);
						}

						// изменение/получение иконки фигуры
						{
							assert(unit.get_label() == "С");
							unit.set_label("5");
							assert(unit.get_label() == "5" && std::stoi(unit.get_label()) == 5);
						}

						// изменение/получение имени фигуры
						{
							assert(unit.get_name() == "Слон");
							unit.set_name("тест");
							assert(unit.get_name() == "тест");
						}

						// изменение/получение типа фигуры по полю класса
						{
							assert(unit.get_type() == officer);
							unit.set_type(zero);
							assert(unit.get_type() == zero);
						}

						// изменение/получение количества ходов
						{
							assert(unit.get_move_count() == 0);
							unit.move_count_up();
							assert(unit.get_move_count() == 1);
							unit.move_count_up(5);
							assert(unit.get_move_count() == 6);
						}

						std::cerr << " - Officer method test complete"sv << std::endl;

					}

					// тестирование функций Horse
					{

						chess::resource::Horse unit(1);

						// изменение/получение id фигуры
						{
							unit.set_id(2);
							assert(unit.get_id() == 2);
						}

						// изменение/получение цвета фигуры
						{
							unit.set_color(black);
							assert(unit.get_color() == black);
						}

						// изменение/получение координат фигуры
						{
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 0.0, 0.0 }));
							unit.set_coordinates(1, 4);
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 1.0, 4.0 }));
						}

						// изменение/получение флага "в игре"
						{
							assert(unit.in_game() == false);
							unit.set_in_game();
							assert(unit.in_game() == true);
							unit.set_out_game();
							assert(unit.in_game() == false);
						}

						// изменение/получение иконки фигуры
						{
							assert(unit.get_label() == "Г");
							unit.set_label("5");
							assert(unit.get_label() == "5" && std::stoi(unit.get_label()) == 5);
						}

						// изменение/получение имени фигуры
						{
							assert(unit.get_name() == "Конь");
							unit.set_name("тест");
							assert(unit.get_name() == "тест");
						}

						// изменение/получение типа фигуры по полю класса
						{
							assert(unit.get_type() == horse);
							unit.set_type(zero);
							assert(unit.get_type() == zero);
						}

						// изменение/получение количества ходов
						{
							assert(unit.get_move_count() == 0);
							unit.move_count_up();
							assert(unit.get_move_count() == 1);
							unit.move_count_up(5);
							assert(unit.get_move_count() == 6);
						}

						std::cerr << " - Horse method test complete"sv << std::endl;

					}

					// тестирование функций Solder
					{

						chess::resource::Solder unit(1);

						// изменение/получение id фигуры
						{
							unit.set_id(2);
							assert(unit.get_id() == 2);
						}

						// изменение/получение цвета фигуры
						{
							unit.set_color(black);
							assert(unit.get_color() == black);
						}

						// изменение/получение координат фигуры
						{
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 0.0, 0.0 }));
							unit.set_coordinates(1, 4);
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 1.0, 4.0 }));
						}

						// изменение/получение флага "в игре"
						{
							assert(unit.in_game() == false);
							unit.set_in_game();
							assert(unit.in_game() == true);
							unit.set_out_game();
							assert(unit.in_game() == false);
						}

						// изменение/получение иконки фигуры
						{
							assert(unit.get_label() == "П");
							unit.set_label("5");
							assert(unit.get_label() == "5" && std::stoi(unit.get_label()) == 5);
						}

						// изменение/получение имени фигуры
						{
							assert(unit.get_name() == "Пешка");
							unit.set_name("тест");
							assert(unit.get_name() == "тест");
						}

						// изменение/получение типа фигуры по полю класса
						{
							assert(unit.get_type() == solder);
							unit.set_type(zero);
							assert(unit.get_type() == zero);
						}

						// изменение/получение количества ходов
						{
							assert(unit.get_move_count() == 0);
							unit.move_count_up();
							assert(unit.get_move_count() == 1);
							unit.move_count_up(5);
							assert(unit.get_move_count() == 6);
						}

						std::cerr << " - Solder method test complete"sv << std::endl;

					}

					// тестирование функций Empty
					{

						chess::resource::Empty unit(1);

						// изменение/получение id фигуры
						{
							unit.set_id(2);
							assert(unit.get_id() == 2);
						}

						// изменение/получение цвета фигуры
						{
							assert(unit.get_color() == grey);
							unit.set_color(black);
							assert(unit.get_color() == black);
						}

						// изменение/получение координат фигуры
						{
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 0.0, 0.0 }));
							unit.set_coordinates(1, 4);
							assert(unit.get_coordinates() == chess::geo::Coordinates({ 1.0, 4.0 }));
						}

						// изменение/получение флага "в игре"
						{
							assert(unit.in_game() == false);
							unit.set_in_game();
							assert(unit.in_game() == true);
							unit.set_out_game();
							assert(unit.in_game() == false);
						}

						// изменение/получение иконки фигуры
						{
							assert(unit.get_label() == ".");
							unit.set_label("5");
							assert(unit.get_label() == "5" && std::stoi(unit.get_label()) == 5);
						}

						// изменение/получение имени фигуры
						{
							assert(unit.get_name() == "Пусто");
							unit.set_name("тест");
							assert(unit.get_name() == "тест");
						}

						// изменение/получение типа фигуры по полю класса
						{
							assert(unit.get_type() == zero);
							unit.set_type(horse);
							assert(unit.get_type() == horse);
						}

						// изменение/получение количества ходов
						{
							assert(unit.get_move_count() == 0);
							unit.move_count_up();
							assert(unit.get_move_count() == 1);
							unit.move_count_up(5);
							assert(unit.get_move_count() == 6);
						}

						std::cerr << " - Empty method test complete"sv << std::endl;

					}

					std::cerr << "Figures method test complete"sv << std::endl << std::endl;
				}

			} // namespace figures_tests

		} // namespace resources_tests

		namespace modules_tests {

			namespace deck_tests {

				void DeckTest::UnitConstructorTest() {

					using namespace chess::resource;

					std::cerr << "Deck constructors test begin"sv << std::endl;

					// Тестирование дефорлтных конструкторов
					{
						chess::deck::Deck test_deck;
						test_deck.set_clear_deck().set_default_figures();
						test_deck.set_default_figures();
						std::cerr << " - Deck default constructors test complete"sv << std::endl;
					}

					// Тестирование параметрических конструкторов
					{
						// Параметрический конструктор с заданым id
						{							

							std::cerr << " - Deck parametric(id) constructors test complete"sv << std::endl;
						}

						// Параметрический конструктор с заданым id и color
						{							

							std::cerr << " - Deck parametric(id, color) constructors test complete"sv << std::endl;
						}

					}

					std::cerr << "Figures constructors test complete"sv << std::endl << std::endl;
				}

				void DeckTest::UnitMethodTest() {

					/*using namespace chess::resource;

					std::cerr << "Deck method test begin"sv << std::endl;

					{
						chess::deck::Deck test_deck;
						test_deck.set_clear_deck();
						chess::resource::Horse horse;
						horse.set_color(chess::resource::white).set_coordinates(2, 5).in_game();
						test_deck.exchange_figure(std::move(horse));
						test_deck.exchange_figure(std::move(
							chess::resource::Horse(3, chess::resource::black).set_coordinates(0,3).set_in_game()));

						test_deck.get_figure_ptr(0, 3)->render_figure().set_id(15).render_figure();

						std::cerr << std::endl;
					}

					{
						chess::deck::Deck test_deck;
						test_deck.add_black_figure_variant(std::move(King(1, black)));
						std::cerr << std::endl;
					}

					{
						chess::deck::Deck test_deck;
						test_deck.add_black_figure_family(std::move(King(1, black)));
						std::cerr << std::endl;
					}*/

					std::cerr << "Deck method test complete"sv << std::endl << std::endl;
				}

			} // namespace deck_tests

		} // modules_tests

		void RunAllTestes() {
			std::cerr << "Выполняю все тесты модуля"sv << std::endl;
			chess::test_frame::resources_tests::figures_tests::FiguresTest figures_test;
			chess::test_frame::modules_tests::deck_tests::DeckTest deck_test;
		}

	} // namespace test_frame

} // namespace chess