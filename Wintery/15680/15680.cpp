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

    cout << (N ? "Leading the Way to the Future" : "YONSEI");

    return 0;
}