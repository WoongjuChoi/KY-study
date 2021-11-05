#pragma once

#include <algorithm>

template<typename T>
class SingleLinkedList
{
    struct Node
    {
        Node() = default;
        Node(const T& data, Node* next = nullptr)
            : Data{ data }, Next{ next } { }
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node()
        {
            Next = nullptr;
        }
        T     Data = {};
        Node* Next = nullptr;
    };
public:
    class const_iterator
    {
    public:
        const_iterator(Node* p = nullptr)
            : _p{ p } { }
        ~const_iterator() { _p = nullptr; }
        const T& operator*() const { return _p->Data; }
        const T* operator->() const { return &_p->Data; }
        const_iterator& operator++() { _p = _p->Next; return *this; }
        const_iterator      operator++(int)
        {
            auto temp = *this;
            _p = _p->Next;
            return temp;
        }
        bool                operator==(const const_iterator& rhs) const
        {
            return _p == rhs._p;
        }
        bool                operator!=(const const_iterator& rhs) const
        {
            return !(*this == rhs);
        }
        bool                operator==(nullptr_t p) const
        {
            return _p == nullptr;
        }
        bool                operator!=(nullptr_t p) const
        {
            // !(*this == nullptr);
            return _p != nullptr;
        }

    public:
        Node* _p = nullptr;
    };
    class iterator : public const_iterator
    {
    public:
        using const_iterator::const_iterator;
        T& operator*() const
        {
            return const_cast<T&>(const_iterator::operator*());
        }
        T* operator->() const
        {
            return const_cast<T*>(const_iterator::operator->());
        }
        iterator& operator++()
        {
            const_iterator::operator++();
            return *this;
        }
        iterator operator++(int)
        {
            iterator temp = *this;
            const_iterator::operator++();
            return temp;
        }
    };
public:
    // 기본 생성자
    SingleLinkedList()
    {
        _head->Next = _end;
    }
    // count만큼의 요소를 갖고 있는 컨테이너를 만드는 생성자
    explicit SingleLinkedList(size_t count)
        : SingleLinkedList()
    {
        for (size_t i = 0; i < count; ++i)
        {
            push_front({});
        }
    }
    // 복사 생성자.
    SingleLinkedList(const SingleLinkedList& other)
        : SingleLinkedList()
    {
        auto inserted = before_begin(); // begin()
        for (auto iter = other.begin(); iter != other.end(); ++iter)
        {
            inserted = insert_after(inserted, *iter);
        }
    }
    // 할당 연산자
    SingleLinkedList& operator=(const SingleLinkedList& rhs)
    {
        if (this != &rhs)
        {
            SingleLinkedList temp(rhs);
            std::swap(_head, temp._head);
            std::swap(_end, temp._end);
        }
        return *this;
    }
    // 소멸자
    ~SingleLinkedList()
    {
        clear();
        delete _head;
        _head = nullptr;
        delete _end;
        _end = nullptr;
    }
    // 첫 번째 요소를 반환한다.
    T& front() { return *begin(); }
    const T& front() const { return *begin(); }

    // 시작 전 요소를 가리키는 반복자를 반환한다.
    iterator before_begin() { return iterator(_head); }
    const_iterator before_begin() const { return const_iterator(_head); }

    // 시작 요소를 가리키는 반복자를 반환한다.
    iterator begin() { return iterator(_head->Next); }
    const_iterator begin() const { return const_iterator(_head->Next); }

    // 끝 다음 요소를 가리키는 반복자를 반환한다.
    iterator end() { return iterator(_end); }
    const_iterator end() const { return const_iterator(_end); }

    // pos 다음에 value를 삽입한다.
    // 삽입된 요소를 가리키는 반복자를 반환한다.
    iterator insert_after(iterator pos, const T& value)
    {
        Node* where = pos._p;
        Node* newNode = new Node(value);
        newNode->Next = where->Next;
        where->Next = newNode;
        return iterator(newNode);
    }
    // pos 다음 요소를 삭제한다.
    // 삭제된 요소를 가리키는 반복자를 반환한다.
    // 아무 요소도 없으면 end()를 반환한다.
    iterator erase_after(iterator pos)
    {
        Node* where = pos._p;
        Node* removed = where->Next;

        if (removed == nullptr)
        {
            return end();
        }
        where->Next = removed->Next;
        removed->Next = nullptr;
        return iterator(removed);
    }
    // 시작 요소에 value를 삽입한다.
    void            push_front(const T& value)
    {
        insert_after(before_begin(), value);
    }
    // 시작 요소를 제거한다.
    void            pop_front()
    {
        iterator removed = erase_after(before_begin());
        delete removed._p;
    }
    // 컨테이너가 비었는지 판단한다.
    bool            empty() const
    {
        if (begin() == end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // 컨테이너를 비워버린다.
    void            clear()
    {
        while (false == empty())
        {
            pop_front();
        }
    }
    // value가 있는지 없는지 검사한다.
    bool            contains(const T& value) const
    {
        for (auto iter = begin(); iter != end(); ++iter)
        {
            if (*iter == value)
            {
                return true;
            }
        }
        return false;
    }
private:
    Node* _head = new Node();
    Node* _end = new Node();
};
