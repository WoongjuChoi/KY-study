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
//int N, M;
//
//bool graph[101][101] = { false };
//
//int dfs()
//{
//	int count = -1;
//	static bool isVisited[101] = { false };
//
//	stack<int> st;
//	st.push(1);
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
//		count++;
//
//		for (int i = N; i > 0; --i)
//		{
//			if (isVisited[i] == false && graph[num][i] == true)
//				st.push(i);
//		}
//	}
//
//	return count;
//}
//
//int main()
//{
//	scanf("%d %d", &N, &M);
//
//	for (int i = 0; i < M; ++i)
//	{
//		int s, e;
//		scanf("%d %d", &s, &e);
//		graph[s][e] = true;
//		graph[e][s] = true;
//	}
//
//	printf("%d", dfs());
//}