#pragma once
#include "SingleLinkedList.h"

class MyStack2
{
public:
    // �⺻ ������
    MyStack2() = default;

    // ���� ������
    MyStack2(const MyStack2& other)
        : _container{ other._container }
    {

    }

    // �Ҵ� ������
    MyStack2& operator=(const MyStack2& rhs)
    {
        if (this != &rhs)
        {
            _container = rhs._container;
        }
    }

    // �Ҹ���
    ~MyStack2() = default;

    // ������ �� �� ��ҿ� �����Ѵ�.
    int& top() { return _container.front(); }
    const int& top() const { return _container.front(); }

    // ������ ������� �˻��Ѵ�.
    bool            empty() const { return _container.empty(); }

    // ������ ũ�⸦ ��ȯ�Ѵ�.
    size_t          size() const { return _size; }

    // ���ÿ� �����͸� �����Ѵ�.
    void            push(int value) { _container.push_front(value); }

    // ���ÿ��� �����͸� �����Ѵ�.
    void            pop()
    {
        if (empty())
        {
            return;
        }

        _container.
    }
private:
    SingleLinkedList<int> _container;
    size_t _size;
};
