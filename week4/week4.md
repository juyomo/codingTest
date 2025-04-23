코딩 테스트 합격자 되기 C++ - 4주차 (시뮬레이션)
===

# 개념 문제

## 1. 

_N×N 크기의 2차원 정수 행렬을 시계 방향으로 90도 회전시키는 기능을 구현한다고 가정해 봅시다. 각 행렬의 원소가 회전 후 어떤 새로운 위치로 이동해야 할지에 대한 좌표 변환 규칙 아이디어를 시뮬레이션하여 설명해주세요. 예를 들어, 원래 행렬의 (r,c) 위치에 있던 원소는 회전 후 어떤 (r′,c′) 위치로 이동해야 할까요? 이 규칙을 일반화하여 설명하고, 이를 구현하기 위한 주요 단계를 논리적으로 나열해주세요._

Let h be the height of the original matrix.

A[r][c] goes to B[c][h-r-1].

* r′ = c
* c′ = h - r - 1 (0 based)

```c++
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            res[i][j] = A[height - j - 1][i];
        }
    }
```

See [here](matrix_rotation_clockwise.cpp) for full soln.

<details>
  <summary>Huh??? Matrices!!! Everywhere!!!</summary>
This is sooo weird? This is the exact same homework question I gave my student for rotating a tetrinomino for implementing a tetris game, like on Tuesday! And we were talking about matrix questions with kwangkyo-jukjeon study? And also with haco-leetcode study, matrices came up for calculating fib for large n (백준 피보나치 6)? What is this -- a week of matrices??!?!?!? From 4 diff places??!??!??!?!
</details>

## 2.

_2차원 평면 상에서 현재 위치 (x,y)에서 시작하여 '동', '서', '남', '북' 방향으로 특정 거리만큼 이동하는 명령들을 처리하는 기능을 구현한다고 가정해 봅시다. 각 이동 명령이 주어졌을 때, 현재 좌표를 어떻게 갱신해야 할지에 대한 좌표 갱신 아이디어를 시뮬레이션하여 설명해주세요. 여러 개의 이동 명령이 순차적으로 주어졌을 때, 최종 도착 좌표를 계산하기 위한 논리적인 처리 흐름을 설명하고, 이를 구현하기 위한 핵심적인 변수 관리 방안에 대한 아이디어를 제시해주세요._

I am lazy. See [here](q2_character_coordinates.cpp).

# 실전 문제

## 이진 변환 반복하기

[Q](https://school.programmers.co.kr/learn/courses/30/lessons/70129) 프로그래머스 문제 링크

[A](q1_binary_transformation.cpp) 내 풀이

## 캐릭터의 좌표

[Q](https://school.programmers.co.kr/learn/courses/30/lessons/120861) 프로그래머스 문제 링크

[A](q2_character_coordinates.cpp) 내 풀이
