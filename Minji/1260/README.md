# Baekjoon Problem 1260 
 
## Problem 
[Problem Link](https://www.acmicpc.net/problem/1260) 

-----------------------------------------------------------
# 문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

# 입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

# 출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

---------------------------------------------------------
# 풀이
- DFS, BFS의 기본 구현 문제이다.

- 첫 시도 때 틀린 이유는 정렬을 하지 않았기 때문이다.
    - 입력 순서나 vector 내부 저장 순서에 의존하다 보면 DFS/BFS 방문 순서가 예제 기대값과 다르게 나오는 문제가 발생하기 때문에 정렬이 필요했다. 
    - DFS와 BFS 모두에서 번호가 작은 노드를 먼저 방문해야 하기 때문에 이웃 노드 리스트를 구할 때 정렬을 하였다.