#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    if(str.size() <= 1)
    {
        cout << 0;
        return 0;
    }
    
    if(str.size() % 2 == 0)
    {
        int start = str.size() / 2;
        
        int compare_index = 0;
        int same_char_count = 0;
        for(int i = str.size() - 1; i >= start; i--)
        {
            if(str[i] == str[compare_index])
            {
                same_char_count++;
            }

            compare_index--;
        }

        same_char_count * 2

    }

    int same_char_count = 0;

    
    for(int i = compare_start; i < str.size(); i++)
    {
        str[compareIndex]

        
    }



    return 0;
}