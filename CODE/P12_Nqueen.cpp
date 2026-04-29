#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Check if safe to place queen
bool isSafe(vector<int>& board, int row, int col, int N){

    for(int i = 0; i < row; i++){

        // same column check
        if(board[i] == col)
            return false;

        // diagonal check
        if(abs(board[i] - col) == abs(i - row))
            return false;
    }

    return true;
}

// Backtracking function
void solveNQ(vector<int>& board, int row, int N, int &count){

    if(row == N){

        count++;

        // print only first solution
        if(count == 1){
            cout << "First Solution:\n";
            for(int i = 0; i < N; i++)
                cout << board[i] + 1 << " ";

            cout << "\n\nBoard:\n";

            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(board[i] == j)
                        cout << "Q ";
                    else
                        cout << ". ";
                }
                cout << endl;
            }
        }

        return;
    }

    for(int col = 0; col < N; col++){
        if(isSafe(board, row, col, N)){
            board[row] = col;
            solveNQ(board, row + 1, N, count);
        }
    }
}

int main(){

    int N = 4;
    vector<int> board(N, -1);
    int count = 0;

    cout << "N = " << N << endl;

    solveNQ(board, 0, N, count);

    cout << "\nTotal Solutions = " << count << endl;

    return 0;
}
