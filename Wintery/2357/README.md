# Baekjoon Problem 2357 
 
## Problem 
[Problem Link](https://www.acmicpc.net/problem/2357) 

## 문제 풀이
고정적인 배열에 대해서 쿼리 질문이 많은 경우에는 세그먼트 트리를 사용할 수 있다.

각 부모 노드는 최솟값 최댓값을 가지고있으며 범위를 비교하며 범위에 속한다면 최솟값 최댓값을 반환하면된다.