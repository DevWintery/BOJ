# Baekjoon Problem 1120 
 
## Problem 
[Problem Link](https://www.acmicpc.net/problem/1120) 

## 문제 해결
A의 앞에 아무 알파벳을 추가한다.

A의 뒤에 아무 알파벳을 추가한다.

이 두가지 규칙을 적용하는 방법은 아래와 같다.

abc

abcdef 가 있을때

```
abcdef
abc
```
```
abcdef
 abc
```
```
abcdef
  abc
```
```
abcdef
   abc
```

이런식으로 A의 스트링을 하나씩 미뤄가며 서로 다른지 검사를 진행하는것이다.

이는 abc 앞에 혹은 뒤에 B의 스트링이 붙는것과 동일한 효과를 가진다.

문제를 풀때는 find로 하려다가 결국 못찾고 인터넷에 검색해봤다.... 이러한 아이디어를 떠올리는건 어떻게 공부해야하는걸까..