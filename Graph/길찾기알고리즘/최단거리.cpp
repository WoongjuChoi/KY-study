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
//int V, E, K;
//
//array<vector<pair<int, int>>, 20000> graph;
//
//
//vector<int> GetShortestPath(int start)
//{
//    // distance �迭 �����
//    // �߰ߵ��� ���� ������ ��� INF��.
//    vector<int> dist(V, INF);
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
//            int next = graph[v][node].second;
//            int nextW = graph[v][node].first;
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
//    scanf("%d %d", &V, &E);
//    scanf("%d", &K);
//
//    
//    for (int i = 0; i < E; ++i)
//    {
//        int u, v, w;
//        scanf("%d %d %d", &u, &v, &w);
//
//        
//        graph[u - 1].emplace_back(pair<int, int>(w, v - 1));
//    }
//    auto path = GetShortestPath(K-1);
//
//    
//    for (auto i : path)
//    {
//        if (i == INF)
//            printf("INF\n");
//        else
//            printf("%d\n", i);
//    }
//}
