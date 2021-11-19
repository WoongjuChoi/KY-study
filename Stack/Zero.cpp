//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//
//class Stack
//{
//public:
//    void push(int value) { _container.push_back(value); }
//    void pop()
//    {
//        if (!_container.empty())
//            _container.pop_back();
//    }
//
//    void result()
//    {
//        int res = 0;
//
//        while(!_container.empty())
//        {
//            res += _container.back();
//            _container.pop_back();
//        }
//
//        printf("%d", res);
//    }
//
//private:
//    vector<int> _container;
//};
//
//int main()
//{
//    int comNum = 0;
//    int num = 0;
//    Stack stack;
//
//    scanf("%d", &comNum);
//
//    for (int i = 0; i < comNum; ++i)
//    {
//        scanf("%d", &num);
//
//        if (num == 0)
//        {
//            stack.pop();
//        }
//        else
//        {
//            stack.push(num);
//        }
//    }
//
//    stack.result();
//}