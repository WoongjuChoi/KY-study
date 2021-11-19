//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <array>
//
//#define INF 987654321
//
//using namespace std;
//
//int N, E;
//
//array<vector<pair<int, int>>, 800> graph;
//
//vector<int> GetShortestPath(int start)
//{
//    // distance �迭 �����
//    // �߰ߵ��� ���� ������ ��� INF��.
//    vector<int> dist(N, INF);
//    // ���� ������ �Ÿ��� 0�̴�.
//    dist[start] = 0;
//
//    // �켱���� ť�� �̿��Ѵ�.
//    priority_queue<pair<int, int>> pq;
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
//        // ���ſ� �߰��� �ִ� ��ο� ���� �ִ� ��θ� ���Ѵ�.
//        // ���ſ� �߰��� �ִ� ��ΰ� �� ũ�ٸ� ����� �ʿ䰡 ����.
//        if (dist[v] < w)
//        {
//            continue;
//        }
//
//        // �ش� ������ �̿����� ��, �ִ� �Ÿ��� ã�� �� �ִ��� üũ�Ѵ�.
//        for (int node = 0; node < graph[v].size(); ++node)
//        {
//            int nextW = graph[v][node].first;
//            int next = graph[v][node].second;
//
//            if (dist[next] > w + nextW)
//            {
//                dist[next] = w + nextW;
//                pq.emplace(-dist[next], next);
//            }
//        }
//    }
//
//    return dist;
//}
//
//int main()
//{
//
//    scanf("%d %d", &N, &E);
//
//    for (int i = 0; i < E; ++i)
//    {
//        int a, b, c;
//        scanf("%d %d %d", &a, &b, &c);
//
//        graph[a - 1].emplace_back(c, b - 1);
//        graph[b - 1].emplace_back(c, a - 1);
//    }
//    
//    int v1, v2;
//    scanf("%d %d", &v1, &v2);
//
//    vector<int> distS = GetShortestPath(0);
//    vector<int> distV1 = GetShortestPath(v1 - 1);
//    vector<int> distV2 = GetShortestPath(v2 - 1);
//
//    int result = min(distS[v1 - 1] + distV1[v2 - 1] + distV2[N - 1], distS[v2 - 1] + distV2[v1 - 1] + distV1[N - 1]);
//
//    if (0 <= result && result < INF)
//        printf("%d", result);
//    else
//        printf("-1");
//}