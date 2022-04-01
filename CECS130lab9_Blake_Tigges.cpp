/*
Lab 9 - tic tac toe    
3/30/2022
Section 1A
Blake Tigges
*/

#include <iostream>
using namespace std;
class game{  
    public:
        void clearBoard(); // function to clear board
        void printBoard(); // function to print board
        void checkSpot(char, int); // function to check spot
    private:
        char board[3][3]; // 3x3 array for board
};

int main(){
    cout << "Tic Tac Toe" << endl;
    game tboard; // create board object
    tboard.clearBoard(); // clear board
    tboard.printBoard(); // print board
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