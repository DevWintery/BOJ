#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

void solve()
{
    int M, N, x, y;
    cin >> M >> N >> x >> y;

    int limit = lcm(M, N);

    for(int k = x; k <= limit; k += M)
    {
        int _y = (k % N == 0) ? N : k % N;

        if(_y == y)
        {
            cout << k << '\n';
            return;
        }
    }

    cout << -1 << '\n';

    return;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}