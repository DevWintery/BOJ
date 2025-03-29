# 문제
평면상에 세 개의 점이 주어지면, 그 세 점으로 이루어지는 삼각형은 유일하게 결정된다. 또는, 삼각형이 이루어지지 않기도 한다. 세 점의 좌표가 주어졌을 때 다음에 따라 이 삼각형의 종류를 판단하는 프로그램을 작성하시오.

세 점이 일직선 위에 있으면 - ‘삼각형이 아님’  출력할 때는 X
세 변의 길이가 같으면 - ‘정삼각형’ 출력할 때는 JungTriangle
두 변의 길이가 같으면
{
    가장 큰 각이 90°보다 크면 - ‘둔각이등변삼각형’ 출력할 때는 Dunkak2Triangle
    가장 큰 각이 90°이면 - ‘직각이등변삼각형’ 출력할 때는 Jikkak2Triangle
    가장 큰 각이 90°보다 작으면 - ‘예각이등변삼각형’ 출력할 때는 Yeahkak2Triangle
}

세 변의 길이가 모두 다르면
{
    가장 큰 각이 90°보다 크면 - ‘둔각삼각형’ 출혁할 때는 DunkakTriangle
    가장 큰 각이 90°이면 - ‘직각삼각형’ 출력할 때는 JikkakTriangle
    가장 큰 각이 90°보다 작으면 - ‘예각삼각형’ 출력할 때는 YeahkakTriangle
}

# 입력
첫째 줄부터 셋째 줄까지 삼각형을 이루는 점의 x좌표와 y좌표가 빈칸을 사이에 두고 주어진다. 입력되는 수는 절댓값이 10,000을 넘지 않는 정수이다. 입력으로 주어지는 세 좌표는 중복되지 않는다.

# 출력
위의 경우에 따라 삼각형의 종류가 무엇인지 출력한다.

------------------------------------------------------
# 오답풀이
- 기존 코드 : 내적만 사용하여 두 벡터가 이루는 각의 방향성을 판단할 수 없다.
```cpp
double GetAngle(pair<int, int> Vector_1, pair<int, int> Vector_2)
{
    double Dot = DotProduct(Vector_1, Vector_2);
    double Cos = Dot / ((Magnitude(Vector_1) * Magnitude(Vector_2)));
    Cos = clamp(Cos, -1.0, 1.0);
    return acos(Cos) * (double)(180.f / PI);
}

// 가장 큰 각도 구하기
double LargestDotProduct()
{
    pair<int, int> AB = {(B.first - A.first), (B.second - A.second)};
    pair<int, int> AC = {(C.first - A.first), (C.second - A.second)};
    pair<int, int> BC = {(C.first - B.first), (C.second - B.second)};

    return max(max(GetAngle(AB, AC), GetAngle(AB, BC)), GetAngle(AC, BC));
}

```