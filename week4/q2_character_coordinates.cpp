// Author: Juyoung Moon
// https://school.programmers.co.kr/learn/courses/30/lessons/120861

// 캐릭터의 좌표

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> dx = {
    {"right", 1},
    {"left", -1},
    {"down", 0},
    {"up", 0}
};
unordered_map<string, int> dy = {
    {"right", 0},
    {"left", 0},
    {"down", -1},
    {"up", 1}
};

void processDir(const string& dir, const int maxX, const int maxY, vector<int>& curr) {
    int newX = curr[0] + dx[dir];
    int newY = curr[1] + dy[dir];
    
    // only update if in bounds
    if (abs(newX) <= maxX && abs(newY) <= maxY) {
        curr[0] = newX;
        curr[1] = newY;
    }
}

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> curr = {0, 0};
    int maxX = board[0] / 2;
    int maxY = board[1] / 2;
    
    for (int i = 0; i < keyinput.size(); i++) {
        processDir(keyinput[i], maxX, maxY, curr);
    }
    
    return curr;
}
