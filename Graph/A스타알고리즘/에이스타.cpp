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
                cout << " "; // �� �� �ִ� ��
            else if (map[r][c] == 1)
                cout << "S"; // ��������
            else if (map[r][c] == 2)
                cout << "B"; // ��ֹ�
            else if (map[r][c] == 3)
                cout << "E"; // ��ǥ����
            else if (map[r][c] == 4)
                cout << "P"; // ������ ���
        }
        cout << endl;
    }
}

int h(Pos a, Pos b) // �޸���ƽ ���ϴ� �Լ�
{
    return abs(a.X - b.X) + abs(a.Y - b.Y); // ����ź �Ÿ�
}

void astar(Pos start, Pos end)
{
    vector<vector<int>> f; // ���������� Ư�� ���������� �Ÿ��� ǥ���ϱ� ���� ����
    for (int i = 0; i < 10; ++i)
        f.emplace_back(10, INF);

    f[start.Y][start.X] = 0; // ���������� �Ÿ��� 0

    Pos path[10][10]; // ���?
    path[start.Y][start.X] = start;

    priority_queue<pair<int, Pos>> pq;
    pq.emplace(0, start);

    int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 }; // �ð�������� ��ǥ ��ȭ
    int dg[] = { 10, 14, 10, 14, 10, 14, 10, 14 }; // �����϶��� ����ġ�� 10, �밢���϶��� 14

    while (false == pq.empty())
    {
        int w = -pq.top().first;
        Pos pos = pq.top().second;
        pq.pop();

        if (f[pos.Y][pos.X] < w) // ������ ����ġ�� �� �۴ٸ� ������ ���� �ʴ´�
        {
            continue;
        }

        if (pos == end) // �����ϸ� ������ ����������
        {
            break;
        }

        for (int i = 0; i < 8; ++i) // �ð�������� ��ǥ �̵���Ű�鼭 �˻�
        {
            int ny = dy[i] + pos.Y;
            int nx = dx[i] + pos.X;

            if (ny < 0 || ny >= 10 || nx < 0 || nx >= 10)
            {
                continue; // ���� ����ٸ� ���� ������
            }

            if (!(map[ny][nx] == 0 || map[ny][nx] == 3))
            {
                continue; // �� �� �ִ� ��Ұ� �ƴ� ��� ���� ������
            }

            int nf = dg[i] + h({ nx, ny }, end); // ����ġ + ��ǥ������ �޸���ƽ = nf

            if (f[ny][nx] > nf) // nf�� ������ ����ġ���� ������� ����
            {
                f[ny][nx] = nf;

                path[ny][nx] = pos; // ��ο� ���� Ž������ ��带 �ִ´�

                pq.emplace(-f[ny][nx], Pos{ nx, ny }); // ���ο� ��ǥ�� ����ġ�� �켱����ť�� �ִ´�
            }
        }
    }

    Pos curr = end; // ��ǥ�������� ��θ� �׸��� ���� curr��� Pos�� ����
    while (curr != start) // ���� ���������� �������� ���ߴٸ�
    {
        map[curr.Y][curr.X] = 4; // ������ ��θ� ǥ��

        curr = path[curr.Y][curr.X]; // path���� ���� ����� ��ǥ���� ����ִ�
    }
}

int main()
{
    PrintMap();

    puts("");

    astar({ START_X, START_Y }, { END_X, END_Y });

    PrintMap();

}