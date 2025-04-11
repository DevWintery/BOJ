#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve()
{
    long long n, m;
    cin >> n >> m;

    long long answer = 0;
    while(n > 0)
    {
        n /= 2;
        answer ++;
    }

    answer += m;

    cout << answer << '\n';
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