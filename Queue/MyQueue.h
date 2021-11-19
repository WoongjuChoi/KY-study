#pragma once
#include <utility>
#include "DoubleLinkedList.h"

class MyQueue
{
public:
    // 기본 생성자
    MyQueue() = default;

    // 복사 생성자
    MyQueue(const MyQueue& other)
        : _container{ other._container } {}

    // 할당 연산자
    MyQueue& operator=(const MyQueue& rhs)
    {
        if (this != &rhs)
        {
            _container = rhs._container;
        }

        return *this;
    }

    // 소멸자
    ~MyQueue() = default;

    // 큐의 첫 번째 요소에 접근한다.
    int& front() { _container.front(); }
    const int& front() const { _container.front(); }

    // 큐의 마지막 요소에 접근한다.
    int& back() { _container.back(); }
    const int& back() const { _container.back(); }

    // 큐가 비었는지 확인한다.
    bool            empty() const { _container.empty(); }

    // 큐의 크기를 반환한다.
    size_t          size() const { _container.size(); }

    // 큐에 데이터를 삽입한다.
    void            push(int value) { _container.push_back(value); }

    // 큐에서 데이터를 꺼낸다.
    void            pop() 
    {
        if (empty())
            return;
        else
            _container.pop_front(); 
    }

private:
    DoubleLinkedList<int>        _container;
};
