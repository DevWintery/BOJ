# Baekjoon Problem 9019 
 
## Problem 
[Problem Link](https://www.acmicpc.net/problem/9019) 

## 회고록
처음에 그래프를 생각하기는 했다. 왜냐하면 D를 했을때 S를 했을때 R을 했을때 L을 했을때로 분기가 갈라지기 때문에 그래프로 표현할 수 있다고 생각했다.

하지만 구현이 어려워서 결국 검색의 힘을 빌렸다. 그래프 접근 방식은 맞았지만 visit의 인덱스를 num으로 한다는 그런 기초적인 생각을 놓쳐서 구현에 어려움을 겪었다.

num을 인덱스로 하고 BFS를 돌려 모든 number를 다 돌아보면 된다.