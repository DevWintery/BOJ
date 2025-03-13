#include <iostream>
#include <vector>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    int N, M;
    cin >> N >> M;

    vector<int> lecture(N);

    for(int i = 0; i < N; ++i)
        cin >> lecture[i];
    
    int l = 1;
    int r = 1'000'000'000;

    int res = 0;

    while(l <= r)
    {
        int mid = (l + r) / 2;

        int cnt = 1;
        int min = 0;

        for(int i = 0; i < N; i ++)
        {
            if(mid < lecture[i])
            {
                cnt = M + 1; // i 번쨰 강의가 크기보다 크면 아예 녹화가 불가능하므로 바로 L을 늘린다.
                break;
            }
            
            if(min + lecture[i] <= mid)
            {
                min += lecture[i];
            }
            else
            {
                min = lecture[i];
                cnt ++;
            }
        }

        if(cnt <= M)
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << res;

    return 0;
}