# Baekjoon Problem 11286 
 
## Problem 
[Problem Link](https://www.acmicpc.net/problem/11286) 

## 문제 풀이
우선순위 큐로 문제를 해결할 수 있다.

priority_queue는 정렬 상태를 less<> grater<> 로 정의할 수 있는데 이를 사용자 정의 구조체로 변경할 수 있다.

큐에 값을 넣을때 무조건 절댓값으로 집어넣고 이 값이 음수에 해당하는지 isNagetive를 넣어줬다.

정렬 상태를 정의할때는 기본적으로 greater로 정의하면 절댓값 순서로 나오게되고 만약 값이 같다면 Right의 isNagetive를 반환하게 되면 음수가 맨 앞으로 나오게된다.