코딩 테스트 합격자 되기 C++ - 1주차
---

# 개념 문제

1. DFS 를 구현하는 대표적인 두 가지 방법은 재귀 호출을 이용하는 것과 명시적인 스택 (Stack) 자료구조를 사용하는 것입니다. 각 구현 방식의 장단점을 비교 설명해주세요.

2. 방향그래프 (Directed Graph) 에서 사이클 (Cycle) 존재 여부를 판별하기 위해 DFS 를 어떻게 활용할 수 있는지 구체적인 알고리즘을 설명해주세요.

3. 재귀를 활용한 DFS 에서 가장 최근의 노드로 돌아가는 백트래킹 동작이 어떤 방식으로 동작하는지 하나의 예를 들어 설명해주세요.



# 풀어볼 문제

[네트워크](https://school.programmers.co.kr/learn/courses/30/lessons/43162)

```c++
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
```

양과 늑대 (프로그래머스)


전력망을 둘로 나누기


양궁 대회

