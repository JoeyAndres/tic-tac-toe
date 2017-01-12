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

#include <iostream>

#include "TicTacToe.h"

namespace tictactoe {

TicTacToe::TicTacToe() :
    _world(DEFAULT_WORLD),
    _lastGameState(GAME_STATE::ONGOING) {
}

GAME_STATE TicTacToe::getGameState() const {
  if (_isPlayerWinner(PLAYER::X)) {
    return GAME_STATE::X_WIN;
  } else if (_isPlayerWinner(PLAYER::O)) {
    return GAME_STATE::O_WIN;
  } else if (_isEmptyCellExist()) {
    // isOngoing ? if there are empty cell.
    return GAME_STATE::ONGOING;
  } else {
    return GAME_STATE::DRAW;
  }
}

bool TicTacToe::_isPlayerWinner(PLAYER p) const {
  CELL_VALUE targetCellValue = p == PLAYER::X ? CELL_VALUE::X : CELL_VALUE::O;
  
  bool hor1 = _world[0][0] == targetCellValue &&
      _world[0][1] == targetCellValue &&
      _world[0][2] == targetCellValue;
  bool hor2 = _world[1][0] == targetCellValue &&
      _world[1][1] == targetCellValue &&
      _world[1][2] == targetCellValue;
  bool hor3 = _world[2][0] == targetCellValue &&
      _world[2][1] == targetCellValue &&
      _world[2][2] == targetCellValue;
  bool diag1 = _world[0][0] == targetCellValue &&
      _world[1][1] == targetCellValue &&
      _world[2][2] == targetCellValue;
  bool diag2 = _world[2][0] == targetCellValue &&
      _world[1][1] == targetCellValue &&
      _world[0][2] == targetCellValue;

  return hor1 || hor2 || hor3 | diag1 || diag2;
}

bool TicTacToe::_isEmptyCellExist() const {
  for (auto row : _world) {
    for (auto cell : row) {
      if (cell == CELL_VALUE::EMPTY) {
        return true;
      }
    }
  }
  return false;
}

GAME_STATE TicTacToe::setCellValue(
    const COLROW& colRow, const CELL_VALUE& value)
throw(
  ColRowIndexExceededWorldException,
  SettingNonEmptyCellException,
  GameFinishException) {
  if (_lastGameState != GAME_STATE::ONGOING) {
    GameFinishException exception;
    std::cerr << exception.what() << std::endl;
    throw exception;
  }

  if (_isInvalidIndex(colRow)) {
    ColRowIndexExceededWorldException exception;
    std::cerr << exception.what() << std::endl;
    throw exception;
  }

  bool isCellAlreadySet = getCellValue(colRow) != CELL_VALUE::EMPTY;
  if (isCellAlreadySet) {
    SettingNonEmptyCellException exception;
    std::cerr << exception.what() << std::endl;
    throw exception;
  }

  _world.at(std::get<0>(colRow)).at(std::get<1>(colRow)) = value;

  _lastGameState = getGameState();
  return _lastGameState;
}

CELL_VALUE TicTacToe::getCellValue(const COLROW& colRow) const
throw(ColRowIndexExceededWorldException) {
  if (_isInvalidIndex(colRow)) {
    throw ColRowIndexExceededWorldException();
  }

  return _world
      .at(std::get<0>(colRow))  // col
      .at(std::get<1>(colRow));  // row
}

bool TicTacToe::_isInvalidIndex(const COLROW& colRow) const {
  if (std::get<0>(colRow) > 2 || std::get<1>(colRow) > 2) {
    return true;
  }

  return false;
}

}  // namespace tictactoe