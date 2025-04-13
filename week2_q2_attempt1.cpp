// 시간초과 남.

#include <vector>
#include <limits.h>
#include <queue>
#include <iostream>
using namespace std;

struct location {
    int r;
    int c;
    int distance;
    
    location(int _r, int _c, int _dist) {
        r = _r;
        c = _c;
        distance = _dist;
    }
    
    vector<location> getNeighbors() {
        vector<location> nghbrs;
        /*
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};*/
        nghbrs.push_back(location(r, c+1, distance+1));
        nghbrs.push_back(location(r, c-1, distance+1));
        nghbrs.push_back(location(r+1, c, distance+1));
        nghbrs.push_back(location(r-1, c, distance+1));
        return nghbrs;
    }
    
    static bool checkInBox(int r, int c, int height, int width) {
        return (r >= 0 && r < height && c >= 0 && c < width);
    }
};

int findMin(int a, int b, int c, int d) {
    int res = a;
    if (b < res) { res = b; }
    if (c < res) { res = c; }
    if (d < res) { res = d; }
    return res;
}

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
        
        for (const location& l : curr.getNeighbors()) {
            if (l.r == 0 && l.c == 0) {
                return l.distance;
            }
            if (l.checkInBox(l.r, l.c, height, width) && map[l.r][l.c] == 1) {
                tovisit.push(l);
                map[l.r][l.c] = -1;
            }
        }
    }
    return -1;
}
