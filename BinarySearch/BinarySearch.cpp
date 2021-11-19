//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <random>
//
//using namespace std;
//
//int BinarySearch(const vector<int>& vec, size_t s, size_t e, int value)
//{
//    if (s >= e)
//        return -1;
//
//    int m = (s + e) / 2;
//    if (vec[m] == value)
//    {
//        return m;
//    }
//    else if (vec[m] < value)
//    {
//        BinarySearch(vec, (m + 1), e, value);
//    }
//    else
//    {
//        BinarySearch(vec, s, m, value);
//    }
//}
//
//int main()
//{
//    vector<int> vec(1'000'000);
//    iota(vec.begin(), vec.end(), 1);
//
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<> distrib(1, vec.size());
//
//    {
//        int value = distrib(gen);
//        printf("BinarySearchR Test\n");
//        printf("Value : %d, Index : %d\n", value, BinarySearch(vec, 0, vec.size(), value));
//    }
//
//}