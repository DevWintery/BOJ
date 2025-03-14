#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    string N;
    cin >> N;

    // 각 자리수를 저장
    vector<int> DigitNumber;

    for(int Place = 0; Place < N.length(); Place++)
    {
        DigitNumber.emplace_back(N[Place] - '0');
    }

    sort(DigitNumber.begin(), DigitNumber.end(), greater<int>());

    for(int digit : DigitNumber)
    {
        cout << digit;
    }
}