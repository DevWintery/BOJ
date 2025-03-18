#include <iostream>
#include <unordered_map>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

void solve()
{
    unordered_map<int, int> m;

    int N;
    cin >> N;

    for(int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        m[x] ++;
    }

    int M;
    cin >> M;
    for(int i = 0; i < M; ++i)
    {
        int x;
        cin >> x;
        
        if(m[x] >= 1)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
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