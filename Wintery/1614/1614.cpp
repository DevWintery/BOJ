#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    long long injured, k;
    cin >> injured >> k;


    long long answer = 0;
    switch (injured)
    {
        case 1:
            answer = k * 8;
        break;

        case 2:
        //2, 8, 10, 16 ...
        {
            long long fullPairs = k / 2;
            long long remaining = k % 2;

            answer = 1 + 8 * fullPairs + (remaining * 6);
        }
        break;

        case 3:
        //3, 7, 1, 15 ...
            answer = 2 + k * 4;
            break;

        case 4:
        //4, 6, 12, 14 ...
        {
            long long fullPairs = k / 2;
            long long remaining = k % 2;

            answer = 3 + 8 * fullPairs + (remaining * 2);
        }
        break;

        case 5:
            answer = 4 + k * 8;
        break;
    }

    cout << answer;

    return 0;
}