# Baekjoon Problem 15666 
 
## Problem 
[Problem Link](https://www.acmicpc.net/problem/15666) 

## 문제풀이
백트래킹의 스탠다드 알고리즘 문제이다.

비내림차순 조건을 구현하는 방법은 이전에 선택한 숫자보다 작은 숫자를 선택하지 않는것이다.

정렬을 했기때문에 현재 인덱스 부터 다시 시작하면 자동으로 조건이 유지된다.

여기서 중복을 제거하는게 관건인데 입력에 중복된 숫자가 있을 경우 같은 레벨의 재귀에서 같은 숫자를 두번 처리 하면 중복된 수열이 생성된다.

이를 방지하기위해 각 재귀의 레벨에서 처리한 숫자를 기록한뒤, 현재 숫자가 이전에 처리한 숫자와 같으면 스킵 하면된다.