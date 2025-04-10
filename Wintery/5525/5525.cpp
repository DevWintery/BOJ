#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int M;
    cin >> M;

    string S;
    cin >> S;

    int patternCount = 0;
    int answer = 0;
    for (int i = 1; i < M - 1; i++)
    {
        if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I')
        {
            patternCount++;
            if (patternCount == N)
            {
                answer++;
                patternCount--;
            }
            i++;
        }
        else
        {
            patternCount = 0;
        }
    }

    cout << answer;

    return 0;
}