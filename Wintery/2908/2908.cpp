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

    string A, B;
    cin >> A >> B;
    
    std::reverse(A.begin(), A.end());
    std::reverse(B.begin(), B.end());
    
    int C, D;
    C = std::stoi(A);
    D = std::stoi(B);
    
    if(C < D)
        cout << D;
    else
        cout << C;
    
    return 0;
}