코딩 테스트 합격자 되기 C++ - 1주차
===

# Preamble, a ramble.

Note to self.
* Get the book!
* Figure out syntax highlighting!
* Fix some ... mediocre code..

I've got a loooong way to go :')

# 개념 문제

## 1.

_DFS 를 구현하는 대표적인 두 가지 방법은 재귀 호출을 이용하는 것과 명시적인 스택 (Stack) 자료구조를 사용하는 것입니다. 각 구현 방식의 장단점을 비교 설명해주세요._

| Recursion | stack |
| --------- | ----- |
| - code is simpler | - code is less intuitive |
| - Function calls get stacked on the stack in memory, so not as ideal for large graphs where searches might go deep. (Stack overflow) | - More suitable for larger graphs. Also allows for more control/manipulation of the stack during the iterative process. |

## 2.

_방향그래프 (Directed Graph) 에서 사이클 (Cycle) 존재 여부를 판별하기 위해 DFS 를 어떻게 활용할 수 있는지 구체적인 알고리즘을 설명해주세요._

- Keep track of visited nodes (e.g. in an unordered_set) and if we come across a node (that is currently in our traversal path) that also belongs to the visited node, we have a cycle!

## 3.

_재귀를 활용한 DFS 에서 가장 최근의 노드로 돌아가는 백트래킹 동작이 어떤 방식으로 동작하는지 하나의 예를 들어 설명해주세요._

- The following is code to get all the subsets of a given array. When we call the recursive function (e.g. `subsetRecur`), it's like creating a child node -- make the next decision. Then when that function returns, we are coming back to the parent node that called the function. 

```
void subsetRecur(int i, const vector<int>& arr, vector<vector<int>>& res, vector<int>& subset) {

    if (i == arr.size()) {
        res.push_back(subset);
        return;
    }
    
    subset.push_back(arr[i]);
    subsetRecur(i+1, arr, res, subset);
    
    subset.pop_back();
    subsetRecur(i+1, arr, res, subset);
}

vector<vector<int> > subsets(vector<int>& arr) {
    vector<int> subset;
    vector<vector<int>> res;
    subsetRecur(0, arr, res, subset);
    return res;
}
```

# 풀어볼 문제

## 깊이 우선 탐색 순회 (몸 풀기 문제)

백준 13023 [Link to Problem](https://www.acmicpc.net/problem/13023)

TODO: Also do it recursively. (Just did it iteratively for now.)

<details>
    <summary>Code</summary>
    
    #include <iostream>
    #include <unordered_map>
    #include <unordered_set>
    #include <stack>
    
    using namespace std;
    
    typedef unordered_set<int> Path;
    
    int main() {
        int n, e;
        cin >> n >> e;
        unordered_map<int, unordered_set<int>> nodes;
        
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a].insert(b);
            nodes[b].insert(a);
        }
        
        for (int startNode = 0; startNode < n; startNode++) {
            stack<pair<int, Path>> tovisit;
            Path path{startNode};
            tovisit.push(make_pair(startNode, path));
    
            while (!tovisit.empty()) {
                pair<int, Path> curr = tovisit.top();
                tovisit.pop();
        
                Path currPath = curr.second;
                currPath.insert(curr.first);
                if (currPath.size() == 5) {
                    cout << 1 << endl;
                    return 0;
                }
    
                for (int neighbor : nodes[curr.first]) {
                    if (currPath.find(neighbor) == currPath.end()) {
                        tovisit.push(make_pair(neighbor, currPath));
                    }
                }
            }
        }
    
        cout << 0 << endl;    
    }
</details>

## 네트워크 (Lv. 3)

[Link to Problem](https://school.programmers.co.kr/learn/courses/30/lessons/43162)

<details>
    <summary>Code</summary>
    
    #include <string>
    #include <vector>
    #include <unordered_set>
    #include <queue>
    
    using namespace std;
    
    int solution(int n, vector<vector<int>> computers) {
        queue<int> checked;
        unordered_set<int> unvisited;
        for (int i = 0; i < n; i++) {
            unvisited.insert(i);
        }
    
        int ans = 0;
        while (unvisited.size() > 0) {
            int randomElem = -1;
    
            for (int n : unvisited) {
                // TODO: Uhm, fix this.
                // Temp way to get a random elem from the map because I was speeding through this..
                randomElem = n;
                break;
            }
    
            checked.push(randomElem);
            unvisited.erase(randomElem);
    
            while (!checked.empty()) {
                int i = checked.front();
                checked.pop();
                for (int j = 0; j < n; j++) {
                    if (i != j && computers[i][j] == 1 && unvisited.find(j) != unvisited.end()) {
                        checked.push(j);
                        unvisited.erase(j);
                    }
                }
            }
            ans++;
        }
        return ans;
    }
</details>

## 양과 늑대 (Lv. 3)

[Link to Problem](https://school.programmers.co.kr/learn/courses/30/lessons/92343)

TODO

## 전력망을 둘로 나누기 (Lv. 2)

[Link to Problem](https://school.programmers.co.kr/learn/courses/30/lessons/86971)

<details>
    <summary>It worked! it's not the most optimal, but out of time. Come back to this.</summary>
    
    #include <string>
    #include <vector>
    #include <queue>
    #include <unordered_set>
    #include <unordered_map>
    #include <cmath>
    
    using namespace std;
    
    int calcMinDiff(int numNodes, const unordered_map<int, vector<int>>& nodes, const vector<int>& edgeToSkip) {
        const int from = edgeToSkip[0];
        const int to = edgeToSkip[1];
        
        queue<int> tovisit;
        unordered_set<int> visited;
        tovisit.push(1);
        visited.insert(1);
        
        while (!tovisit.empty()) {
            int curr = tovisit.front();
            tovisit.pop();
            
            auto it = nodes.find(curr);
            if (it != nodes.end()) {
                const vector<int>& neighbors = it->second;
                for (int n : neighbors) {
                    if (visited.find(n) == visited.end() &&
                       !((from == curr && to == n) || (from == n && to == curr))) {
                        tovisit.push(n);
                        visited.insert(n);
                    }
                }
            }
        }
        
        int res = numNodes - (2 * visited.size());
        return abs(res);
    }
    
    int solution(int numNodes, vector<vector<int>> wires) {
        unordered_map<int, vector<int>> nodes; // node to a list of all of its neighbors
        for (const auto& edge: wires) {
            int from = edge[0];
            int to = edge[1];
            nodes[from].push_back(to);
            nodes[to].push_back(from);
        }
        
        int minDiff = numNodes;
        
        for (int i = 0; i < wires.size(); i++) {
            int tmp = calcMinDiff(numNodes, nodes, wires[i]);
            if (tmp == 0) {
                return 0;
            } else if (numNodes % 2 == 1 && tmp == 1) {
                return 1;
            }
            if (tmp < minDiff) {
                minDiff = tmp;
            }
        }
        
        return minDiff;
    }
</details>

## 양궁 대회 (Lv. 2)

[Link to Problem](https://school.programmers.co.kr/learn/courses/30/lessons/92342)

<details>
    <summary>Attempt 1, which failed quite spectacularly. (Well, it passed for the first two test cases and then.. :P)</summary>
    
    #include <string>
    #include <vector>
    #include <cmath>
    #include <iostream>
    using namespace std;
    
    bool getNextPossibility(int n, vector<int>& arrows, vector<int>& poss) {
        // for each possibility of arrow arrangement
        for (int i = 0; i < poss.size(); i++) {
            poss[i] = 0;
        }
        
        for (int j = 0; j < arrows.size(); j++) {
            int jthArrowAt = arrows[j];
            poss[jthArrowAt]++;
        }
    
        // increment arrow possibility
        int idx = arrows.size() - 1;
        arrows[idx]++;
        while (idx >= 0 && arrows[idx] == 11) {
            arrows[idx] = 0;
            idx--;
            if (idx >= 0) arrows[idx]++;
        }
        
        return idx < 0;
    }
    
    int calcScoreDiff(const vector<int>& other, const vector<int>& mine) {
        int otherSum = 0;
        int mySum = 0;
        
        for (int i = 0; i < other.size(); i++) {
            if (other[i] == 0 && mine[i] == 0) {
                continue;
            }
            
            int currScore = 10 - i;
            if (other[i] >= mine[i]) {
                otherSum += currScore;
            } else {
                mySum += currScore;
            }
        }
        
        int res = mySum - otherSum;
        if (res == 0) {
            return -1;
        }
        return res;
    }
    
    vector<int> solution(int n, vector<int> info) {
        vector<int> arrows(n, 0);
        vector<int> possibility(11, 0);
        vector<int> answer;
        
        int maxScore = -1;
        bool done = false;
        
        while (!done) {
            done = getNextPossibility(n, arrows, possibility);
            int score = calcScoreDiff(info, possibility);
            if (score > maxScore) {
                // todo: equal
                maxScore = score;
                answer = possibility;
            }
        }
        
        if (maxScore <= 0) {
            return {-1};
        } else {
            return answer;
        }
    }
</details>

<details>
    <summary>Attempt 2. TODO</summary>
</details>
