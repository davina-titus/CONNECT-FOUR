# Connect Four 🔴🟡

A fully playable two-player Connect Four game built in C++, 
running in the console with a clean board display and complete 
win detection logic.

## How to Play
- Two players take turns dropping pieces into a 7-column, 6-row grid
- Enter a column number (1–7) to drop your piece
- First player to connect four pieces horizontally, vertically,
  or diagonally wins
- The board updates and displays after every move

## Features
- Full 6x7 grid implementation
- Two-player local gameplay
- Win detection in all four directions — horizontal, vertical,
  diagonal left, diagonal right
- Draw detection when the board is full
- Input validation to prevent invalid or full-column moves
- Clean console board rendering after each turn

## Concepts Demonstrated
- 2D array manipulation in C++
- Nested loop logic for multi-directional win checking
- Input validation and game loop design
- Object-oriented structure with classes and methods
- Console-based UI design

## How to Run
```bash
g++ -o connectfour main.cpp
./connectfour
```

## Language
- **C++**

---
*Built as part of CS coursework @ University of Illinois Chicago*
