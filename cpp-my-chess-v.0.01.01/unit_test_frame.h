/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//  Блок unit-тестов всех элементов программы                                                  //
//                                                                                             //
//  Структура:                                                                                 //
//  1. namespace figures_tests - блок тестирования функций класса Figure                       //
//                                                                                             //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>
#include <variant>
#include <cassert>
#include <iostream>
#include <string_view>

#include "game_resource.h"                                       // модуль ресурсов игры
#include "game_geo_libary.h"                                     // модуль геометрических функций


namespace chess {

	namespace test_frame {

		class UnitTest { // класс-интерфейс всех тестов
		public:
			UnitTest() = default;
			virtual ~UnitTest() = default;

			virtual void UnitConstructorTest() = 0;
			virtual void UnitMethodTest() = 0;
		};

		namespace resource_tests {

			namespace figures_tests {

				class FiguresTest : public UnitTest {
				public:
					FiguresTest() : UnitTest() {
						UnitConstructorTest();
						UnitMethodTest();
					}

					void UnitConstructorTest() override;
					void UnitMethodTest() override;
				};

			} // namespace figures_tests

		} // namespace resource_tests

		void RunAllTestes();

	} // namespace test_frame

} // namespace chess_deck