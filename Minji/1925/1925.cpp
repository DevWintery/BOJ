#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define Initialize                     \
    ios_base ::sync_with_stdio(false); \
    cin.tie(NULL);                     \
    cout.tie(NULL);

#define TRIANGLE_SIDE_COUNT (3)

pair<int, int> A;
pair<int, int> B;
pair<int, int> C;

bool IsStraightLine()
{
    // // AB 기울기
    // float AB = ((B.first == A.first)) ? 0 : (B.second - A.second) / (B.first - A.first);
    // float AC = ((C.first == A.first)) ? 0 : (C.second - A.second) / (C.first - A.first);
    // return (AB == AC);

    return ((B.first - A.first) * (C.second - A.second)) == ((B.second - A.second) * (C.first - A.first));
}

// 피타고라스 공식을 이용한 빗변 길이 체크
void CheckPythagoras()
{
    vector<float> LengthList(TRIANGLE_SIDE_COUNT);
    
    // AB
    LengthList[0] = pow(B.first - A.first, 2) + pow(B.second - A.second, 2);
    // AC
    LengthList[1] = pow(C.first - A.first, 2) + pow(C.second - A.second, 2);
    // BC
    LengthList[2] = pow(C.first - B.first, 2) + pow(C.second - B.second, 2);

    if((LengthList[0] == LengthList[1])
        && (LengthList[1] == LengthList[2]))
    {
        cout << "JungTriangle";
        return;
    }

    sort(LengthList.begin(), LengthList.end());

    // 빗변 (C^2)
    float LongestSide = LengthList[2];
    // A^2 + B^2
    float RemainderSide = LengthList[0] + LengthList[1];

    // 직각 삼각형
    if (LongestSide == RemainderSide)
    {
        if((LengthList[0] == LengthList[1]))
        {
            cout << "Jikkak2Triangle";
        }
        else
        {
            cout << "JikkakTriangle";
        }
    }
    // 둔각 삼각형
    else if(LongestSide > RemainderSide)
    {
        if((LengthList[0] == LengthList[1]))
        {
            cout << "Dunkak2Triangle";
        }
        else
        {
            cout << "DunkakTriangle";
        }
    }
    else
    {
        if((LengthList[0] == LengthList[1]) || (LengthList[1] == LengthList[2]))
        {
            cout << "Yeahkak2Triangle";
        } 
        else
        {
            cout << "YeahkakTriangle";
        }
    }
}

int main()
{
    Initialize

    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> C.first >> C.second;

    if (IsStraightLine())
    {
        cout << "X";
        return 0;
    }

    CheckPythagoras();
}