#include <iostream>
using namespace std;

vector<vector<int>> rotateClockwise(const vector<vector<int>>& A) {
    int height = A.size();
    if (height == 0) {
        return {};
    }

    int width = A[0].size();
    if (width == 0) {
        return {}; // bleh
    }

    vector<vector<int>> res(width, vector<int>(height));

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            res[i][j] = A[height - j - 1][i];
        }
    }

    return res;
}

void printMatrix(const vector<vector<int>>& A) {
    for (int i = 0; i < A.size(); i++) {
        const vector<int>& row = A[i];
        for (int j = 0; j < row.size(); j++) {
            cout << row[j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> A = {
        {1, 2, 3, 10},
        {4, 5, 6, 11},
        {7, 8, 9, 12}
    };

    cout << "Original Matrix: " << endl;
    printMatrix(A);

    vector<vector<int>> B = rotateClockwise(A);

    cout << "Matrix rotated clockwise: " << endl;
    printMatrix(B);
}