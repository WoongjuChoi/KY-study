//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <set>
//
//using namespace std;
//
//int N, M, V;
//
//bool graph[1001][1001] = { false };
//
//void dfs(int node)
//{
//	static bool isVisited[1001] = { false };
//
//	stack<int> st;
//	st.push(node);
//
//	while (!st.empty())
//	{
//		int num = st.top();
//		st.pop();
//
//		if (isVisited[num])
//			continue;
//
//		isVisited[num] = true;
//		printf("%d ", num);
//
//		for (int i = N; i > 0; --i)
//		{
//			if (isVisited[i] == false && graph[num][i] == true)
//				st.push(i);
//		}
//	}
//}
//
//void bfs(int node)
//{
//	static bool isVisited[1001] = { false };
//
//	queue<int> q;
//	q.push(node);
//
//	while (!q.empty())
//	{
//		int num = q.front();
//		q.pop();
//
//		if (isVisited[num])
//			continue;
//
//		isVisited[num] = true;
//		printf("%d ", num);
//
//		for (int i = 1; i <= N; ++i)
//		{
//			if (isVisited[i] == false && graph[num][i] == true)
//				q.push(i);
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d %d %d", &N, &M, &V);
//
//	for (int i = 0; i < M; ++i)
//	{
//		int s, e;
//		scanf("%d %d", &s, &e);
//		graph[s][e] = true;
//		graph[e][s] = true;
//	}
//
//	dfs(V);
//	printf("\n");
//	bfs(V);
//}