// https://school.programmers.co.kr/learn/courses/30/lessons/12952

#include <string>
#include <vector>

using namespace std;

bool available(const int n, const vector<vector<int>>& board, int row, int col) {
    // check prev rows
    for (int r = 0; r < row; r++) {
        if (board[r][col] == 1) {
            // col taken!
            return false;
        }
    }
    
    // check diagonals
    for (int r = 0; r < row; r++) {
        int rDelta = abs(r - row);
        int col1 = col + rDelta;
        int col2 = col - rDelta;
        
        if (col1 >= 0 && col1 < n && board[r][col1] == 1) {
            return false;
        }
        if (col2 >= 0 && col2 < n && board[r][col2] == 1) {
            return false;
        }
    }
    
    return true;
}

void recur(const int n, vector<vector<int>>& board, int row, int& poss) {
    if (row == n) {
        poss++;
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (available(n, board, row, col)) {
            board[row][col] = 1;
            recur(n, board, row + 1, poss);
            board[row][col] = 0;
        }
    }    
}

int solution(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    int poss = 0;
    recur(n, board, 0, poss);
    
    return poss;
}
