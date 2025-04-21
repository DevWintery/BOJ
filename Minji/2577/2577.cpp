#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A,B,C = 0;
    cin >> A >> B >> C;

    long long Result = A * B * C;
    string strResult = to_string(Result);

    int Count[10] = {0};

    for (char Char : strResult) 
    {
        Count[Char - '0']++;
    }

    for (int i = 0; i < 10; i++) 
    {
        cout << Count[i] << '\n';
    }

    return 0;
}