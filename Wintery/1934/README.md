# Baekjoon Problem 1934 
 
## Problem 
[Problem Link](https://www.acmicpc.net/problem/1934) 

## 문제풀이
유클리드 호제법을 이용한 lcm와 gcd로 쉽게 문제를 풀수있다.

## 유클리드 호제법
a, b가 있고 a > b일때 a % b = r 이라고 한다면 a, b의 최대공약수는 b, r의 최대공약수와 같다.

이러한 성질에 따라 b % r = r' 을 구하는 과정을 반복해 나머지가 0이 나올때 나누는 수가 최대 공약수임을 알 수 있다.

lcm(a,b) * gcd(a, b) = a * b 의 성질을 이용해 gcd를 구한뒤 lcm(a,b) = (a * b) / gcd(a, b)

곱하기를 먼저할경우 오버플로우 유의를 하여 a * (b / gcd(a, b))로 변형할 수 있다.