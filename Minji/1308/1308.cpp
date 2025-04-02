#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int MonthDate[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct FDayData
{
    int Year;
    int Month;
    int Date;

    bool IsLeafYear(int Y) const
    {
        return (Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0);
    }

    long long TotalDate() const 
    {
        long long Result = 0;

        // Year
        if(Year > 0)
        {
            for(int i = 1; i < Year; i++)
            {
                Result += (IsLeafYear(i) ? 366 : 365);
            }
        }

        if(IsLeafYear(Year))
        {
            MonthDate[1] = 29;
        }        

        // Month
        for(int i = 1; i < Month; i++)
        {
            Result += MonthDate[i-1];
        }        

        Result += Date;
        return Result;
    }
};

int main()
{
    Initialize

    FDayData Today;
    FDayData TargetDay;

    cin >> Today.Year >> Today.Month >> Today.Date;
    cin >> TargetDay.Year >> TargetDay.Month >> TargetDay.Date;

    if((TargetDay.Year > Today.Year + 1000)
        || (TargetDay.Year == Today.Year + 1000 
            && TargetDay.Month >= Today.Month
            && TargetDay.Date >= Today.Date))
    {
        cout << "gg";
        return 0;
    }

    cout << "D-" << (TargetDay.TotalDate() - Today.TotalDate());
}