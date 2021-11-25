#pragma once

#include <utility>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;


class Set
{
	struct Node
	{
		Node(int data = 0, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr)
			: Data{ data }, Parent{ parent }, Left{ left }, Right{ right } { }
		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
		~Node() { Parent = Left = Right = nullptr; }

		int		Data = 0;
		Node*	Parent = nullptr;
		Node*	Left = nullptr;
		Node*	Right = nullptr;
	};
public:
	Set() = default;
	~Set() { clear(); }


	// Ʈ���� ���̸� ���Ѵ�
	int height() const
	{
		if (empty())
		{
			return -1;
		}

		queue<Node*> q;
		q.push(_root);

		int h = -1;

		while (q.empty() == false)
		{
			size_t sz = q.size();
			for (size_t i = 0; i < sz; ++i)
			{
				Node* node = q.front();
				q.pop();

				if (node->Left)
				{
					q.push(node->Left);
				}

				if (node->Right)
				{
					q.push(node->Right);
				}
			}

			++h;
		}

		return h;
	}

	int height2() const { return heightHelper(_root); }

	// Ʈ���� ������� Ȯ���Ѵ�.
	bool empty() const { return _root == nullptr; }

	// Ʈ���� ũ�⸦ ��ȯ�Ѵ�.
	size_t	size() const { return _size; }

	// Ʈ���� ����.
	void clear()
	{
		while (empty() == false)
		{
			erase(_root);
		}
	}

	// Ʈ���� ���� �����Ѵ�.
	pair<Node*, bool> insert(int value)
	{
		// ��Ʈ�϶�
		if (empty())
		{
 			_root = new Node(value);
			++_size;

			return make_pair(_root, true);
		}

		Node* inserted = _root;
		Node* parent = nullptr;

		// ������ ��ġ ã��
		while (inserted)
		{
			parent = inserted;

			if (inserted->Data == value)
			{
				return make_pair(inserted, false);
			}
			else if (inserted->Data < value)
			{
				inserted = inserted->Right;
			}
			else
			{
				inserted = inserted->Left;
			}
		}

		// ��ġ ã������ ��带 ����
		inserted = new Node(value, parent);

		if (parent->Data > value)
		{
			parent->Left = inserted;
		}
		else
		{
			parent->Right = inserted;
		}

		++_size;

		return make_pair(inserted, true);
	}

	// Ʈ������ ���� �����Ѵ�.
	void erase(Node* pos)
	{
		if (empty())
		{
			return;
		}

		if (pos->Parent == nullptr)
		{
			_root = pos->Left;
			_root->Parent = nullptr;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		// �ڽ��� ���� �� => �ܸ� ����� ��
		if (pos->Left == nullptr && pos->Right == nullptr)
		{
			if (pos->Parent->Left == pos)
			{
				pos->Parent->Left = nullptr;
			}
			else
			{
				pos->Parent->Right = nullptr;
			}

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		// �ڽ��� �ϳ��� ��
		if (pos->Left == nullptr) // �ڽ��� �����ʿ��� ���� ��
		{
			if (pos->Parent->Left == pos)
			{
				pos->Parent->Left = pos->Right;
			}
			else
			{
				pos->Parent->Right = pos->Right;
			}

			pos->Right->Parent = pos->Parent;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}
		else if (pos->Right == nullptr) // �ڽ��� ���ʿ��� ���� ��
		{
			if (pos->Parent->Left == pos)
			{
				pos->Parent->Left = pos->Left;
			}
			else
			{
				pos->Parent->Right = pos->Left;
			}

			pos->Left->Parent = pos->Parent;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		// �ڽ��� �� ���� ��
		Node* successor = pos->Left;
		while (successor->Right)
		{
			successor = successor->Right;
		}

		swap(pos->Data, successor->Data);

		erase(successor);

		return;
	}

	size_t erase(int value) // ������ ������ ����
	{
		Node* removed = find(value);
		if (removed == nullptr)
		{
			return 0;
		}

		erase(removed);

		return 1;
	}

	// Ʈ������ Ư�� ���� ã�´�.
	Node* find(int value)
	{
		return const_cast<Node*>(static_cast<const Set&>(*this).find(value));
	}

	const Node* find(int value) const
	{
		const Node* result = _root;

		while (result) // result�� nullptr�� �ƴ϶��
		{
			if (result->Data == value)
			{
				return result;
			}
			else if (result->Data < value)
			{
				result = result->Right;
			}
			else
			{
				result = result->Left;
			}
		}

		return result;
	}

	// ��ȸ
	void traverseByPreorder() { preOrderHelper(_root); }
	void traverseByInorder() { inOrderHelper(_root); }
	void traverseByPostorder() { postOrderHelper(_root); }
	void traverseByLevelorder()
	{
		if (empty())
		{
			return;
		}

		queue<Node*> q;
		q.push(_root);

		size_t h = 0;

		while (q.empty() == false)
		{
			cout << "Level " << h << " : ";
			size_t sz = q.size();
			for (size_t i = 0; i < sz; ++i)
			{
				Node* node = q.front();
				q.pop();

				printf("%d ", node->Data);

				if (node->Left)
				{
					q.push(node->Left);
				}

				if (node->Right)
				{
					q.push(node->Right);
				}
			}

			++h;
		}
	}

private:
	int heightHelper(const Node* node) const
	{
		if (node == nullptr)
		{
			return -1;
		}

		int left = heightHelper(node->Left) + 1;
		int right = heightHelper(node->Right) + 1;

		return max(left, right);
	}

	void preOrderHelper(const Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		cout << node->Data << ' ';
		preOrderHelper(node->Left);
		preOrderHelper(node->Right);
	}

	void inOrderHelper(const Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		inOrderHelper(node->Left);
		cout << node->Data << ' ';
		inOrderHelper(node->Right);
	}

	void postOrderHelper(const Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		postOrderHelper(node->Left);
		postOrderHelper(node->Right);
		cout << node->Data << ' ';
	}

private:
	Node* _root = nullptr;
	size_t _size = 0;
};