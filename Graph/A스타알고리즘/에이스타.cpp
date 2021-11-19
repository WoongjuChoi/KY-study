#include <iostream>
#include <queue>
#include <vector>

#define START_X 2
#define START_Y 4
#define END_X   7
#define END_Y   4

#define INF 1e9

using namespace std;

int map[10][10] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 2, 0, 0, 3, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

struct Pos
{
    int X;
    int Y;

    bool operator<(const Pos& other) const { return (X < other.X) && (Y < other.Y); }
    bool operator==(const Pos& other) const { return X == other.X && Y == other.Y; }
    bool operator!=(const Pos& other) const { return !(*this == other); }
};

void PrintMap()
{
    for (int r = 0; r < 10; ++r)
    {
        for (int c = 0; c < 10; ++c)
        {
            if (map[r][c] == 0)
                cout << " "; // 갈 수 있는 곳
            else if (map[r][c] == 1)
                cout << "S"; // 시작지점
            else if (map[r][c] == 2)
                cout << "B"; // 장애물
            else if (map[r][c] == 3)
                cout << "E"; // 목표지점
            else if (map[r][c] == 4)
                cout << "P"; // 움직인 경로
        }
        cout << endl;
    }
}

int h(Pos a, Pos b) // 휴리스틱 구하는 함수
{
    return abs(a.X - b.X) + abs(a.Y - b.Y); // 맨하탄 거리
}

void astar(Pos start, Pos end)
{
    vector<vector<int>> f; // 시작점부터 특정 지점까지의 거리를 표시하기 위한 벡터
    for (int i = 0; i < 10; ++i)
        f.emplace_back(10, INF);

    f[start.Y][start.X] = 0; // 시작지점은 거리가 0

    Pos path[10][10]; // 경로?
    path[start.Y][start.X] = start;

    priority_queue<pair<int, Pos>> pq;
    pq.emplace(0, start);

    int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 }; // 시계방향으로 좌표 변화
    int dg[] = { 10, 14, 10, 14, 10, 14, 10, 14 }; // 직선일때는 가중치가 10, 대각선일때는 14

    while (false == pq.empty())
    {
        int w = -pq.top().first;
        Pos pos = pq.top().second;
        pq.pop();

        if (f[pos.Y][pos.X] < w) // 기존의 가중치가 더 작다면 루프를 돌지 않는다
        {
            continue;
        }

        if (pos == end) // 도착하면 루프를 빠져나간다
        {
            break;
        }

        for (int i = 0; i < 8; ++i) // 시계방향으로 좌표 이동시키면서 검사
        {
            int ny = dy[i] + pos.Y;
            int nx = dx[i] + pos.X;

            if (ny < 0 || ny >= 10 || nx < 0 || nx >= 10)
            {
                continue; // 맵을 벗어난다면 다음 루프로
            }

            if (!(map[ny][nx] == 0 || map[ny][nx] == 3))
            {
                continue; // 갈 수 있는 장소가 아닌 경우 다음 루프로
            }

            int nf = dg[i] + h({ nx, ny }, end); // 가중치 + 목표까지의 휴리스틱 = nf

            if (f[ny][nx] > nf) // nf가 기존의 가중치보다 작은경우 갱신
            {
                f[ny][nx] = nf;

                path[ny][nx] = pos; // 경로에 현재 탐색중인 노드를 넣는다

                pq.emplace(-f[ny][nx], Pos{ nx, ny }); // 새로운 좌표와 가중치를 우선순위큐에 넣는다
            }
        }
    }

    Pos curr = end; // 목표지점부터 경로를 그리기 위해 curr라는 Pos를 생성
    while (curr != start) // 아직 시작지점에 도착하지 못했다면
    {
        map[curr.Y][curr.X] = 4; // 움직인 경로를 표시

        curr = path[curr.Y][curr.X]; // path에는 이전 경로의 좌표값이 들어있다
    }
}

int main()
{
    PrintMap();

    puts("");

    astar({ START_X, START_Y }, { END_X, END_Y });

    PrintMap();

}