#include <iostream>
#include <cmath>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    long long Total;
    long long Win;
    cin >> Total >> Win;

    if(Win == Total)
    {
        cout << -1 << endl;
        return 0;
    }

    // 현재 승률
    long long Current = 100 * Win/Total;
    if(Current >= 99)
    {        
        cout << -1 << endl;
        return 0;
    }

    long long Denominator = (Total * (Current + 1) - 100 * Win);
    long long Divider = (100 - Current - 1);

    bool Remain = (Denominator % Divider) == 0;
    long long Result = ceil(Denominator / Divider);
    
    cout << (Remain ? Result : Result + 1);
}