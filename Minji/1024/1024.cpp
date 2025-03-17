#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    long long N, L;
    cin >> N >> L;

    int Result = 0;

    while(L <= 100)
    {
        int Remain = (2*N - L*L + L) % (2*L);
        if(Remain == 0)
        {
            Result = (2*N - L*L + L) / (2*L);
            if(Result >= 0)
            {
                for(int i = 0; i < L; i++)
                {
                    cout << Result + i << " ";
                }
                return 0;
            }
        }
        
        L++;
    }

    cout << -1;
}