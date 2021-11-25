#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <utility>

#define INF 987654321

using namespace std;

int V, E, K;

array<vector<pair<int, int>>, 20000> graph;

vector<int> dijkstra()
{
	vector<int> dist(V);

	for (int i = 0; i < V; ++i)
	{
		dist[i] = graph[K][i].second;
	}

	vector<bool> isVisited(V);
	isVisited[K] = true;

	for (int i = 0; i < V - 1; ++i)
	{
		size_t next = 0;
		size_t minDist = INF;

		for (size_t node = 0; node < V; ++node)
		{
			if (isVisited[node])
				continue;

			if (minDist > dist[node])
			{
				next = node;
				minDist = dist[node];
			}
		}

		isVisited[next] = true;

		for (size_t node = 0; node < V; ++node)
		{
			dist[node] = min(dist[node], dist[next] + graph[next][node]);
		}
	}

	return dist;
}

int main()
{
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	--K;

	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].emplace_back(pair<int, int>(v, w));
	}

	vector<int> result = dijkstra();
	for (int i = 0; i < result.size(); ++i)
	{
		printf("%d\n", result[i]);
	}
}