#include <iostream>
#include <time.h>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    time_t timer = time(NULL);
    // UTC 시간 가지고오기
    struct tm* t = gmtime(&timer);

    cout << t->tm_year + 1900 << "-";
    cout << ((t->tm_mon + 1) < 10 ? "0" : "") << t->tm_mon + 1 << "-";
    cout << (t->tm_mday < 10 ? "0" : "") << t->tm_mday;
}