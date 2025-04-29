#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<char, bool> map;

    string S;
    int K;
    cin >> S >> K;

    string answer = "";

    int count = 1;

    for(int i = 0; i < S.length(); i ++)
    {
        if(::tolower(S[i]) == ::tolower(S[i + 1]))
        {
            count ++;
        }
        else
        {
            if(map[::tolower(S[i])] == false)
            {
                map[::tolower(S[i])] = true;

                if(count < K)
                    answer += "0";
                else
                    answer += "1";
            }

            count = 1;
        }
    }

    cout << answer;

    return 0;
}