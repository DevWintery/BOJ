#include <iostream>

using namespace std;

#define Initialize                     \
    ios_base ::sync_with_stdio(false); \
    cin.tie(NULL);                     \
    cout.tie(NULL);

int main()
{
    Initialize

    int N, Total = 0;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int PlugCount;
        cin >> PlugCount;
        Total += PlugCount;
    }

    cout << Total - (N-1);
}