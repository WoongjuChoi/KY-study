#pragma once
#include <utility>

template<typename T>
class CircularSingleLinkedList
{
public:
    struct Node
    {
        Node(const T& data = {}, Node* next = nullptr)
            : Data{ data }, Next{ next } { }
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node() = default;

        T   Data = {};
        Node* Next = nullptr;
    };

public:
    // �⺻ ������
    CircularSingleLinkedList() = default;

    // ���� ������
    CircularSingleLinkedList(const CircularSingleLinkedList& other)
        : CircularSingleLinkedList()
    {
        if (other.empty())
        {
            return;
        }
        auto iter = other.head();
        do
        {
            push_back(iter->Data);

            iter = iter->Next;
        } while (iter != other.head());
    }

    // �Ҵ� ������
    CircularSingleLinkedList& operator=(const CircularSingleLinkedList& rhs)
    {
        if (this != &rhs)
        {
            CircularSingleLinkedList temp(rhs);
            std::swap(_before_head, temp._before_head);
            std::swap(_before_tail, temp._before_tail);
        }

        return *this;
    }

    // �Ҹ���
    ~CircularSingleLinkedList()
    {
        clear();

        delete _before_head;
        _before_head = nullptr;
        _before_tail = nullptr;
    }

    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    T& front()
    {
        return head()->Data;
    }
    const T& front() const
    {
        return head()->Data;
    }

    // ������ ��Ҹ� ��ȯ�Ѵ�.
    T& back()
    {
        return tail()->Data;
    }
    const T& back() const
    {
        return tail()->Data;
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
        return before_head()->Next;
    }
    const Node* head() const
    {
        return before_head()->Next;
    }

    // �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* tail()
    {
        return before_tail()->Next;
    }
    const Node* tail() const
    {
        return before_tail()->Next;
    }

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* insert_after(Node* pos, const T& value)
    {
        Node* newNode = new Node(value);
        newNode->Next = pos->Next;
        pos->Next = newNode;

        // ù ��° ���Ұ� ���Ե� ��
        if (head()->Next == nullptr)
        {
            head()->Next = head();
        }
        // �� ��° ���Ұ� ���Ե� ��
        // _before_tail�� ��ġ�� �Ű���� ��
        else if (before_head() == before_tail())
        {
            _before_tail = head();
            tail()->Next = head();
        }
        // _before_tail/ tail�� ���Ե� ��
        // _before_tail��  newNode�� �Ű��־�� ��
        else if (pos == before_tail() || pos == tail())
        {
            _before_tail = _before_tail->Next;
        }
        // _before_head�� ������ ��
        else if (pos == before_head())
        {
            tail()->Next = head();
        }

        return newNode;
    }

    // pos ���� ��Ҹ� �����Ѵ�.
    // ������ ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* erase_after(Node* pos)
    {
        if (empty())
        {
            return tail();
        }

        Node* removed = pos->Next;

        // ���Ұ� �ϳ��� ��
        if (head()->Next == head())
        {
            before_head()->Next = nullptr;
        }
        // ���Ұ� �� ���� ��
        else if (before_tail() == head())
        {
            before_head()->Next = removed->Next;

            _before_tail = before_head();

            tail()->Next = head();
        }
        // tail�� �����Ϸ��� �� ��
        else if (pos == before_tail())
        {
            before_tail()->Next = removed->Next;

            while (tail()->Next != head())
            {
                _before_tail = _before_tail->Next;
            }
        }
        // before_tail�� ���ŵ� ��
        else if (pos->Next == before_tail())
        {
            pos->Next = removed->Next;

            _before_tail = pos;
        }
        // ù �κ��� ���ŵ� ��
        else if (pos->Next == head())
        {
            before_head()->Next = removed->Next;

            tail()->Next = head();
        }
        else
        {
            pos->Next = removed->Next;
        }

        removed->Next = nullptr;

        return removed;
    }

    // ���� ��ҿ� value�� �����Ѵ�.
    void      push_front(const T& value)
    {
        insert_after(before_head(), value);
    }

    // ������ ��ҿ� value�� �����Ѵ�.
    void      push_back(const T& value)
    {
        if (empty())
            insert_after(before_head(), value);
        else
            insert_after(tail(), value);
    }

    // ���� ��Ҹ� �����Ѵ�.
    void      pop_front()
    {
        Node* erased = erase_after(before_head());
        delete erased;
    }

    // ������ ��Ҹ� �����Ѵ�.
    void      pop_back()
    {
        Node* erased = erase_after(before_tail());
        delete erased;
    }

    // �����̳ʰ� ������� �Ǵ��Ѵ�.
    bool      empty() const { return head() == nullptr; }

    // �����̳ʸ� ���������.
    void      clear()
    {
        while (empty() == false)
        {
            pop_back();
        }
    }

    // �����̳ʿ� value�� �ִ��� Ȯ���Ѵ�.
    bool      contains(const T& value) const
    {
        if (empty())
        {
            return false;
        }

        auto iter = head();
        do
        {
            if (iter->Data == value)
                return true;

            iter = iter->Next;
        } while (iter != head());

        return false;
    }

private:
    Node* _before_head = new Node();
    Node* _before_tail = _before_head;
};
