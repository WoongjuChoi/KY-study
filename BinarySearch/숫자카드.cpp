#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void binarysearch(vector<int> vec, size_t s, size_t e, int value)
{
    int count = 0;

    while (s < e)
    {
        int m = (s + e) / 2;
        if (vec[m] == value)
        {
            count++;
            s++;
        }
        else if (vec[m] < value)
        {
            s = m + 1;
        }
        else
        {
            e = m;
        }
    }

    printf("%d ", count);
}

int main()
{
    int N = 0;
    int M = 0;
    int num = 0;
    vector<int> vec;

    scanf("%d", &N);

    vec.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &num);

        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    scanf("%d", &M);

    for (int i = 0; i < M; ++i)
    {
        scanf("%d", &num);
        binarysearch(vec, 0, vec.size(), num);
    }
}