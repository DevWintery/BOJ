# 문제
어떤 정수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 그 수를 제곱ㄴㄴ수라고 한다. 제곱수는 정수의 제곱이다. min과 max가 주어지면, min보다 크거나 같고, max보다 작거나 같은 제곱ㄴㄴ수가 몇 개 있는지 출력한다.

# 입력
첫째 줄에 두 정수 min과 max가 주어진다.

# 출력
첫째 줄에 min보다 크거나 같고, max보다 작거나 같은 제곱ㄴㄴ수의 개수를 출력한다.

# 제한
1 ≤ min ≤ 1,000,000,000,000
min ≤ max ≤ min + 1,000,000

# 문제 풀이
입력값의 범위가 매우 크다. 유의해야 한다.

에라토스테네스의 체라는 고전 알고리즘이 존재한다. 이는 소수를 찾기 위한것인데

N이 주어졌을때 2부터 N까지의 소수를 찾는 알고리즘이다.

에라토스테네스의 체를 이용하여 현재 범위에서 최소 제곱수를 구한뒤 그 제곱수의 배수를 모두 지우고, 그 다음 제곱수의 배수를 모두 지우고를 반복하여 제곱ㄴㄴ수를 찾을 수 있게된다.