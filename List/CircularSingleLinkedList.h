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
    // 기본 생성자
    CircularSingleLinkedList()
    {
        _before_head->Next = _head;
        _before_tail->Next = _head;
    }

    // 복사 생성자
    CircularSingleLinkedList(const CircularSingleLinkedList& other)
        : CircularSingleLinkedList()
    {
        for (auto iter = other.before_head(); iter != other.before_tail(); ++iter)
        {
            push_back(iter->Data);
        }
    }

    // 할당 연산자
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

    // 소멸자
    ~CircularSingleLinkedList()
    {
        clear();

        _head = nullptr;
        _before_head = nullptr;
        _before_tail = nullptr;
        _size = 0;
    }

    // 첫 번째 요소를 반환한다.
    int& front()
    {
        return _head->Data;
    }
    const int& front() const
    {
        return _head->Data;
    }

    // 마지막 요소를 반환한다.
    int& back()
    {
        return _before_tail->Next->Data;
    }
    const int& back() const
    {
        return _before_tail->Next->Data;
    }

    // 시작 전 요소를 가리키는 반복자를 반환한다.
    Node* before_head()
    {
        return _before_head;
    }
    const Node* before_head() const
    {
        return _before_head;
    }

    // 끝 전 요소를 가리키는 반복자를 반환한다.
    Node* before_tail()
    {
        return _before_tail;
    }
    const Node* before_tail() const
    {
        return _before_tail;
    }

    // 시작 요소를 가리키는 반복자를 반환한다.
    Node* head()
    {
        return _head;
    }
    const Node* head() const
    {
        return _head;
    }

    // 끝 요소를 가리키는 반복자를 반환한다.
    Node* tail()
    {
        return _before_tail->Next;
    }
    const Node* tail() const
    {
        return _before_tail->Next;
    }

    // pos 다음에 value를 삽입한다.
    // 삽입된 요소를 가리키는 반복자를 반환한다.
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

    // pos 다음 요소를 삭제한다.
    // 삭제된 요소의 다음 요소를 가리키는 반복자를 반환한다.
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

    // 시작 요소에 value를 삽입한다.
    void      push_front(int value)
    {
        insert_after(before_head(), value);
    }

    // 마지막 요소에 value를 삽입한다.
    void      push_back(int value)
    {
        insert_after(tail(), value);
    }

    // 시작 요소를 제거한다.
    void      pop_front() 
    {
        erase_after(before_head());
    }

    // 마지막 요소를 제거한다.
    void      pop_back()
    {
        erase_after(before_tail());
    }

    // 컨테이너가 비었는지 판단한다.
    bool      empty() const { return _size; }

    // 컨테이너를 비워버린다.
    void      clear()
    {
        while (empty == false)
        {
            pop_back();
        }
    }

    // 컨테이너에 value가 있는지 확인한다.
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
