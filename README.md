# Game-Of-Life

A C implementation of Conway’s **Game of Life**. This project simulates a cellular automaton where cells evolve across generations according to a fixed set of rules based on neighboring cells.

## Overview

The Game of Life is played on a two-dimensional grid where each cell is either:

- **Alive (1)**
- **Dead (0)**

During each generation, every cell changes state according to the number of surrounding live neighbors.

Rules:

- Any live cell with fewer than 2 neighbors dies
- Any live cell with 2 or 3 neighbors survives
- Any live cell with more than 3 neighbors dies
- Any dead cell with exactly 3 neighbors becomes alive

The simulation repeatedly applies these rules to produce evolving patterns.

---

## Features

- Simulates Conway’s Game of Life generations
- Counts neighboring live cells
- Updates the board according to game rules
- Detects stable board states
- Uses a **1-D array representation** for a 2-D board
- Handles board boundaries safely
- Supports testing using provided board configurations

---

## Implemented Functions

### `countLiveNeighbor()`

Calculates the number of live neighbors surrounding a specific cell.

Responsibilities:

- Checks all eight surrounding cells
- Handles edge and corner cases
- Avoids counting cells outside board boundaries
- Excludes the current cell from neighbor count

---

### `updateBoard()`

Updates the game board to the next generation.

Responsibilities:

- Applies Conway’s Game of Life rules
- Determines whether cells live, die, or become alive
- Updates every cell simultaneously
- Maintains proper board state transitions

---

### `aliveStable()`

Determines whether the current board configuration will remain unchanged in the next generation.

Returns:

- `1` → board remains unchanged
- `0` → board changes next generation

Used to stop simulation once a stable state is reached.

---

## Board Representation

Although the game board is conceptually two-dimensional, it is stored internally as a **one-dimensional array**.

Cell access uses:

```c
board[row * boardColSize + col]
