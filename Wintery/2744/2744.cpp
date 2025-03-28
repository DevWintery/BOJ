#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i ++)
    {
        if(islower(str[i]))
            str[i] = str[i] - 32;
        else
            str[i] = str[i] + 32;
            
    }
    
    cout << str;

    return 0;
}