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

#include "declares.h"
#include "ColRowIndexExceededWorldException.h"
#include "SettingNonEmptyCellException.h"
#include "GameFinishException.h"

namespace tictactoe {

/**
 * @class TicTacToe
 * @brief The class representing the tic-tac-toe world.
 */
class TicTacToe{
 public:
  /**
   * Sets all cells to CELL_VALUE::EMPTY.
   */
  TicTacToe();

  /**
   * Gets the current game state.
   * @return Current game state.
   */
  GAME_STATE getGameState() const;

  /**
   * Sets the cell value given the col/row coordinate.
   * @param colRow  col/row coordinate.
   * @param cellValue cell value.
   * @return New game state.
   */
  GAME_STATE setCellValue(const COLROW& colRow, const CELL_VALUE& cellValue)
  throw(
    ColRowIndexExceededWorldException,
    SettingNonEmptyCellException,
    GameFinishException);

  /**
   * Acquires the value of a given col/row coordinate.
   * @param colRow col/row coordinate.
   * @return The value of the cell.
   */
  CELL_VALUE getCellValue(const COLROW& colRow) const
  throw (ColRowIndexExceededWorldException);

 protected:
  /**
   * True if the given player type won.
   * @param p Player type.
   * @return True if the given player type already won.
   */
  bool _isPlayerWinner(PLAYER p) const;

  /**
   * @return True if an empty cell exist.
   */
  bool _isEmptyCellExist() const;

  /**
   * Returns true if a given col/row index is invalid (out of bounds).
   * @param colRow col/row coordinate.
   * @return True if invalid, otherwise true.
   */
  bool _isInvalidIndex(const COLROW& colRow) const;

 protected:
  GAME_STATE _lastGameState;
  WORLD _world;
};

}  // namespace tictactoe