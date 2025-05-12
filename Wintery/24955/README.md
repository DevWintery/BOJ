# Baekjoon Problem 24955 
 
## Problem 
[Problem Link](https://www.acmicpc.net/problem/24955) 

## 문제 해설
그래프 탐색 문제이다.

목표를 탐색하는 문제이기 때문에 DFS보단 BFS를 선택하는게 속도에 더 유리하다.

x로 부터 y로 가는 과정 자체는 간단하나 숫자를 이어붙히는 과정이 추가 된다.

처음에는 귀찮아서 문자열로 이어 붙혔으나 long long으로 변환하는 과정에서 out_of_range가 나 처음 생각했던 방법인 concatenate 함수로 이용해서 숫자를 이어 붙혓다.

MOD는 (a%n + b%n) % n = (a+b)%n 과같은 성질이 존재하기때문에 계속해서 Mod 연산으로 값을 작게 유지해야한다.
이때 a와 b는 이미 Mod 연산이된 값이 들어오기때문에 (정확히는 a는 Mod 연산된 값, b는 Mod가 필요없는 값) 굳이 Mod 연산을 하지 않아도된다.