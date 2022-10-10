/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//  ���� unit-������ ���� ��������� ���������                                                  //
//                                                                                             //
//  ���������:                                                                                 //
//  1. namespace figures_tests - ���� ������������ ������� ������ Figure                       //
//                                                                                             //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>
#include <variant>
#include <cassert>
#include <iostream>
#include <string_view>

#include "game_resource.h"                                       // ������ �������� ����
#include "game_geo_libary.h"                                     // ������ �������������� �������
#include "game_chess_deck.h"                                     // ������ ������ ��������� �����


namespace chess {

	namespace test_frame {

		class UnitTest { // �����-��������� ���� ������
		public:
			UnitTest() = default;
			virtual ~UnitTest() = default;

			virtual void UnitConstructorTest() = 0;
			virtual void UnitMethodTest() = 0;
		};

		namespace resources_tests {

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

		} // namespace resources_tests

		namespace modules_tests {

			namespace deck_tests {

				class DeckTest : public UnitTest {
				public:
					DeckTest() : UnitTest() {
						UnitConstructorTest();
						UnitMethodTest();
					}

					void UnitConstructorTest() override;
					void UnitMethodTest() override;
				};

			} // namespace deck_tests

		} // modules_tests

		void RunAllTestes();

	} // namespace test_frame

} // namespace chess