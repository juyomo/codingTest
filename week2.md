코딩 테스트 합격자 되기 C++ - 2주차 (BFS)
===

# 개념 문제

## 1.

_BFS(너비 우선 탐색) 알고리즘의 작동 원리를 설명하고, 어떤 자료구조를 사용하는지, 그리고 그 이유는 무엇인지 설명해주세요._

BFS uses a queue to keep track of the next nodes to visit. We start at a node, and then add its neighbors to the queue. Then, when we pop out elements from the queue, because of the FIFO nature, we end up traversing the graph from nearest to farthest.

## 2.

_BFS와 DFS(깊이 우선 탐색)의 차이점은 무엇이며, 각각 어느 종류의 문제에 더 적합한지 예시를 들어 설명해주세요._

DFS goes down one path and doesn't come back until that path is no longer traversable. It's like finishing one dish completely and then trying the next dish.

BFS, on the other hand, you taste each dish bit by bit. 

DFS allows the use of recursion. Also think backtracking. Also, exploring every possibility.

BFS is useful when you are looking for the shortest path.

## 3.

_BFS 알고리즘의 시간 복잡도는 O(V+E)인데, 그래프의 형태(예: 밀집 그래프 vs. 희소 그래프)가 실재 수행시간에 어떤 영향을 미칠 수 있을지 설명해주세요._

If you have a 밀집 그래프, you have more edges for the same number of nodes, so the time complexity goes up. Might be more than O(V), O(V^2) worst case.

희소 그래프 has fewer edges for the same number of nodes, so O(V+E) is low. (e.g. tree is O(V) because E = V-1.)

# 실전 문제

## Q1. 너비 우선 탐색 순회(몸풀기 문제 37번)

## Q2. 게임 맵 최단거리

[Link to Problem](https://school.programmers.co.kr/learn/courses/30/lessons/1844)

[Attempt 1.](week2_q2_attempt1.cpp)

효율성 테스트 1만 시간초과.

## Q3. 경주로 건설

[Link to Problem](https://school.programmers.co.kr/learn/courses/30/lessons/67259)

[Attempt 1.](week2_q3_attempt1.cpp)

테케 #4 틀림.
