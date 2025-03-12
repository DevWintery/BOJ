#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    int Num1, Num2;
    cin >> Num1 >> Num2;

    cout << Num1 + Num2 << endl;
    cout << Num1 - Num2 << endl;
    cout << Num1 * Num2 << endl;
    cout << Num1 / Num2 << endl;
    cout << Num1 % Num2 << endl;
}