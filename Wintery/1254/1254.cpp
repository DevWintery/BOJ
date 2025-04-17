#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;

    string rS = S;

    ::reverse(rS.begin(), rS.end());

    int answer = 987654321;

    for(int i = 0; i < S.size(); i ++)
    {
        string subS = S.substr(i, S.size());
        string subrS = rS.substr(0, rS.size() - i);

        if (subS == subrS)
        {
            answer = ::min(answer, (int)S.size() + i);
        }
    }

    cout << answer;

    return 0;
}