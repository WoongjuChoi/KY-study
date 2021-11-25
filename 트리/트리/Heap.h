#pragma once

#include <vector>

class Heap
{
public:
	Heap() = default;
	~Heap() = default;

	// �ִ� ���Ҹ� ��ȯ�Ѵ�.
	const int& top() const { return _container.front(); }

	// ���� ����ִ��� Ȯ���Ѵ�.
	bool empty() const { return _container.empty(); }

	// ���� ũ�⸦ ��ȯ�Ѵ�.
	size_t size() const { return _container.size(); }

	// ���� ���Ҹ� �����Ѵ�.
	void push(int value)
	{
		// ������ ��忡 ���� �߰��Ѵ�.
		_container.push_back(value);

		// �θ�� ���ϸ鼭 ��ġ�� �ٲ��ش�. ���� �Һ����� ������ ������
		// �θ� ��尡 �׻� �ڽ� ��庸�� Ŀ�� �Ѵ�.

		size_t curr = _container.size();
		size_t parent = curr / 2;

		while (curr > 0 && _container[parent - 1] < _container[curr - 1])
		{
			std::swap(_container[parent], _container[curr]);

			curr = parent;
			parent = curr / 2;
		}
	}

	// ������ ���Ҹ� �����Ѵ�.
	void pop()
	{
		if (empty())
		{
			return;
		}

		// ���� ������ ��带 ��Ʈ ���� ������ش�.
		_container[0] = _container[size() - 1];
		_container.pop_back();

		// ���� �Һ����� ������ �� ���� �ڽ� ���� �ٲ��ش�.
		size_t curr = 1;
		size_t child = 2;

		while (child <= _container.size())
		{
			// ������ �ڽ��� ���� �ڽĺ��� �� ũ�ٸ�
			if (child + 1 < _container.size() && _container[child - 1] < _container[child + 1 - 1])
			{
				// ������ �ڽİ� ���Ѵ�
				++child;
			}

			// �̹� ���� �Һ����� �����Ѵٸ� �ߴ��Ѵ�.
			if (_container[curr - 1] >= _container[child - 1])
			{
				break;
			}

			std::swap(_container[curr - 1], _container[child - 1]);
			curr = child;
			child = curr * 2;
		}
	}

private:
	std::vector<int> _container;
};