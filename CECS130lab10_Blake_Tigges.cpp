/*
Lab 9 - tic tac toe    
3/30/2022
Section 1A
Blake Tigges
*/

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;
class game{  
    public:
        void clearBoard(); // function to clear board
        void printBoard(); // function to print board
        int checkSpot(int, int); // function to check spot
        void first(); // function to who goes first randomly
        void flipActive(); // change active letter
        void checkWin(); // has someone won
        void whoWon(); // who won
        int turn; // track of turn, 0 = player, 1 = computer
        int done = 0; // is game still playing
        char active = 'X'; // use x or o
    private:
        char board[3][3]; // 3x3 array for board
};
class game3d : public game{
    public:
        void clearBoard(); // function to clear board
        void printBoard(); // function to print board
        int checkSpot(int, int, int); // function to check spot
        void checkWin(); // has someone won
    private:
        char board[3][3][3]; // 3x3x3 array for board [col][row][level]
};
int main(){
    cout << "Tic Tac Toe" << endl;
    game3d tboard; // create board object
    tboard.clearBoard(); // clear board
    tboard.printBoard(); // print board
    tboard.first(); // who goes first
    while (tboard.done == 0){ // while game is still playing
        if (tboard.turn == 0){ // if it is player's turn
            cout << "Player's turn" << endl;
            int col; // column
            int row; // row
            int lvl; // level
             do { // keep getting new spot until spot is open
                cout << "Pick column" << endl; cin >> col; // get spot
                cout << "Pick row" << endl; cin >> row;
                cout << "Pick level" << endl; cin >> lvl;
            } while (tboard.checkSpot(col, row, lvl) == 0);
            tboard.checkSpot(col, row, lvl); // check spot
            tboard.printBoard(); // print board
            tboard.checkWin(); // check for win
            tboard.turn = 1; // switch turn
            tboard.flipActive(); // switch active
        }
        else if (tboard.turn == 1){ // if it is computer's turn
            cout << "Computer's turn" << endl;
            srand(time(0)); // seed random number generator
            int col = (rand() % 3) + 1; // random spot
            int row = (rand() % 3) + 1;
            int lvl = (rand() % 3) + 1;
            do { // keep getting new spot until spot is open
                col = (rand() % 3) + 1;
                row = (rand() % 3) + 1;
                lvl = (rand() % 3) + 1;
            } while (tboard.checkSpot(col, row, lvl) == 0);
            tboard.printBoard(); // print board
            tboard.checkWin(); // check for win
            tboard.turn = 0; // switch turn
            tboard.flipActive(); // switch active
        }
    }
}
// Override base class functions
void game3d::checkWin(){
    // check for win
    for (int j = 0; j < 3; j++){ // check for wins on each level but only inside that level
        for (int i = 0; i < 3; i++){ // check rows
            if ((board[i][0][j] == 'X' || board[i][0][j] == 'O') && board[i][0][j] == board[i][1][j] && board[i][1][j] == board[i][2][j]){
                whoWon();
            }
        }
        for (int i = 0; i < 3; i++){ // check colums
            if ((board[0][i][j] == 'X' || board[0][i][j] == 'O') && board[0][i][j] == board[1][i][j] && board[1][i][j] == board[2][i][j]){
                whoWon();
            }
        }
        if ((board[0][0][j] == 'X' || board[0][0][j] == 'O') && board[0][0][j] == board[1][1][j] && board[1][1][j] == board[2][2][j]){ // check diag 1
            whoWon(); // check who won
        }
        else if ((board[2][0][j] == 'X' || board[2][0][j] == 'O') && board[2][0][j] == board[1][1][j] && board[1][1][j] == board[0][2][j]){ // check daig 2
            whoWon(); // check who won
        }
    }
    for (int k = 0; k < 3; k++) { // check for stacks of x or o
        for (int i = 0; i < 3; i++){
           if ((board[i][k][0] == 'X' || board[i][k][0] == 'O') && board[i][k][0] == board[i][k][1] && board[i][k][1] == board[i][k][2]){
                whoWon();
            } 
        }
    }
    for (int i = 0; i < 3; i++){  
        if ((board[i][0][0] == 'X' || board[i][0][0] == 'O') && board[i][0][0] == board[i][1][1] && board[i][1][1] == board[i][2][2]){ // top row to bottom row across levels
            whoWon();
        }
    }
    for (int i = 0; i < 3; i++){ 
        if ((board[i][2][0] == 'X' || board[i][2][0] == 'O') && board[i][2][0] == board[i][1][1] && board[i][1][1] == board[i][0][2]){ // bottom row to top row across levels
            whoWon();
        }
    }
    for (int i = 0; i < 3; i++){ 
        if ((board[0][i][0] == 'X' || board[0][i][0] == 'O') && board[0][i][0] == board[1][i][1] && board[1][i][1] == board[2][i][2]){ // left column to right column across levels
            whoWon();
        }
    }
    for (int i = 0; i < 3; i++){ 
        if ((board[2][i][0] == 'X' || board[2][i][0] == 'O') && board[2][i][0] == board[1][i][1] && board[1][i][1] == board[0][i][2]){ // right column to left column across levels
            whoWon();
        }
    }
    if ((board[0][0][0] == 'X' || board[0][0][0] == 'O') && board[0][0][0] == board[1][1][1] && board[1][1][1] == board[2][2][2]){ // top left to bottom right
        whoWon();
    }
    if ((board[0][0][2] == 'X' || board[0][0][2] == 'O') && board[0][0][2] == board[1][1][1] && board[1][1][1] == board[2][2][0]){ // top bottom right to bottom top left
        whoWon(); 
    }
    if ((board[2][0][0] == 'X' || board[2][0][0] == 'O') && board[2][0][0] == board[1][1][1] && board[1][1][1] == board[0][2][2]){ // top right to bottom left
        whoWon();
    }
    if ((board[2][0][2] == 'X' || board[2][0][2] == 'O') && board[2][0][2] == board[1][1][1] && board[1][1][1] == board[0][2][0]){ // top left to bottom right
        whoWon();
    }
}
int game3d::checkSpot(int col, int row, int lvl){
    if (board[col-1][row-1][lvl-1] != ' '){
        //cout << "Spot is taken" << endl;
        //cout << col << " " << row << endl;
        return 0;
    } else {
        board[col-1][row-1][lvl-1] = active;
        return 1;
    }
}
void game3d::clearBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                board[i][j][k] = ' ';
            }
        }
    }
}
void game3d::printBoard(){
    for (int k = 0; k < 3; k++){
        cout << endl << "  1 2 3" << endl;
        for(int i = 0; i < 3; i++){
            cout << i+1 << " ";
            for(int j = 0; j < 3; j++){
                cout << board[j][i][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
// Base class functions
void game::whoWon(){
    if (turn == 0){ // if active is winning
            cout << "Player wins!" << endl;
            done = 1; // game is done
        }
    else if (turn == 1){ // if active is not winning
        cout << "Computer wins!" << endl;
        done = 1; // game is done
    }
}
void game::checkWin(){
    // check for win
    for (int i = 0; i < 3; i++){ // check rows
        if ((board[i][0] == 'X' || board[i][0] == 'O') && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            whoWon();
        }
    }
    for (int i = 0; i < 3; i++){ // check colums
        if ((board[0][i] == 'X' || board[0][i] == 'O') && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            whoWon();
        }
    }
    if ((board[0][0] == 'X' || board[0][0] == 'O') && board[0][0] == board[1][1] && board[1][1] == board[2][2]){ // check diag 1
        whoWon(); // check who won
    }
    else if ((board[2][0] == 'X' || board[2][0] == 'O') && board[2][0] == board[1][1] && board[1][1] == board[0][2]){ // check column 1
        whoWon(); // check who won
    }
}
void game::flipActive(){ // function to change active
    if (active == 'X'){ // if active is x
        active = 'O'; // change to o
    }
    else if (active == 'O'){ // if active is o
        active = 'X'; // change to x
    }
}
int game::checkSpot(int col, int row){
    if (board[col-1][row-1] != ' '){
        //cout << "Spot is taken" << endl;
        //cout << col << " " << row << endl;
        return 0;
    } else {
        board[col -1][row -1] = active;
        return 1;
    }
}
void game::clearBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}
void game::printBoard(){
    cout << endl << "  1 2 3" << endl;
    for(int i = 0; i < 3; i++){
        cout << i+1 << " ";
        for(int j = 0; j < 3; j++){
            cout << board[j][i] << " ";
        }
        cout << endl;
    }
}
void game::first(){
    srand(time(0));
    turn = rand() % 2;
    if(turn == 0){
        cout << "Player goes first" << endl << "You are X" << endl;;
    }
    else{
        cout << "Computer goes first" << endl << "You are O" << endl;
    }
    
}
