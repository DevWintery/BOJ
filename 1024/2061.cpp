#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    // K는 100자리 수까지 표현되므로로
    string K;
    // d의 범위로 인해 소수로 나누는 과정에서 문제가 생길 가능성이 있음음
    long long L;

    cin >> K >> L;

    for(long long Divider = 2; Divider < L; Divider++)
    {
        long long Remainder = 0;
        for (char digit : K) 
        {
            Remainder = (Remainder * 10 + (digit - '0')) % Divider;
        }

        if(Remainder == 0)
        {
            cout << "BAD " << Divider;
            return 0;
        }
    }

    cout << "GOOD";
}