#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int a = 1;
    int answer = 1;

    for(int i = 0; i < N; i ++)
    {
        if(i % 2 != 0)
            a += 1;
        answer += a;
    }
    cout << answer;

    return 0;
}