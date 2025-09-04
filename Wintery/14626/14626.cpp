#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    bool flag = true;
    int sum = 0;

    int errorIndex = 0;

    for(int i = 0; i < str.length(); i ++)
    {
        flag = !flag;

        if(str[i] == '*')
        {
            errorIndex = i;
            continue;
        }

        int number = (str[i] - '0');
        sum += flag ? (3 * number) : number;
    }

    if(errorIndex % 2 != 0)
    {
        for(int i = 0; i < 10; i ++)
        {
            if((sum + i * 3) % 10 == 0)
            {
                cout << i;
                break;
            }
        }
    }
    else
    {
        cout << 10 - sum % 10;
    }

    return 0;
}