#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    int CoinCount, Cost;
    cin >> CoinCount >> Cost;

    bool bEnough = CoinCount * 100 >= Cost;
    cout << (bEnough ? "Yes" : "No");
}