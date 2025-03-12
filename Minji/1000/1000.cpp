#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    int num1, num2;
    cin >> num1 >> num2;

    // 1000
    cout << num1 + num2 << endl;

    // 1001
    cout << num1 - num2 << endl;

    // 10098
    cout << num1 * num2 << endl;
}