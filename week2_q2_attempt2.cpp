// https://school.programmers.co.kr/learn/courses/30/lessons/1844
// 게임 맵 최단거리 attempt 2.

// TC is same, but optimized.. now it works!

#include <vector>
#include <limits.h>
#include <queue>
#include <iostream>
using namespace std;

const int dr[] = {1, 0, 0, -1};
const int dc[] = {0, 1, -1, 0};

struct location {
    int r;
    int c;
    int distance;
    
    location() {}
    location(int _r, int _c, int _dist) {
        r = _r;
        c = _c;
        distance = _dist;
    }
};

int solution(vector<vector<int>> map) {
    int height = map.size();
    int width = map[0].size();
    
    queue<location> tovisit;
    location curr(height - 1, width - 1, 1);
    tovisit.push(curr);
    map[curr.r][curr.c] = -1;
    
    while (!tovisit.empty()) {
        curr = tovisit.front();
        tovisit.pop();
        int r = curr.r;
        int c = curr.c;
        
        int newDist = curr.distance + 1;
        for (int i = 0; i < 4; i++) {
            int lr = r + dr[i];
            int lc = c + dc[i];
            if (lr == 0 && lc == 0) {
                return newDist;
            }
            if (lr >= 0 && lr < height && lc >= 0 && lc < width && map[lr][lc] == 1) {
                location l(lr, lc, newDist);
                tovisit.push(l);
                map[lr][lc] = -1;
            }
        }
    }
    return -1;
}
