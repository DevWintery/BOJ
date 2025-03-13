#include <iostream>
#include <cmath>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


void solve()
{
    unsigned int x, y;
    cin >> x >> y;

    double s = sqrt(y - x);
    int r = round(sqrt(y - x));

    if(s <= r)
        cout << 2 * r - 1 << '\n';
    else
        cout << 2 * r << '\n';
}

int main()
{
    Initialize

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}