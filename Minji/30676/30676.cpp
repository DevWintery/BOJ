#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    int Wave;
    cin >> Wave;

    string Result;
    if(Wave >= 620 && Wave <= 780)
    {
        Result = "Red";
    }
    else if(Wave >= 590 && Wave < 620)
    {
        Result = "Orange";
    }
    else if(Wave >= 570 && Wave < 590)
    {
        Result = "Yellow";
    }
    else if(Wave >=495 && Wave < 570)
    {
        Result = "Green";
    }
    else if(Wave >= 450 && Wave < 495)
    {
        Result = "Blue";
    }
    else if(Wave >= 425 && Wave < 450)
    {
        Result = "Indigo";
    }
    else if(Wave >= 380 && Wave < 425)
    {
        Result = "Violet";
    }

    cout << Result;
}