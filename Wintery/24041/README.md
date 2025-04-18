# Baekjoon Problem 24041 
 
## Problem 
[Problem Link](https://www.acmicpc.net/problem/24041) 

## 문제 풀이

x일이 지났을때 현재 세균의 수가 G를 넘지않는지를 묻는 문제이다.

x의 범위가 매우 크기때문에 이분 탐색으로 x의 범위를 줄여나갈 수 있다.

이때 K개 만큼 음식을 제외하는것은 우선순위 큐를 사용하여 가장 많은 세균을 가진 음식을 K개 제거하는것으로 구현하였다.
