//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int BinarySearch(const vector<int>& vec, size_t s, size_t e, int value)
//{
//    if (s >= e)
//        return 0;
//
//    int m = (s + e) / 2;
//    if (vec[m] == value)
//    {
//        return 1;
//    }
//    else if (vec[m] < value)
//    {
//        return BinarySearch(vec, m + 1, e, value);
//    }
//    else
//    {
//        return BinarySearch(vec, s, m, value);
//    }
//}
//
//int main()
//{
//    int N = 0;
//    int num = 0;
//    vector<int> vec;
//
//    scanf("%d", &N);
//
//    for (int i = 0; i < N; ++i)
//    {
//        scanf("%d", &num);
//
//        vec.push_back(num);
//    }
//
//    sort(vec.begin(), vec.end());
//
//    scanf("%d", &N);
//
//    for (int i = 0; i < N; ++i)
//    {
//        scanf("%d", &num);
//        printf("%d\n", BinarySearch(vec, 0, vec.size(), num));
//    }
//}