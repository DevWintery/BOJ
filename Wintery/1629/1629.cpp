#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B, C;
    cin >> A >> B >> C;

    int answer = 1;
    
    while(B > 0)
    {
        if(B & 1)
        {
            answer = (answer * A) % C;
        }

        A = (A * A) % C;
        B >>= 1;
    }

    cout << answer;
    
    return 0;
}