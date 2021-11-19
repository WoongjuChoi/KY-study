#pragma once
#include <iostream>
#include <array>

using namespace std;

enum class EGraphType
{
    Matrix,
    List
};

template <EGraphType type, size_t N>
class MyGraph;

template <size_t N>
class MyGraph<EGraphType::Matrix, N>
{
public:
    // �� ������ �������� Ȯ���Ѵ�.
    bool        IsAdjacent(int start, int end)
    {
        if (_edges[start][end] != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
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

        for (int i = 0; i < _edges.size(); ++i)
        {
            if (_edges[i][node])
            {
                ++count;
            }
        }

        return count;
    }

    // ���� ������ ���Ѵ�.
    int         GetOutDegree(int node)
    {
        int count = 0;

        for (int i = 0; i < _edges.size(); ++i)
        {
            if (_edges[node][i])
            {
                ++count;
            }
        }

        return count;
    }

    // ������ �߰��Ѵ�.
    void        AddEdge(int start, int end, int weight = 1)
    {
        _edges[start][end] = weight;
    }

    // ������ �����Ѵ�.
    void        DeleteEdge(int start, int end)
    {
        _edges[start][end] = 0;
    }

    // ����Ѵ�.
    // ����..
    // [ 0 1 0 0 0 ]
    // [ 0 0 1 0 0 ]
    // [ 0 0 0 0 1 ]
    // [ 0 1 0 0 0 ]
    // [ 0 0 0 0 0 ]
    void        Print()
    {
        for (size_t i = 0; i < _edges.size(); ++i)
        {
            cout << "[ ";
            for (size_t j = 0; j < _edges.size(); ++j)
            {
                cout << _edges[i][j] << ' ';
            }
            cout << "]\n";
        }
    }

private:
    array<array<int, N>, N>     _edges = {};
};
