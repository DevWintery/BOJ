#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    long long X, Y;
    cin >> X >> Y;

    long long Z = 100 * Y / X;
    if(Z >= 99)
    {
        cout << -1;
        return 0;
    }

    int l = 1;
    int r = 1'000'000'000;

    int res = 0;

    while(l <= r)
    {
        int mid = (l + r) / 2;

        int temp = 100 * (Y + mid) / (X + mid);

        if(temp <= Z)
            //더 많은 판수를 해야한다.
            l = mid + 1;
        else
        {
            //더 적은 판수를 할 수 있을지도 모른다.
            res = mid;
            r = mid - 1;
        }
    }

    cout << res;
    
    return 0;
}