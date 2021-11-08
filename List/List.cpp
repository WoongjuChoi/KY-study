#include <forward_list>
#include <iostream>
#include "DoubleLinkedList.h"
#include "SingleLinkedList.h"
#include "CircularSingleLinkedList.h"

using namespace std;


int main()
{
	DoubleLinkedList<float> lst;

	lst.push_back(4.5f);
	lst.push_back(5.2f);
	lst.push_front(2.4f);

	for (auto iter = lst.begin(); iter != lst.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}