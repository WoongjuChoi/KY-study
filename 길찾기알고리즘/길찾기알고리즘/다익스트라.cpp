//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//#define INF 987654321
//
//using namespace std;
//
//int graph[7][7] = {
//    {   0,   7, INF, INF,   3,  10, INF },
//    {   7,   0,   4,  10,   2,   6, INF },
//    { INF,   4,   0,   2, INF, INF, INF },
//    { INF,  10,   2,   0,  11,   9,   4 },
//    {   3,   2, INF,  11,   0, INF,   5 },
//    {  10,   6, INF,   9, INF,   0, INF },
//    { INF, INF, INF,   4,   5, INF,   0 }
//};
//
//std::vector<int> GetShortestPath(int start)
//{
//    // 1. distance / distance[i] : ���� ���� -> i�� ���� �ִ� ���. distance[start] = 0 / �������� INF
//    // 2. �߰��� ���� �� �ִ� ����� ����(v)�� ã�´�. => ��(�켱���� ť)�� ����� ����ȭ ����
//    // 3. �ش� ����(v)�� �����ؼ� ���� ��, �ִ� ��ΰ� �ִ��� Ž���Ѵ�. distance[i] = min(distance[i], distance[v] + graph[v][i]);
//    // 4. ��� ������ ���ؼ� �ִ� ��θ� ã�� ������ �ݺ��Ѵ�.
//    // 5. 
//    std::vector<int> dist(7);
//    for (int i = 0; i < 7; ++i)
//        dist[i] = graph[start][i];
//
//    // �湮�� ���� ���� �����
//    std::vector<bool> isVisited(7);
//    isVisited[start] = true;
//
//    // ��� ������ ���� �ִ� ��θ� ã�� ������
//    for (int i = 0; i < 7 - 1; ++i)
//    {
//        // �湮���� ���� ���� �� �ּڰ��� ������ ������ ����
//        size_t next = 0;
//        size_t minDist = INF;
//
//        for (size_t node = 0; node < 7; ++node)
//        {
//            if (isVisited[node])
//                continue;
//
//            if (minDist > dist[node])
//            {
//                next = node;
//                minDist = dist[node];
//            }
//        }
//
//        // �湮 ǥ�� => �湮�� ������ �ּ� �Ÿ����� ������.
//        isVisited[next] = true;
//
//        // ��� ������Ʈ
//        for (size_t node = 0; node < 7; ++node)
//        {
//            dist[node] = std::min(dist[node], dist[next] + graph[next][node]);
//        }
//    }
//
//    return dist;
//}
//
//// O((V + E)logV)���� ����ȭ (V�� ������ ����, E�� �� ������ �ֺ��� ���)
//std::vector<int> GetShortestPath2(int start)
//{
//    // distance �迭 �����
//    // �߰ߵ��� ���� ������ ��� INF��.
//    vector<int> dist(7, INF);
//    // ���� ������ �Ÿ��� 0�̴�.
//    dist[start] = 0;
//
//    // �켱���� ť�� �̿��Ѵ�. (���� ������ �ڵ� ����) ����Ʈ�� �ִ밪���� ��µ�
//    // pair : ù ��° ���� �������� ����. ù��°�� ����ġ, �ι�°�� ���
//    priority_queue<pair<int, int>> pq;
//
//    // ���� ������ �־��ش�.
//    pq.emplace(0, start);
//
//    // dist�� ��� ���� ã�� ������
//    while (false == pq.empty())
//    {
//        // dist �߿��� ���� �ּҰ��� ������ ������ �̾Ƴ���.
//        int w = -pq.top().first;
//        int v = pq.top().second;
//        pq.pop();
//
//        // �ش� ������ ������ ��, �ִ� �Ÿ��� ã�� �� �ִ��� üũ�Ѵ�.
//        for (int node = 0; node < 7; ++node)
//        {
//            if (dist[node] > dist[v] + graph[v][node])
//            {
//                // ��� ������Ʈ
//                dist[node] = dist[v] + graph[v][node];
//
//                // ������ �־ ���Ǹ� �ؾ� ��
//                // ���� ū ������ �����ϱ⶧���� ����ġ�� ������ �����ؾ� �Ÿ��� ª���� ���� ���ϵ�
//                pq.emplace(-dist[node], node);
//            }
//        }
//    }
//
//    return dist;
//}
//
//int main()
//{
//    auto vec1 = GetShortestPath(0);
//    auto vec2 = GetShortestPath(2);
//
//    std::cout << "0 : [";
//    for (int i : vec1)
//    {
//        std::cout << i << ' ';
//    }
//    std::cout << "]\n";
//
//    std::cout << "2 : [";
//    for (int i : vec2)
//    {
//        std::cout << i << ' ';
//    }
//    std::cout << "]\n";
//
//    auto vec3 = GetShortestPath2(0);
//    std::cout << "0 : [";
//    for (int i : vec3)
//    {
//        std::cout << i << ' ';
//    }
//    std::cout << "]\n";
//}
