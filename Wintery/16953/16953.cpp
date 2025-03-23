#include <iostream>
#include <queue>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    int A, B;
    cin >> A >> B;

    queue<pair<long long, int>> q;

    q.push({A, 1});

    while(!q.empty())
    {
        auto [x, cnt] = q.front(); q.pop();

        if(x == B)
        {
            cout << cnt;
            return 0;
        }
        else
        {
            if(B >= (x * 2))
                q.push({x * 2, cnt + 1});
            
            if(B >= (x * 10 + 1))
                q.push({x * 10 + 1, cnt + 1});
        }
    }

    cout << - 1;

    return 0;
}