#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> paper(N, vector<int>(M));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> paper[i][j];
        }
    }

    int answer = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // ㅡ 자 블럭 (I 테트로미노)
            // 가로 방향
            if(j + 3 < M)
                answer = max(answer, paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i][j+3]);
            
            // 세로 방향
            if(i + 3 < N)
                answer = max(answer, paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+3][j]);

            // ㅁ자 블럭 (O 테트로미노)
            if(i + 1 < N && j + 1 < M)
                answer = max(answer, paper[i][j] + paper[i+1][j] + paper[i][j+1] + paper[i+1][j+1]);

            // L 블럭 (L 테트로미노)
            // L 모양 (0도 회전)
            if(i + 2 < N && j + 1 < M)
                answer = max(answer, paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+2][j+1]);
            
            // L 모양 (90도 회전)
            if(i + 1 < N && j + 2 < M)
                answer = max(answer, paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j]);
            
            // L 모양 (180도 회전)
            if(i + 2 < N && j + 1 < M)
                answer = max(answer, paper[i][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1]);
            
            // L 모양 (270도 회전)
            if(i + 1 < N && j + 2 < M)
                answer = max(answer, paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2] + paper[i][j+2]);
            
            // L 모양 대칭 (0도 회전)
            if(i + 2 < N && j + 1 < M)
                answer = max(answer, paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1] + paper[i+2][j]);
            
            // L 모양 대칭 (90도 회전)
            if(i + 1 < N && j + 2 < M)
                answer = max(answer, paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2] + paper[i][j]);
            
            // L 모양 대칭 (180도 회전)
            if(i + 2 < N && j + 1 < M)
                answer = max(answer, paper[i][j] + paper[i][j+1] + paper[i+1][j] + paper[i+2][j]);
            
            // L 모양 대칭 (270도 회전)
            if(i + 1 < N && j + 2 < M)
                answer = max(answer, paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j+2]);

            // Z 블럭 (S 테트로미노)
            // 가로 방향
            if(i + 1 < N && j + 2 < M)
                answer = max(answer, paper[i][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+1][j+2]);
            
            // 세로 방향
            if(i + 2 < N && j + 1 < M)
                answer = max(answer, paper[i][j+1] + paper[i+1][j+1] + paper[i+1][j] + paper[i+2][j]);

            // Z 블럭 대칭 (Z 테트로미노)
            // 가로 방향
            if(i + 1 < N && j + 2 < M)
                answer = max(answer, paper[i+1][j] + paper[i+1][j+1] + paper[i][j+1] + paper[i][j+2]);
            
            // 세로 방향
            if(i + 2 < N && j + 1 < M)
                answer = max(answer, paper[i][j] + paper[i+1][j] + paper[i+1][j+1] + paper[i+2][j+1]);

            // T 블럭 (T 테트로미노)
            // T 모양 (0도 회전)
            if(i + 1 < N && j + 2 < M)
                answer = max(answer, paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j+1]);
            
            // T 모양 (90도 회전)
            if(i + 2 < N && j + 1 < M)
                answer = max(answer, paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1] + paper[i+1][j]);
            
            // T 모양 (180도 회전)
            if(i + 1 < N && j + 2 < M)
                answer = max(answer, paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2] + paper[i][j+1]);
            
            // T 모양 (270도 회전)
            if(i + 2 < N && j + 1 < M)
                answer = max(answer, paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+1][j+1]);
        }
    }

    cout << answer << endl;
    return 0;
}