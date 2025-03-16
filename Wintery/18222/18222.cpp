#include <iostream>
#include <string>
#include <bitset>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

int main()
{
    Initialize

    long long k;
    cin >> k;

    cout << bitset<64>(--k).count() % 2;

    return 0;
}