#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


vector<string> Split(string str, char delimiter)
{
    istringstream iss(str);
    string buffer;

    vector<string> result;

    while(getline(iss, buffer, delimiter))
    {
        result.push_back(buffer);
    }

    return result;
}

int main()
{
    Initialize

    string str;
    getline(cin, str);

    vector<string> v = Split(str, ' ');
    v[1].pop_back(); // ',' 제거

    vector<string> time = Split(v[3], ':');

    unordered_map<string, int> monthToIdx = {
        {"January", 0}, {"February", 1}, {"March", 2}, {"April", 3},
        {"May", 4}, {"June", 5}, {"July", 6}, {"August", 7},
        {"September", 8}, {"October", 9}, {"November", 10}, {"December", 11}
    };

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    bool isLeap = false;
    int year = stoi(v[2]);
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        isLeap = true;
        days[1] = 29; // 윤년이면 2월을 29일로 변경
    }

    
    int month = monthToIdx[v[0]];
    int date = stoi(v[1]);
    int hour = stoi(time[0]);
    int minute = stoi(time[1]);

    // 해당 날짜까지의 총 분 계산
    int totalMinutes = 0;
    
    // 이전 월까지의 모든 일수 합산
    for(int i = 0; i < month; i++)
    {
        totalMinutes += days[i] * 24 * 60;
    }
    
    // 해당 월의 일수 추가 (1일부터 시작하므로 -1)
    totalMinutes += (date - 1) * 24 * 60;
    
    // 시간과 분 추가
    totalMinutes += hour * 60 + minute;

    // 연도의 총 분 계산
    int yearMinutes = isLeap ? 366 * 24 * 60 : 365 * 24 * 60;
    
    // 백분율 계산
    double percentage = (double)totalMinutes / yearMinutes * 100;

    cout.precision(9);
    cout << fixed;
    cout << percentage;

    return 0;
}