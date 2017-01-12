/**
 * tictactoe
 * Copyright (C) 2016  Joey Andres<yeojserdna@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "tictactoe"
#include "catch.hpp"

using tictactoe::TicTacToe;

SCENARIO("TicTacToe game",
         "[TicTacToe]") {
  TicTacToe ticTacToe;

  GIVEN("New tictactoe world") {
    WHEN("We query the game status") {
      THEN ("The game should be on going") {
        REQUIRE(ticTacToe.getGameState() == tictactoe::GAME_STATE::ONGOING);
      }
    }

    WHEN("We check all the cell") {
      THEN ("They should all be empty.") {
        for (size_t c = 0; c < 3; c++) {
          for (size_t r = 0; r < 3; r++) {
            REQUIRE(ticTacToe.getCellValue({c, r}) == tictactoe::CELL_VALUE::EMPTY);
          }
        }
      }
    }
  }

  GIVEN("X sets [0, 0]") {
    ticTacToe.setCellValue({0, 0}, tictactoe::CELL_VALUE::X);

    WHEN("We query the value of [0, 0]") {
      THEN("It should be X") {
        REQUIRE(ticTacToe.getCellValue({0, 0}) == tictactoe::CELL_VALUE::X);
      }
    }
  }

  GIVEN("TicTacToe with [0, 0] set to X") {
    ticTacToe.setCellValue({0, 0}, tictactoe::CELL_VALUE::X);

    WHEN("We set [0, 0] again") {
      THEN("exception is thrown since it's already set.") {
        bool exceptionThrown = false;
        try {
          ticTacToe.setCellValue({0, 0}, tictactoe::CELL_VALUE::O);
        } catch (tictactoe::SettingNonEmptyCellException snece) {
          exceptionThrown = true;
        }

        REQUIRE(exceptionThrown);
      }
    }
  }

  GIVEN("Winning state for X") {
    ticTacToe.setCellValue({0, 0}, tictactoe::CELL_VALUE::X);
    ticTacToe.setCellValue({0, 2}, tictactoe::CELL_VALUE::O);
    ticTacToe.setCellValue({1, 1}, tictactoe::CELL_VALUE::X);
    ticTacToe.setCellValue({2, 1}, tictactoe::CELL_VALUE::O);
    auto gameState = ticTacToe.setCellValue({2, 2}, tictactoe::CELL_VALUE::X);

    WHEN("We query game state") {
      THEN("It should be X_WIN") {
        REQUIRE(gameState == tictactoe::GAME_STATE::X_WIN);
      }
    }

    WHEN("We O does another move") {
      THEN("Exception is thrown since game is over") {
        bool exceptionThrown = false;
        try {
          ticTacToe.setCellValue({0, 1}, tictactoe::CELL_VALUE::O);
        } catch (tictactoe::GameFinishException gfe) {
          exceptionThrown = true;
        }

        REQUIRE(exceptionThrown);
      }
    }
  }
}