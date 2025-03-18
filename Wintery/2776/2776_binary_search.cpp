#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


void solve()
{
    int N, M;
    cin >> N;
    
    vector<int> nv(N);
    for(int i = 0; i < N; ++i)
        cin >> nv[i];

    cin >> M;

    vector<int> mv(M);
    for(int i = 0; i < M; ++i)
        cin >> mv[i];

    sort(nv.begin(), nv.end());


    for(int i = 0; i < M; ++i)
    {
        int l = 0;
        int r = N - 1;
        int target = mv[i];

        bool found = false;
        while(l <= r)
        {
            int mid = (l + r) / 2;
    
            int cur = nv[mid];
            if(target < cur)
            {
                r = mid - 1;
            }
            else if(target > cur)
            {
                l = mid + 1;
            }
            else
            {
                found = true;
                break;
            }
        }

        cout << (found ? 1 : 0) << '\n';
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