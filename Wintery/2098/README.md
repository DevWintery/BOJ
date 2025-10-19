# Baekjoon Problem 2098 
 
## Problem 
[Problem Link](https://www.acmicpc.net/problem/2098) 

## 문제 풀이
비트마스크로 현재 간 위치와 안간 위치를 구분한다.

예를 들면 0101 은 1번 도시와 3번 도시를 방문 그 외 도시는 방문하지않았다.

각 모든 도시를 방문한뒤에 다시 돌아가는 코스트를 return 받아 결과를 저장한다.

이미 계산한 결과를 DP에 저장해 연산 횟수를 줄인다.