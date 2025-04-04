#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

int main()
{
    Initialize

    long long HurtFinger, UsableMaxCount = 0;
    cin >> HurtFinger >> UsableMaxCount;

    // 사용할 수 있는 손가락이 없을 경우
    // 아픈 손가락을 제외하고 셀 수 있는 최대 수 출력
    if(UsableMaxCount <= 0)
    {
        cout << (HurtFinger - 1);
    }
    else
    {
        // N번 사용한다면, (N+1) 사용 시의 숫자를 저장
        long long ExcessCountNum = 0;
        long long ExcessCount = UsableMaxCount + 1;

        switch (HurtFinger)
        {
            // 엄지 혹은 새끼 손가락일 경우
            case 1:
            case 5: ExcessCountNum = 8 * (ExcessCount - 1) + HurtFinger; break;
            // 검지 : 짝수공차 6 / 홀수공차 2
            case 2:
            {
                long long EvenCount = ExcessCount / 2;
                long long OddCount = ExcessCount - EvenCount - 1;

                ExcessCountNum = 6 * EvenCount + 2 * OddCount + HurtFinger;
                break;
            }
            // 중지 : 공차 4
            case 3: ExcessCountNum = 4 * (ExcessCount - 1) + HurtFinger; break;
            // 약지 : 짝수공차 2 / 홀수공차 6
            case 4:
            {
                long long EvenCount = ExcessCount / 2;
                long long OddCount = ExcessCount - EvenCount - 1;

                ExcessCountNum = 2 * EvenCount + 6 * OddCount + HurtFinger;
                break;
            }
            default: cout << 0; return 0;
        }

        cout << ExcessCountNum - 1;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
}