// https://school.programmers.co.kr/learn/courses/30/lessons/87946

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void recur(const vector<vector<int>>& dungeons, vector<int>& indexLeft, int& currMax, int hp, int dungeonsExplored) {
    if (dungeonsExplored > currMax) {
        currMax = dungeonsExplored;
    }
    
    for (int i = 0; i < indexLeft.size(); i++) {
        if (indexLeft[i] && hp >= dungeons[i][0]) {
            indexLeft[i] = false;
            recur(dungeons, indexLeft, currMax, hp - dungeons[i][1], dungeonsExplored+1);
            indexLeft[i] = true;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<int> indexLeft(dungeons.size(), true);
    
    int currMax = 0;
    recur(dungeons, indexLeft, currMax, k, 0);
    return currMax;
}
