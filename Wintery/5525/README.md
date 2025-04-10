# Baekjoon Problem 5525 
 
## Problem 
[Problem Link](https://www.acmicpc.net/problem/5525) 

## 문제풀이
브루트포스하게 풀면 시간초과가 나며 50점밖에 맞지못한다.

O(NM)의 시간복잡도를 O(M)으로 줄이기 위해서는 IOI가 반복되어서 나오는 구조에 집중해야한다.

Pn은 IOI가 N번 반복된 문자열이기때문에 IOI가 나온 횟수를 기록하여 N과 같다면 정답을 증가시켰다.

이로써 O(M)의 시간복잡도로 문제를 해결할 수 있다.

## 주의할 점
정확히는 첫 IOI 다음은 OI 가 붙는 형태이기 때문에 반복문을 잘 작성하여야한다.