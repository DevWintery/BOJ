#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B = 0;
    while(cin >> A >> B)
    {
        cout << A+B << "\n";
    }    

    return 0;
}