#pragma once
#include <vector>
#include <utility>

using namespace std;

template <EGraphType type, size_t N>
class MyGraph;

template <size_t N>
class MyGraph<EGraphType::List, N>
{
public:
    // �� ������ �������� Ȯ���Ѵ�.
    bool        IsAdjacent(int start, int end)
    {
        for (const auto& edge : _edges[start])
        {
            if (edge.first == end)
            {
                return true;
            }
        }

        return false;
    }

    // ������ ���Ѵ�.
    int         GetDegree(int node)
    {
        int in = GetInDegree(node);
        int out = GetOutDegree(node);

        return in + out;
    }

    // ���� ������ ���Ѵ�.
    int         GetInDegree(int node)
    {
        int count = 0;
        
        for (size_t i = 0; i < _edges.size(); ++i)
        {
            if (i == node)
            {
                continue;
            }

            for (const auto& edge : _edges[i])
            {
                if (edge.first == node)
                {
                    ++count;
                }
            }
        }

        return count;
    }

    // ���� ������ ���Ѵ�.
    int         GetOutDegree(int node)
    {
        return _edges[node].size();
    }

    // ������ �߰��Ѵ�.
    void        AddEdge(int start, int end, int weight = 1)
    {
        _edges[start].push_back(pair<int, int>(end, weight));
    }

    // ������ �����Ѵ�.
    void        DeleteEdge(int start, int end)
    {
        for (auto iter = _edges[start].begin(); iter != _edges[start].end(); ++iter)
        {
            if (iter->first == end)
            {
                _edges[start].erase(iter);

                break;
            }
        }
    }

    // ����Ѵ�.
    // ����..
    // [ 1 ] : [ (3,1) (4,3) ]
    // [ 2 ] :
    // [ 3 ] :
    // [ 4 ] :
    // [ 5 ] : [ (2, 4) (3, 5) ]
    void        Print()
    {
        for (size_t r = 0; r < _edges.size(); ++r)
        {
            cout << "[ " << r << " ] : ";
            for (const auto& elem : _edges[r])
            {
                cout << "(" << elem.first << "," << elem.second << ") ";
            }
            cout << endl;
        }
    }

private:
    // pair : 2�� �̻��� �����͸� �������ִ� �ڷᱸ��
    array<vector<std::pair<int, int>>, N>       _edges;
};
