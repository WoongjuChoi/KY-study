#pragma once
#include <utility>

class CircularSingleLinkedList
{
public:
    struct Node
    {
        Node(int data = 0, Node* next = nullptr)
            : Data{ data }, Next{ next } { }
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node() = default;

        int   Data = 0;
        Node* Next = nullptr;
    };

public:
    // �⺻ ������
    CircularSingleLinkedList()
    {
        _before_head->Next = _head;
        _before_tail->Next = _head;
    }

    // ���� ������
    CircularSingleLinkedList(const CircularSingleLinkedList& other)
        : CircularSingleLinkedList()
    {
        for (auto iter = other.before_head(); iter != other.before_tail(); ++iter)
        {
            push_back(iter->Data);
        }
    }

    // �Ҵ� ������
    CircularSingleLinkedList& operator=(const CircularSingleLinkedList& rhs)
    {
        if (this != &rhs)
        {
            CircularSingleLinkedList temp(rhs);
            std::swap(_before_head, temp._before_head);
            std::swap(_before_tail, temp._before_tail);
            std::swap(_head, temp._head);
            std::swap(_size, temp._size);
        }

        return *this;
    }

    // �Ҹ���
    ~CircularSingleLinkedList()
    {
        clear();

        _head = nullptr;
        _before_head = nullptr;
        _before_tail = nullptr;
        _size = 0;
    }

    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    int& front()
    {
        return _head->Data;
    }
    const int& front() const
    {
        return _head->Data;
    }

    // ������ ��Ҹ� ��ȯ�Ѵ�.
    int& back()
    {
        return _before_tail->Next->Data;
    }
    const int& back() const
    {
        return _before_tail->Next->Data;
    }

    // ���� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* before_head()
    {
        return _before_head;
    }
    const Node* before_head() const
    {
        return _before_head;
    }

    // �� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* before_tail()
    {
        return _before_tail;
    }
    const Node* before_tail() const
    {
        return _before_tail;
    }

    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* head()
    {
        return _head;
    }
    const Node* head() const
    {
        return _head;
    }

    // �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* tail()
    {
        return _before_tail->Next;
    }
    const Node* tail() const
    {
        return _before_tail->Next;
    }

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* insert_after(Node* pos, int value)
    {
        Node* newNode = new Node(value);
        if (pos == _before_head)
        {
            if (_size == 0)
            {
                newNode->Next = newNode;
            }
            else
            {
                newNode->Next = _head;
            }

            _head = newNode;
        }
        else if (pos == _before_tail)
        {
            newNode->Next = tail();
        }
        else if (pos == tail())
        {
            _before_tail = tail();
            newNode->Next = newNode;
        }
        
        pos->Next = newNode;
        ++_size;

        return newNode;
    }

    // pos ���� ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* erase_after(Node* pos)
    {
        Node* removed = pos->Next;

        if (removed == nullptr)
        {
            return;
        }

        pos->Next = removed->Next;

        return pos->Next;
    }

    // ���� ��ҿ� value�� �����Ѵ�.
    void      push_front(int value)
    {
        insert_after(before_head(), value);
    }

    // ������ ��ҿ� value�� �����Ѵ�.
    void      push_back(int value)
    {
        insert_after(tail(), value);
    }

    // ���� ��Ҹ� �����Ѵ�.
    void      pop_front() 
    {
        erase_after(before_head());
    }

    // ������ ��Ҹ� �����Ѵ�.
    void      pop_back()
    {
        erase_after(before_tail());
    }

    // �����̳ʰ� ������� �Ǵ��Ѵ�.
    bool      empty() const { return _size; }

    // �����̳ʸ� ���������.
    void      clear()
    {
        while (empty == false)
        {
            pop_back();
        }
    }

    // �����̳ʿ� value�� �ִ��� Ȯ���Ѵ�.
    bool      contains(int value) const
    {
        for (auto iter = head(); iter != tail(); ++iter)
        {
            if (iter->Data == value)
            {
                return true;
            }
        }

        return false;
    }

private:
    Node* _before_head = new Node();
    Node* _before_tail = _before_head;
    Node* _head = nullptr;
    size_t          _size = 0;
};
