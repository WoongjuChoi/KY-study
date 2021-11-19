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
//    // distance 배열 만들기
//    // 발견되지 않은 정점은 모두 INF다.
//    vector<int> dist(V, INF);
//    // 시작 정점은 거리가 0이다.
//    dist[start] = 0;
//
//    // 우선순위 큐를 이용한다.
//    priority_queue<pair<int, int>> pq;
//    // 시작 정점을 넣어준다.
//    pq.emplace(0, start);
//
//    // dist의 모든 값을 찾을 때까지
//    while (false == pq.empty())
//    {
//        // dist 중에서 가장 최소값을 가지는 정점을 뽑아낸다.
//        int w = -pq.top().first;
//        int v = pq.top().second;
//        pq.pop();
//
//        // 과거에 발견한 최단 경로와 현재 최단 경로를 비교한다.
//        // 과거에 발견한 최단 경로가 더 크다면 계산할 필요가 없다.
//        if (dist[v] < w)
//        {
//            continue;
//        }
//
//        // 해당 정점을 이용했을 때, 최단 거리를 찾을 수 있는지 체크한다.
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
