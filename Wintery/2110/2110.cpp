#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    int n, c;
    cin >> n >> c;

    vector<int> router(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> router[i];
    }

    ::sort(router.begin(), router.end());

    int l = 0;
    int r = router[n-1];

    int res = 0;

    while(l <= r)
    {
        int count = 1;

        int mid = (l + r) / 2;

        int start = router[0];
        
        for(int i = 1; i < n; ++i)
        {
            int end = router[i];

            if(end - start >= mid)
            {
                ++count;
                start = end;
            }
        }

        if(count >= c)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << res;

    return 0;
}