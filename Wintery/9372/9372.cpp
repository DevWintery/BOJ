#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


void solve()
{
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
    }

    cout << N - 1 << '\n';
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