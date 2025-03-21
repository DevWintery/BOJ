#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

int main()
{
    Initialize

        int Row,
        Column;
    cin >> Row >> Column;

    for (int R = 0; R < Row; R++)
    {
        for (int C = 0; C < Column; C++)
        {
            cout << "*";
        }
        cout << endl;
    }
}