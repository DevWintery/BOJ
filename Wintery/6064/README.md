# Baekjoon Problem 6064 
 
## Problem 
[Problem Link](https://www.acmicpc.net/problem/6064) 

## 문제 풀이
[중국인의 나머지 정리](https://youtu.be/5vQsSBK60Vk?si=I2ECZPdQwu9b_tSB)
[중국인의 나머지 정리 n = 2 일때](https://youtu.be/nfBcUPJziio?si=-uGFjVXSrUtERy7D)

문제를 보고 모르겠어서 알고리즘 분류를 펼처보니 중국인의 나머지 정리를 이용하여 문제를 해결할 수 있다고 한다.

모르는 유형이라 유튜브와 위키로 조금 공부를 했는데 전혀 이해하지못했다.

하지만 문제가 유도하는 방법이 무엇인지 알았으므로 아래의 풀이로 해결했다.

문제는

$$k \equiv x \pmod{M}$$
$$k \equiv y \pmod{N}$$

의 k를 를 구하는 문제이다. 즉 k를 M으로 나누면 나머지가 x, k를 N으로 나누면 나머지가 y가 되는 해를 찾으면된다.

이를 프로그래밍적으로 해결하면 

1. $x + M, x + 2M, x + 3M ...$은 모두 M으로 나누었을때 나머지가 x다.
2. $x + M, x + 2M ...$으로 k의 후보를 생성하고 해당 k를 N으로 나누면 나머지가 y인지 확인했을때 y가 맞다면 정답이다.

만약 LCM(최소공배수) 까지 확인이 불가능하다면 이는 불가능한 해이다.

### 왜 최소 공배수까지만 하는가
$$k \equiv x \pmod{M}$$
$$k \equiv y \pmod{N}$$

여기서

$$LCM(M, N) + k \equiv x \pmod{M}$$
$$LCM(M, N) + k \equiv y \pmod{N}$$

를 해도 식은 성립한다 왜냐하면 LCM(M, N)도 결국 M의 배수이기 때문이다.

즉 k가 해라면 $k + n * LCM(M, N)$ 도 해이기때문에 LCM 범위내에서 해를 찾지못한다면 더 큰 범위에서도 해는 존재하지 않게된다.
