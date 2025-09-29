#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B;
    cin >> A >> B;

    int answer = 987654321;

    for (int i = 0; i < B.length(); i++)
    {
        bool flag = true;
        int count = 0;
        for (int j = 0; j < A.length(); j++)
        {
            if(i + A.length() > B.length())
            {
                flag = false;
                break;
            }

            if(A[j] != B[i + j])
            {
                count ++;
            }
        }

        if(flag)
            answer = ::min(count, answer);
    }

    cout << answer;

    return 0;
}