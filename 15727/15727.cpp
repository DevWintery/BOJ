#include<iostream>

using namespace std;

#define Init    ios_base :: sync_with_stdio(false); \
                cin.tie(NULL); \
                cout.tie(NULL);

int main()
{
    Init

    int answer = 0;

    int L;
    cin >> L;

    answer = (L / 5) + ( (L % 5 != 0) ? 1 : 0 );

    cout << answer;

    return 0;
}