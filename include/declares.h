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

#pragma once

#include <array>
#include <utility>

using std::array;
using std::pair;

namespace tictactoe {

/**
 * @enum PLAYER
 * @brief Enumeration for player type, which in tic-tac-toe is X and O.
 */
enum class PLAYER { X, O };

/**
 * @enum CELL_VALUE
 * @brief The value of a tic-tac-toe cell, which is X, O, or empty.
 */
enum class CELL_VALUE { X, O, EMPTY };

/**
 * @enum GAME_STATE
 * @brief X_WIN if X player won. O_WIN if O player won. Otherwise DRAW OR ONGOING.
 */
enum class GAME_STATE { X_WIN, O_WIN, DRAW, ONGOING };

/**
 * @typedef COL
 * @brief Data type for tic-tac-toe column.
 */
using COL = array<CELL_VALUE, 3>;

/**
 * @typedef COLROW
 * @brief Typedef for the col/row coordinate.
 */
using COLROW = pair<size_t, size_t>;

/**
 * @typedef WORLD
 * @brief The tic-tac-toe world, consisting of all 3 column and 3 row.
 */
using WORLD = array<COL, 3>;

/**
 * @var DEFAULT_WORLD
 * @brief The default world consisting of all empty cells.
 */
extern const WORLD DEFAULT_WORLD;

}  // namespace tictactoe