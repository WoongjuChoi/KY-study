#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;

int tomato[1000][1000] = { -1 };
static bool isVisited[1000][1000] = { false };

int countDay(int r, int c)
{
    int result = 1;

    isVisited[r][c] = true;

    if (r - 1 >= 0 && tomato[r - 1][c] == 0 && isVisited[r - 1][c] == false)
    {
        tomato[r - 1][c] = 1;
        result += countDay(r - 1, c);
    }

    if (r + 1 < N && tomato[r + 1][c] == 0 && isVisited[r + 1][c] == false)
    {
        tomato[r + 1][c] = 1;
        result += countDay(r + 1, c);
    }

    if (c - 1 >= 0 && tomato[r][c - 1] == 0 && isVisited[r][c - 1] == false)
    {
        tomato[r][c - 1] = 1;
        result += countDay(r, c - 1);
    }

    if (c + 1 < N && tomato[r][c + 1] == 0 && isVisited[r][c + 1] == false)
    {
        tomato[r][c + 1] = 1;
        result += countDay(r, c + 1);
    }

    return result;
}

int main()
{
    scanf("%d %d", &M, &N);

    vector<int> result;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            scanf("%d", &tomato[i][j]);
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (tomato[i][j] == 1)
            {
                result.push_back(countDay(i, j));
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (tomato[i][j] == 0) // 익지 않은 토마토가 존재하는 경우
            {
                result.push_back(0);
            }
        }
    }

    sort(result.begin(), result.end());

    printf("%d", result.front());
}