# 문제
두 정수 A와 B를 입력받은 다음, A/B를 출력하는 프로그램을 작성하시오.

# 입력
첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)

# 출력
첫째 줄에 A/B를 출력한다. 실제 정답과 출력값의 절대오차 또는 상대오차가 10^-9 이하이면 정답이다.

---------------------------------------------------------------------------------------------

# 풀이
- 이걸 틀렸다는 것 자체가 굉장히이... 충격적이다...
- 연산을 틀린건 아니고 `fixed`와 `setprecision(9)`의 존재조차 몰랐삼...ㅠ
    - `fixed` : 소수점 고정 형식으로 출력 (fixed-point)
    - `setprecision(9)` : 최대 소수점 9자리까지 출력