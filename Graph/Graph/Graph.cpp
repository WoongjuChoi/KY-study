#include <iostream>
#include "MyGraph.h"
#include "MyGraph2.h"

int main()
{
    MyGraph<EGraphType::Matrix, 7> gilhos;

    gilhos.AddEdge(0, 1, 32);
    gilhos.AddEdge(0, 2, 38);
    gilhos.AddEdge(0, 3, 23);
    gilhos.AddEdge(0, 4, 12);
    gilhos.AddEdge(0, 5, 8);

    gilhos.Print();

    cout << boolalpha << gilhos.IsAdjacent(0, 6);

    for (int i = 0; i < 7; ++i)
    {
        cout << gilhos.GetDegree(i) << endl;
    }

    MyGraph<EGraphType::List, 7> g2;

    g2.AddEdge(0, 1, 32);
    g2.AddEdge(0, 2, 38);
    g2.AddEdge(0, 3, 23);
    g2.AddEdge(0, 4, 12);
    g2.AddEdge(0, 5, 8);
     
    g2.Print();

    cout << boolalpha << g2.IsAdjacent(0, 6);

    for (int i = 0; i < 7; ++i)
    {
        cout << g2.GetDegree(i) << endl;
    }
}