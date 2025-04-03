#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

// key : 문제 번호
// Value : 문제를 풀 수 있는 학생들
map<int,vector<int>> CanSolveStudent;

// 모든 문제를 풀 수 있는 학생들의 조합
set<set<int>> Combination;

void AddCombination(int QuizNum)
{
    const vector<int>& CanSolveQuiz = CanSolveStudent.find(QuizNum)->second;

    if(Combination.size() <= 0)
    {
        for(int Student : CanSolveQuiz)
        {
            set<int> NewComb = {Student};
            Combination.emplace(NewComb);
        }
        return;
    }

    set<set<int>> NewCombinations;

    for(const set<int>& Comb : Combination)
    {
        for(int Student : CanSolveQuiz)
        {
            set<int> NewComb = Comb;
            if(Comb.find(Student) == Comb.end())
            {
                NewComb.emplace(Student);
            }
            NewCombinations.emplace(NewComb);
        }
    }
    Combination = NewCombinations;

}

int main()
{
    Initialize

    int N, M = 0;


    cin >> N >> M;

    for(int i = 1; i <= N; i++)
    {
        CanSolveStudent.emplace(i,vector<int>());
    }

    for(int Student = 0; Student < M; Student++)
    {
        int QuizCount = 0;
        cin >> QuizCount;

        // 한 학생이 모든 문제를 풀 수 있음을 의미미
        if(QuizCount >= N)
        {
            cout << 1;
            return 0;
        }

        for(int i = 0; i < QuizCount; i++)
        {
            int Num = 0;
            cin >> Num;

            auto it = CanSolveStudent.find(Num);
            it->second.push_back(Student);
        }
    }

    // 출력
    for(auto it : CanSolveStudent)
    {
        // 문제를 풀 수 있는 학생이 없음을 의미
        if(it.second.size() <= 0)
        {
            cout << -1;
            return 0;
        }

        AddCombination(it.first);
    }

    int MinCount = INT_MAX;
    for(auto Comb : Combination)
    {
        if(MinCount > Comb.size())
        {
            MinCount = Comb.size();
        }
    }

    cout << MinCount;   
}