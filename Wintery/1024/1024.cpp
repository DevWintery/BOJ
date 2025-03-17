#include <iostream>
#include <vector>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    long long N, L;
    cin >> N >> L;

    for(int length = L; length <= 100; ++length)
    {
        // N = (start + (start + length - 1)) * length / 2
        // 2N = (2*start + length - 1) * length
        // 2N = 2*start*length + length^2 - length
        // 2*start*length = 2N - length^2 + length
        // start = (2N - length^2 + length) / (2*length)

        long long numerator = 2 * N - length * length + length;
        long long denominator = 2 * length;
        
        // 시작 값이 정수이고 음이 아닌지 확인
        if (numerator >= 0 && numerator % denominator == 0) 
        {
            long long start = numerator / denominator;
            
            for (int i = 0; i < length; i++) 
            {
                cout << start + i;

                if (i < length - 1) 
                    cout << " ";
            }
            return 0;
        }
    }

    cout << -1;
    return 0;
}