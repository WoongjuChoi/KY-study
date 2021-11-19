#pragma once

#include <cstddef>
#include <utility>

template<typename T>
class DoubleLinkedList
{
    struct Node
    {
        Node() = default;
        Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
            : Data{ data }, Prev{ prev }, Next{ next } {}
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node() = default;

        T     Data;
        Node* Next;
        Node* Prev;
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
        const_iterator operator++(int)
        {
            auto temp = *this;
            _p = _p->Next;
            return temp;
        }
        const_iterator& operator--() { _p = _p->Prev; return *this; }
        const_iterator operator--(int)
        {
            auto temp = *this;
            _p = _p->Prev;
            return temp;
        }
        bool                operator==(const const_iterator& rhs) const
        {
            return _p == rhs._p;
        }
    public:
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
        iterator& operator--()
        {
            const_iterator::operator--();
            return *this;
        }
        iterator operator--(int)
        {
            iterator temp = *this;
            const_iterator::operator--();
            return temp;
        }
    };

   /* void swap(T& a, T& b) noexcept
    {
        T temp = a;
        a = b;
        b = temp;
    }*/

    // 기본 생성자
    DoubleLinkedList() = default;

    // count만큼의 요소를 갖고 있는 컨테이너를 만드는 생성자
    explicit DoubleLinkedList(size_t count)
        : DoubleLinkedList()
    {
        for (size_t i = 0; i < count; ++i)
        {
            push_front({});
        }
    }

    // 복사 생성자.
    DoubleLinkedList(const DoubleLinkedList& other)
        : DoubleLinkedList()
    {
        /*auto inserted = end();
        for (auto iter = other.end()->Prev; iter != other.begin(); iter = iter->Prev)
        {
            inserted = insert(inserted, iter->Data);
        }*/

        for (auto iter = other.begin(); iter != other.end(); ++iter)
        {
            push_back(*iter);
        }
    }

    // 할당 연산자
    DoubleLinkedList& operator=(const DoubleLinkedList& rhs)
    {
        if (this != &rhs)
        {
            DoubleLinkedList temp(rhs);
            std::swap(_end, temp._end);
            std::swap(_head, temp._head);
            std::swap(_size, temp._size);
        }

        return *this;
    }

    // 소멸자
    ~DoubleLinkedList()
    {
        clear();

        delete _end;
        _end = nullptr;
        _head = nullptr;
        _size = 0;
    }

    // 첫 번째 요소를 반환한다.
    T& front() { return *begin(); }
    const T& front() const { return *begin(); }

    // 마지막 요소를 반환한다.
    T& back() { return *(--end()); }
    const T& back() const { return *(--end()); }

    // 시작 요소를 가리키는 반복자를 반환한다.
    // 리스트가 비어있다면 end()와 같다.
    iterator begin() { return _head; } // 매개변수가 하나인 생성자가 있을 경우 매개변수 타입에서 생성자 타입으로 자동 형변환된다.(암시적 형변환) _head가 Node* 에서 const_iterator로 형변환됨
    const_iterator begin() const { return _head; }

    // 끝 다음 요소를 가리키는 반복자를 반환한다.
    iterator end() { return _end; }
    const_iterator end() const { return _end; }

    // pos 이전에 value를 삽입한다.
    // 삽입된 요소를 가리키는 반복자를 반환한다.
    iterator insert(iterator pos, const T& value)
    {
        Node* where = pos._p;
        Node* newNode = new Node(value);
        Node* prevNode = where->Prev;

        where->Prev = newNode;
        if (prevNode != nullptr)
        {
            prevNode->Next = newNode;
        }
        newNode->Prev = prevNode;
        newNode->Next = where;

        if (where == _head)
        {
            _head = newNode;
        }

        ++_size;

        return iterator(newNode);
    }

    // pos 요소를 삭제한다.
    // 삭제된 요소의 다음 요소를 가리키는 반복자를 반환한다.
    // 아무 요소도 없으면 end()를 반환한다.
    iterator erase(iterator pos)
    {
        if (empty())
        {
            return end();
        }

        Node* where = pos._p;
        Node* prevNode = where->Prev;
        Node* nextNode = where->Next;

        if (prevNode != nullptr)
        {
            prevNode->Next = nextNode;
        }

        if (nextNode != nullptr)
        {
            nextNode->Prev = prevNode;
        }

        if (where == _head)
        {
            _head = nextNode;
        }

        delete where;
        where = nullptr;

        --_size;

        return iterator(nextNode);
    }

    // 시작에 value를 삽입한다.
    void            push_front(const T& value) { insert(begin(), value); }

    // 끝에 value를 삽입한다.
    void            push_back(const T& value) { insert(end(), value); }

    // 시작 요소를 제거한다.
    void            pop_front() { erase(begin()); }

    // 끝 요소를 제거한다.
    void            pop_back() { erase(--end()); }

    // 컨테이너가 비었는지 판단한다.
    bool            empty() const { return _size == 0; }


    // 리스트 안에 있는 요소의 개수를 반환한다.
    size_t          size() const {  return _size; }

    // 컨테이너를 비워버린다.
    void            clear()
    {
        while (empty() == false)
        {
            pop_front();
        }
    }


    // 해당 value가 있는지 체크한다.
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
    Node*           _end = new Node();
    Node*           _head = _end;
    size_t          _size = 0;
};

