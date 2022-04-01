/*
Lab 9 - tic tac toe    
3/30/2022
Section 1A
Blake Tigges
*/

#include <iostream>
#include <time.h>
using namespace std;
class game{  
    public:
        void clearBoard(); // function to clear board
        void printBoard(); // function to print board
        void checkSpot(char, int); // function to check spot
        void first(); // function to who goes first randomly
        int turn; // track of turn, 0 = player, 1 = computer
        int done; // is game still playing
    private:
        char board[3][3]; // 3x3 array for board
};

int main(){
    cout << "Tic Tac Toe" << endl;
    game tboard; // create board object
    tboard.clearBoard(); // clear board
    tboard.printBoard(); // print board
    while (tboard.done == 0){ // while game is still playing
        if (tboard.turn == 0){ // if it is player's turn
            cout << "Player's turn" << endl;
            char col; // column
            int row; // row
            cin >> col; // get spot
            cin >> row;
            tboard.checkSpot(col, row); // check spot
            tboard.printBoard(); // print board
            tboard.turn = 1; // switch turn
        }
        else if (tboard.turn == 1){ // if it is computer's turn
            cout << "Computer's turn" << endl;
            srand(time(NULL)); // seed random number generator
            int spot = rand() % 9; // random spot
            tboard.checkSpot('O', spot); // check spot
            tboard.printBoard(); // print board
            tboard.turn = 0; // switch turn
        }
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
    cout << "  A B C" << endl;
    for(int i = 0; i < 3; i++){
        cout << i+1 << " ";
        for(int j = 0; j < 3; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void game::first(){
    srand(time(0));
    turn = rand() % 2;
    if(turn == 0){
        cout << "Player goes first" << endl;
    }
    else{
        cout << "Computer goes first" << endl;
    }
    
}