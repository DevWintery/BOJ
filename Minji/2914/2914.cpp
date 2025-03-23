#include <iostream>

using namespace std;

#define Initialize                     \
    ios_base ::sync_with_stdio(false); \
    cin.tie(NULL);                     \
    cout.tie(NULL);

int main()
{
    Initialize

        int A, I;
    cin >> A >> I;

    cout << (A * (I - 1)) + 1;
}