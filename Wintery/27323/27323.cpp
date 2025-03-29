#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    int a, b;
    cin >> a >> b;

    cout << a * b;

    return 0;
}