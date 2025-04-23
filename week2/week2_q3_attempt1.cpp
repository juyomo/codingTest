// 테스트케이스 1,2,3 만 통과.

#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

const int drs[] = {-1, 0, 0, 1};
const int dcs[] = {0, -1, 1, 0};
const char dirs[] = {'U', 'L', 'R', 'D'};
const char kStartingDir = ' ';

class Node {
    public:
    int r;
    int c;
    char dir;
    int cost;
    
    Node(int _r, int _c, int _dir, int _cost) :
        r(_r), c(_c), dir(_dir), cost(_cost) {}
    

    void debugPrint() const {
        cout << r << " " << c << " " << dir << " " << cost << endl;
    }
    
    bool isAtEnd(int height, int width) const {
        return (r == height - 1 && c == width - 1);
    }
    
    void getNeighbors(int height, int width, const vector<vector<int>>& board, vector<Node>& neighbors) const {
        for (int i = 0; i < 4; i++) {
            int nr = r + drs[i];
            int nc = c + dcs[i];
            
            if (nr >= 0 && nc >= 0 && nr < height && nc < width
               && board[nr][nc] == 0) {
                char ndir = dirs[i];
                int newCost = cost + 100;
                if (dir != kStartingDir && ndir != dir) {
                    newCost += 500;
                }
                Node n(nr, nc, ndir, newCost);
                neighbors.push_back(n);
            }
        }
    }
};

int solution(vector<vector<int>> board) {
    const int kVisitedConst = -1;
    const int height = board.size();
    const int width = board[0].size();
    
    Node start(0, 0, ' ', 0);
    
    queue<Node> tovisit;
    tovisit.push(start);
    
    int minCost = INT_MAX;
    
    while (!tovisit.empty()) {
        const Node& curr = tovisit.front();
        tovisit.pop();
        board[curr.r][curr.c] = kVisitedConst;
        curr.debugPrint();
        
        if (curr.isAtEnd(height, width)) {
            if (curr.cost < minCost) {
                minCost = curr.cost;
            }
        } else {
            vector<Node> neighbors;
            curr.getNeighbors(height, width, board, neighbors);
            for (const auto& ngh : neighbors) {
                tovisit.push(ngh);
            }
        }
    }
    
    return minCost;
}
