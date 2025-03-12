#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    long Num1, Num2, Num3;
    cin >> Num1 >> Num2 >> Num3;

    cout << Num1 + Num2 + Num3 << endl;
}