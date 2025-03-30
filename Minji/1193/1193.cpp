#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

int main()
{
    Initialize

    int Sequence = 0;
    cin >> Sequence;

    int LineNum = 1;
    while(Sequence > LineNum)
    {
        Sequence -= LineNum;
        LineNum++;
    }

    // 짝수 - 분모 증가
    if (LineNum % 2 == 0)
    {
        cout << Sequence << "/" << LineNum + 1 - Sequence;
    }   
    // 홀수 - 분자 증가
    else
    {
        cout << LineNum + 1 - Sequence << "/" << Sequence;
    }
}