//******************************************************************************
// PROGRAM : PROJECT 5 - CONNECT FOUR
// COURSE : CS 141 - PROGRAM DESIGN II
// DAVINA TITUS 
// UIN : 652284919 
// DATE : 16TH APRIL 2025

// DESCRIPTION :
// THIS PROGRAM IMPLEMENTS A TWO-PLAYER CONNECT FOUR GAME WHERE PLAYERS TAKE TURNS
// DROPPING COLORED DISCS (RED 'R' OR YELLOW 'Y') INTO A 6X7 GRID. THE OBJECTIVE
// IS TO CONNECT FOUR DISCS OF THE SAME COLOR VERTICALLY, HORIZONTALLY, OR DIAGONALLY.
// PLAYERS CAN CHOOSE WHICH COLUMN TO DROP THEIR DISC, AND THE GAME CONTINUES UNTIL
// SOMEONE WINS OR THE BOARD FILLS UP RESULTING IN A TIE.
// *****************************************************************************
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//NUM OF ROWS AND COLUMNS
const int rows = 6;
const int cols = 7;

// FUNCTION PROTOTYPES
void initializeBoard(vector<vector<char>>& board);
void displayBoard(const vector<vector<char>>& board);
bool isValidMove( const vector<vector<char>>& board, int col);
void makeMove(vector<vector<char>>& board, int col, char player);
bool checkWin(const vector<vector<char>>& board, char player);
bool isTie(const vector<vector<char>>& board);

//MAIN FUNCTION
int main() 
{
    // INITIALIZE GAME VARIABLES
    vector<vector<char>> board;
    initializeBoard(board);
    char currentPlayer = 'R';
    bool endGame = false;
    
    // MAIN GAME LOOP
    while (!endGame){
        displayBoard(board);
        cout << "\nIt is " << (currentPlayer=='R'? "Red" : "Yellow") << "'s turn." << endl;
        bool validMove = false;

        // LOOP UNTIL PLAYER MAKES A VALID MOVE
        while (!validMove){
            cout << "In which column would you like to move (-1 to exit)? " << endl;

        int col;
        cin >> col;

        // EXIT GAME
        if (col==-1){
            return 0;
        }

        // VALIDATE THE MOVE
        if (!isValidMove(board,col)){
            cout << "Invalid move,try again." << endl;
            cout << "\nIt is " << (currentPlayer=='R'? "Red" : "Yellow") << "'s turn." << endl;
            continue;
        }

        // EXECUTE THE VALID MOVE
        makeMove(board,col,currentPlayer);
        validMove = true;
    }
    
    // CHECK IF PLAYER HAS WON THE GAME
    if (checkWin(board,currentPlayer)){
            displayBoard(board);
            cout << "\n" << (currentPlayer == 'R' ? "Red" : "Yellow") << " wins!\n";
            endGame=true;
        // CHECK IF BOARD IS FULL (TIE)
        } else if (isTie(board)){ 
            displayBoard(board);
            cout << endl << "Game over. Tie game." << endl;
            endGame = true;
        }else {
            currentPlayer= (currentPlayer =='R')? 'Y' : 'R';
        }
    }
    return 0;
}

// INITIALIZE THE BOARD WITH EMPTY SLOTES ('-')
void initializeBoard(vector<vector<char>>& board){
    board.resize(rows, vector<char>(cols,'-'));
}

// DISPLAY THE CURRENT STATE OF THE BOARD
void displayBoard(const vector<vector<char>>& board){
    // LOOP THROUGH EACH ROW
    for ( int i = 0; i < rows; i++){
        for (int j = 0; j <cols; j++){
            cout << board[i][j]<<" ";
        }
        cout << endl;
    } // PRINT LINE
    cout << string(cols*2 - 1, '=') << endl;
    for (int j = 1; j<= cols; j++){
        cout << j << " ";
    }
    cout << endl;
}

// CHECK IF A MOVE IS VALID
bool isValidMove( const vector<vector<char>>& board, int col){
    // CHECK IF COLUMN IS OUT OF BOUNDS
    if (col<1||col> cols) {
        return false;
    } // CHECK IF COLUMN IS ALREADY FULL
    if (board[0][col-1]!='-'){
        return false;
    }
    return true;
}

// MAKE A MOVE IN THE SPECIFIED COLUMN
void makeMove(vector<vector<char>>& board, int col, char player){
    for (int i= rows -1; i >=0;i--){
        if (board[i][col-1]=='-'){
            board[i][col-1] = player;
            break;
        }
    }
}

// CHECK IF THE PLAYER HAS WON
bool checkWin(const vector<vector<char>>& board, char player){
    //CHECK HORIZONTAL WINS
    for (int row = 0;row<rows;row++){
        for(int col=0;col<=cols-4;col++){
            if (board[row][col]==player &&
                board[row][col+1]==player &&
                board[row][col+2]==player &&
                board[row][col+3]==player) {
                    return true;
            }
        }
    }

    // CHECK VERTICAL WINS
    for (int row = 0;row<=rows-4;row++){
        for(int col=0;col<cols;col++){
            if (board[row][col]==player &&
                board[row+1][col]==player &&
                board[row+2][col]==player &&
                board[row+3][col]==player) {
                    return true;
            }
        }
    }

    //CHECK DIAGNOL WINS (TOP LEFT TO BOTTOM RIGHT)
    for (int row = 0;row<=rows-4;row++){
        for(int col=0;col<=cols-4;col++){
            if (board[row][col]==player &&
                board[row+1][col+1]==player &&
                board[row+2][col+2]==player &&
                board[row+3][col+3]==player) {
                    return true;
            }
        }
    }

    //CHECK DIAGNOL WINS (BOTTOM LEFT TO RIGHT)
    for (int row = 3; row < rows; row++) {
        for (int col = 0; col <= cols - 4; col++) {
            if (board[row][col] == player &&
                board[row-1][col+1] == player &&
                board[row-2][col+2] == player &&
                board[row-3][col+3] == player) {
                return true;
            }
        }
    }
    // NO WIN FOUND 
    return false;
}

// CHECK IF THE GAME IS A TIE
bool isTie(const vector<vector<char>>& board){
    for (int col=0;col<cols;col++){
        if (board[0][col] == '-') {
            return false; // GAME IS NOT A TIE 
        }
    }
    // GAME IS A TIE
    return true;
}


