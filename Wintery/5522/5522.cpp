#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int answer = 0;
    while(cin >> n)
    {
        answer += n;
    }
    cout << answer;

    return 0;
}