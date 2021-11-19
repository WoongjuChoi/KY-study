#pragma once
#include <utility>
#include "DoubleLinkedList.h"

class MyQueue
{
public:
    // �⺻ ������
    MyQueue() = default;

    // ���� ������
    MyQueue(const MyQueue& other)
        : _container{ other._container } {}

    // �Ҵ� ������
    MyQueue& operator=(const MyQueue& rhs)
    {
        if (this != &rhs)
        {
            _container = rhs._container;
        }

        return *this;
    }

    // �Ҹ���
    ~MyQueue() = default;

    // ť�� ù ��° ��ҿ� �����Ѵ�.
    int& front() { _container.front(); }
    const int& front() const { _container.front(); }

    // ť�� ������ ��ҿ� �����Ѵ�.
    int& back() { _container.back(); }
    const int& back() const { _container.back(); }

    // ť�� ������� Ȯ���Ѵ�.
    bool            empty() const { _container.empty(); }

    // ť�� ũ�⸦ ��ȯ�Ѵ�.
    size_t          size() const { _container.size(); }

    // ť�� �����͸� �����Ѵ�.
    void            push(int value) { _container.push_back(value); }

    // ť���� �����͸� ������.
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
