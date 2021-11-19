//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <vector>
//#include <stack>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//
//char graph[25][25] = {'0'};
//static bool isVisited[25][25] = { false };
//
//int dfs(int r, int c)
//{
//	int result = 1;
//
//	isVisited[r][c] = true;
//
//	if (r - 1 >= 0 && graph[r - 1][c] == '1' && isVisited[r - 1][c] == false)
//		result += dfs(r - 1, c);
//
//	if (r + 1 < N && graph[r + 1][c] == '1' && isVisited[r + 1][c] == false)
//		result += dfs(r + 1, c);
//
//	if (c - 1 >= 0 && graph[r][c - 1] == '1' && isVisited[r][c - 1] == false)
//		result += dfs(r, c - 1);
//
//	if (c + 1 < N && graph[r][c + 1] == '1' && isVisited[r][c + 1] == false)
//		result += dfs(r, c + 1);
//
//	return result;
//} // 왜 조건문 else if로 하면 값이 이상하게 나오는걸까?
//
//int main()
//{
//	vector<int> numOfHouse;
//
//	scanf("%d", &N);
//
//	for (int i = 0; i < N; ++i)
//	{
//		scanf("%s", graph[i]);
//	}
//
//	for (int r = 0; r < N ; ++r)
//	{
//		for (int c = 0; c < N; ++c)
//		{
//			if (isVisited[r][c] == false && graph[r][c] == '1')
//			{
//				numOfHouse.push_back(dfs(r, c));
//			}
//		}
//	}
//
//	sort(numOfHouse.begin(), numOfHouse.end());
//	printf("%d\n", numOfHouse.size()); // 총 단지수
//	for (int i = 0; i < numOfHouse.size(); ++i)
//	{
//		printf("%d\n", numOfHouse[i]); // 각 단지에 속하는 집의 수
//	}
//}