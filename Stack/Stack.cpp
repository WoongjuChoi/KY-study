//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <string>
//
//using namespace std;
//
//class List
//{
//public:
//    struct Node
//    {
//        int data = 0;
//        Node* next = nullptr;
//        Node* before = nullptr;
//
//        Node() = default;
//        Node(int value) { data = value; }
//    };
//
//    List()
//    {
//        _end->before = _head;
//        _head->next = _end;
//    };
//
//    int back() { return _end->before->data; }
//
//    void push_back(int value)
//    {
//        Node* newNode = new Node(value);
//
//        newNode->next = _end;
//        newNode->before = _end->before;
//        newNode->before->next = newNode;
//        _end->before = newNode;
//
//        ++_size;
//    }
//
//    void pop_back()
//    {
//        if (_size == 0)
//            return;
//
//        Node* removed = _end->before;
//        removed->before->next = _end;
//        _end->before = removed->before;
//
//        delete removed;
//        removed = nullptr;
//
//        --_size;
//    }
//
//    bool empty() { return _size == 0; }
//    int size() { return _size; }
//
//private:
//    Node* _end = new Node;
//    Node* _head = _end;
//    int   _size = 0;
//};
//
//class Stack
//{
//public:
//    void push(int value) { _container.push_back(value); }
//    void pop()
//    {
//        if (_container.empty())
//            printf("%d\n", -1);
//        else
//        {
//            printf("%d\n", _container.back());
//            _container.pop_back();
//        }
//    }
//    void size() { printf("%d\n", _container.size()); }
//    void empty()
//    {
//        if (_container.empty())
//        {
//            printf("%d\n", 1);
//        }
//        else
//        {
//            printf("%d\n", 0);
//        }
//    }
//    void top()
//    {
//        if (_container.empty())
//            printf("%d\n", -1);
//        else
//            printf("%d\n", _container.back());
//    }
//
//private:
//    List _container;
//};
//
//bool isCorrect(char* input, string command)
//{
//    for (int i = 0; i < command.size(); ++i)
//    {
//        if (input[i] != command.at(i))
//            return false;
//    }
//
//    return true;
//}
//
//int main()
//{
//    int comNum = 0;
//    int num = 0;
//    char command[100];
//    Stack stack;
//
//    scanf("%d", &comNum);
//
//    for (int i = 0; i < comNum; ++i)
//    {
//        scanf("%s", command);
//
//        if (isCorrect(command,"push"))
//        {
//            scanf("%d", &num);
//            stack.push(num);
//        }
//        else if (isCorrect(command, "pop"))
//        {
//            stack.pop();
//        }
//        else if (isCorrect(command, "size"))
//        {
//            stack.size();
//        }
//        else if (isCorrect(command, "empty"))
//        {
//            stack.empty();
//        }
//        else if (isCorrect(command, "top"))
//        {
//            stack.top();
//        }
//    }
//}