//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//
//vector<int> graph[10001];
//int parent[10001];
//
//void SetParent(int p, int c)
//{
//	parent[c] = p;
//
//	for (int n : graph[c])
//	{
//		if (parent[n] == 0)
//			SetParent(c, n);
//	}
//}
//
//int main()
//{
//	scanf("%d", &N);
//	for (int i = 0; i < N - 1; ++i)
//	{
//		int s, e;
//		scanf("%d %d", &s, &e);
//
//		graph[s].push_back(e);
//		graph[e].push_back(s);
//	}
//
//	SetParent(2, 2);
//
//	for (int i = 1; i <= N; ++i)
//	{
//		printf("%d", parent[i]);
//	}
//}