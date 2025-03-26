#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Initialize                     \
    ios_base ::sync_with_stdio(false); \
    cin.tie(NULL);                     \
    cout.tie(NULL);

struct SellData
{
    int Cost;
    int DeliveryCost;

    bool operator < (const SellData &other) const 
    {
        return Cost < other.Cost;
    }
};
    
int main()
{
    Initialize

    int Count = 0;
    cin >> Count;

    vector<SellData> Data;

    for(int Index = 0; Index < Count; Index++)
    {
        SellData data;
        cin >> data.Cost >> data.DeliveryCost;
        Data.push_back(data);
    }

    int MaxTotalbenefit = 0;
    int MaxTotalbenefitCost = INT_MAX;

    for(SellData data : Data)
    {
        int Totalbenefit = 0;
        for(SellData compare : Data)
        {
            if((data.Cost > compare.Cost))
            {
                continue;
            }
            int Total = (data.Cost - compare.DeliveryCost);
            if(Total > 0)
            {
                Totalbenefit += Total;
            }
        }

        if(MaxTotalbenefit < Totalbenefit)
        {            
            MaxTotalbenefit = Totalbenefit;
            MaxTotalbenefitCost = data.Cost;
        }
        else if((MaxTotalbenefit == Totalbenefit) && (MaxTotalbenefitCost > data.Cost))
        {
            MaxTotalbenefitCost = data.Cost;
        }
    }

    if(MaxTotalbenefit <= 0)
    {
        cout << 0;
    }
    else
    {
        cout << MaxTotalbenefitCost;
    }
}