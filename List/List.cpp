#include <forward_list>
#include "DoubleLinkedList.h"
#include <iostream>​
#include <list>
#include "SingleLinkedList.h"

using namespace std;


int main()
{
	list<int> list;

	list.push_back(4);
	list.push_back(5);
	list.push_front(2);

	for (auto iter = list.begin(); iter != list.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}