#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    
    while(true)
    {
        int x, y;
        cin >> x >> y;

        if(x == 0 && y == 0)
            break;

        if(x > y)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    
    return 0;
}