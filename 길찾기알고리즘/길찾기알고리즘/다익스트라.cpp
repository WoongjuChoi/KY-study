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
//    // 1. distance / distance[i] : 시작 정점 -> i로 가는 최단 경로. distance[start] = 0 / 나머지는 INF
//    // 2. 발견한 정점 중 최단 경로의 정점(v)을 찾는다. => 힙(우선순위 큐)를 사용해 최적화 가능
//    // 3. 해당 정점(v)을 경유해서 갔을 때, 최단 경로가 있는지 탐색한다. distance[i] = min(distance[i], distance[v] + graph[v][i]);
//    // 4. 모든 정점에 대해서 최단 경로를 찾을 때까지 반복한다.
//    // 5. 
//    std::vector<int> dist(7);
//    for (int i = 0; i < 7; ++i)
//        dist[i] = graph[start][i];
//
//    // 방문한 정점 집합 만들기
//    std::vector<bool> isVisited(7);
//    isVisited[start] = true;
//
//    // 모든 정점에 대한 최단 경로를 찾을 때까지
//    for (int i = 0; i < 7 - 1; ++i)
//    {
//        // 방문하지 않은 정점 중 최솟값을 가지는 정점을 구함
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
//        // 방문 표시 => 방문한 정점은 최소 거리임을 보장함.
//        isVisited[next] = true;
//
//        // 경로 업데이트
//        for (size_t node = 0; node < 7; ++node)
//        {
//            dist[node] = std::min(dist[node], dist[next] + graph[next][node]);
//        }
//    }
//
//    return dist;
//}
//
//// O((V + E)logV)까지 최적화 (V는 정점의 개수, E는 한 정점의 주변의 노드)
//std::vector<int> GetShortestPath2(int start)
//{
//    // distance 배열 만들기
//    // 발견되지 않은 정점은 모두 INF다.
//    vector<int> dist(7, INF);
//    // 시작 정점은 거리가 0이다.
//    dist[start] = 0;
//
//    // 우선순위 큐를 이용한다. (값을 넣으면 자동 정렬) 디폴트는 최대값부터 출력됨
//    // pair : 첫 번째 값을 기준으로 정렬. 첫번째는 가중치, 두번째는 노드
//    priority_queue<pair<int, int>> pq;
//
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
//        // 해당 정점을 경유할 때, 최단 거리를 찾을 수 있는지 체크한다.
//        for (int node = 0; node < 7; ++node)
//        {
//            if (dist[node] > dist[v] + graph[v][node])
//            {
//                // 경로 업데이트
//                dist[node] = dist[v] + graph[v][node];
//
//                // 구현에 있어서 주의를 해야 함
//                // 힙은 큰 값부터 리턴하기때문에 가중치를 음수로 저장해야 거리가 짧은게 먼저 리턴됨
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
