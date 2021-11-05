#pragma once

#include <cstddef>



template<typename T>
class DoubleLinkedList
{
public:
    struct Node
    {
        Node(int data = 0, Node* prev = nullptr, Node* next = nullptr)
            : Data{ data }, Prev{ prev }, Next{ next } {}
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node() = default;

        int     Data;
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
    class iterator : const_iterator
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

    void swap(T& a, T& b) noexcept
    {
        T temp = a;
        a = b;
        b = temp;
    }

    // �⺻ ������
    DoubleLinkedList() = default;

    // count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
    explicit DoubleLinkedList(size_t count)
        : DoubleLinkedList()
    {
        for (size_t i = 0; i < count; ++i)
        {
            push_front(0);
        }
    }

    // ���� ������.
    DoubleLinkedList(const DoubleLinkedList& other)
        : DoubleLinkedList()
    {
        /*auto inserted = end();
        for (auto iter = other.end()->Prev; iter != other.begin(); iter = iter->Prev)
        {
            inserted = insert(inserted, iter->Data);
        }*/

        for (auto iter = other.begin(); iter != other.end(); iter = iter->Next)
        {
            push_back(iter->Data);
        }
    }

    // �Ҵ� ������
    DoubleLinkedList& operator=(const DoubleLinkedList& rhs)
    {
        if (this != &rhs)
        {
            DoubleLinkedList temp(rhs);
            swap(_end, temp._end);
            swap(_head, temp._head);
            swap(_size, temp._size);
        }

        return *this;
    }

    // �Ҹ���
    ~DoubleLinkedList()
    {
        clear();
    }

    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    int& front() { return *begin(); }
    const int& front() const { return *begin(); }

    // ������ ��Ҹ� ��ȯ�Ѵ�.
    int& back() { return *(--end()); }
    const int& back() const { return *(--end()); }

    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // ����Ʈ�� ����ִٸ� end()�� ����.
    iterator begin() { return _head; } // �Ű������� �ϳ��� �����ڰ� ���� ��� �Ű����� Ÿ�Կ��� ������ Ÿ������ �ڵ� ����ȯ�ȴ�.(�Ͻ��� ����ȯ) _head�� Node* ���� const_iterator�� ����ȯ��
    const_iterator begin() const { return _head; }

    // �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator end() { return _end; }
    const_iterator end() const { return _end; }

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator insert(iterator pos, int value)
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

    // pos ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
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

    // ���ۿ� value�� �����Ѵ�.
    void            push_front(int value) { insert(begin(), value); }

    // ���� value�� �����Ѵ�.
    void            push_back(int value) { insert(end(), value); }

    // ���� ��Ҹ� �����Ѵ�.
    void            pop_front() { erase(begin()); }

    // �� ��Ҹ� �����Ѵ�.
    void            pop_back() { erase(end()->Prev); }

    // �����̳ʰ� ������� �Ǵ��Ѵ�.
    bool            empty() const { return _size == 0; }


    // ����Ʈ �ȿ� �ִ� ����� ������ ��ȯ�Ѵ�.
    size_t          size() const {  return _size; }

    // �����̳ʸ� ���������.
    void            clear()
    {
        while (empty() == false)
        {
            pop_front();
        }
    }


    // �ش� value�� �ִ��� üũ�Ѵ�.
    bool            contains(int value) const
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
