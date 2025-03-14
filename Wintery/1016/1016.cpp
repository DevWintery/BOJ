#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    long long min, max;
    cin >> min >> max;

    int range = max - min + 1;

    vector<bool> is_squared(range, false);

    for(long long i = 2; i * i <= max; ++i)
    {
        long long square = i * i;

        //min이상인 최소 제곱수
        long long start = (min + square - 1) / square * square; // a / b를 올림하는것은 (a + b - 1) / b 와 같다

        //square의 배수를 모두 지운다.
        for(long long j = start; j <= max; j += square)
            is_squared[j - min] = true;
    }

    int count = 0;
    for (int i = 0; i < range; i++) {
        if (!is_squared[i]) count++;
    }
    
    cout << count << '\n';
    
    return 0;
}