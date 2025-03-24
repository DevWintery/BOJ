#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <iomanip>

using namespace std;

#define Initialize                     \
    ios_base ::sync_with_stdio(false); \
    cin.tie(NULL);                     \
    cout.tie(NULL);

#define ONE_DATE_MINUTE (1440)

struct DateData
{
    string Month;
    int Date;
    int Year;
    int Hour;
    int Minute;
};

unordered_map<std::string, int> MonthMap = {
    {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4},
    {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8},
    {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}};

int MonthDate[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    Initialize

    string NowData;
    getline(cin, NowData);

    DateData Date;

    // Split Input
    {
        istringstream ss(NowData);
        string Month;
        char comma, colon;
    
        ss >> Date.Month >> Date.Date >> comma >> Date.Year >> Date.Hour >> colon >> Date.Minute;
    }

    // 윤년 여부
    bool bIsLeapYear = (Date.Year % 400 == 0) || ((Date.Year % 4 == 0) && (Date.Year % 100 != 0));

    int Month = 0;
    auto Iterator = MonthMap.find(Date.Month);
    if(Iterator != MonthMap.end())
    {
        Month = Iterator->second;
    }

    if(bIsLeapYear)
    {
        MonthDate[1] = 29;
    }

    int NowTotalMinute = 0;
    for(int i = 0; i < Month-1; i++)
    {
        NowTotalMinute += MonthDate[i] * ONE_DATE_MINUTE;
    }
    NowTotalMinute += (Date.Date - 1) * ONE_DATE_MINUTE;
    NowTotalMinute += Date.Hour * 60;
    NowTotalMinute += Date.Minute;

    int YearTotalMinute = bIsLeapYear ? (366 * ONE_DATE_MINUTE) : (365 * ONE_DATE_MINUTE);

    double YearProgress = (double)NowTotalMinute / YearTotalMinute * 100.f;
    cout.precision(9);
    cout << fixed;
    cout << YearProgress;
}