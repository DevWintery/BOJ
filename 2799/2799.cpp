#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    //창문 타입들 순서대로 나와야하기 때문에 map을 사용
    map<string, int, greater<string>> answer;
    answer.insert( ::make_pair("................", 0) );
    answer.insert( ::make_pair("****............", 0) );
    answer.insert( ::make_pair("********........", 0) );
    answer.insert( ::make_pair("************....", 0) );
    answer.insert( ::make_pair("****************", 0) );


    int M, N;
    cin >> M >> N;

    vector<string> v(M * N);

    //첫 줄은 #으로 이루어져있으므로 스킵
    string str;
    cin >> str;

    //M개의 층이 있으므로 층별로 순회
    for(int i = 0; i < M; ++i)
    {
        //창문 정보 기입
        vector<string> windows(N);
        for(int j = 0; j < 4; ++j)
        {
            cin >> str;

            //N개의 창문이 있으므로 N번 순회
            int startPos = 1;
            for(int k = 0; k < N; ++k, startPos += 5)
            {
                windows[k] += str.substr(startPos, 4);
            }
        }

        //answer 저장
        for(const string& window : windows)
        {
            ++answer[window];
        }
        
        //#으로 이루어진 문자는 스킵
        cin >> str;
    }

    for(const auto& res : answer)
    {
        cout << res.second << ' ';
    }

    return 0;
}