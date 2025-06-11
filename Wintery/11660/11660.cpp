#include <iostream>
#include <vector>
#include <string>

using namespace std;

int board[1025][1025];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int temp;
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            cin >> temp;

            board[i][j] = board[i - 1][j] + board[i][j - 1] + temp - board[i - 1][j - 1];
        }
    }

    int result;
    int x1, y1, x2, y2;

    for(int i = 0; i < M; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        result = board[x2][y2] - board[x1 - 1][y2] - board[x2][y1 - 1] + board[x1 - 1][y1 - 1];
        cout << result << '\n';
    }

    return 0;
}