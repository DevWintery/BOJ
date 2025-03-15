#include <iostream>
#include <cmath>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    long long A, B;
    cin >> A >> B;

    cout << (A+B) * (A-B);
}