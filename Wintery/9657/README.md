# Baekjoon Problem 9657 
 
## Problem 
[Problem Link](https://www.acmicpc.net/problem/9657) 

## 문제 해결
```
1 	1 -> 0				SK
2	2 -> 1 -> 0				CK
3	3 -> 0				SK
4	4 -> 0				SK
5	5 -> 2 -> 1 -> 0			SK
6	6 -> 2 -> 1 -> 0 			SK
7	7 -> 6 -> 2 -> 1 -> 0		CK
8	8 -> 7 -> 6 -> 2 -> 1 -> 0	SK
9	9 -> 8 -> 5 -> 4 -> 0		CK
```

기본적인 상황
```
dp[1] = 1
dp[2] = 2
dp[3] = 1
dp[4] = 1
```

이후 상황
상근이 기준으로 짝수로 된 상황을 선택해야함

```
dp[5] + 1 = dp[1] or dp[4] or dp[2] = 3
dp[6] + 1= dp[5] or dp[3] or dp[2] = 3
dp[7] + 1= dp[6] or dp[4] or dp[3] = 모두 홀수이기때문에 값이 무조건 짝수
dp[8] + 1 = dp[7] or dp[5] or dp[4] = 5
dp[9] + 1 = dp[8] or dp[6] or dp[5] = 모두 홀수이기때문에 값이 무조건 짝수
```

## 검토
굳이 짝수 홀수로 안하고 bool 처럼 true false로 하거나 0, 1같은 플래그 형식으로하는게 나머지 연산이 덜 들어가서 괜찮을듯