#include <forward_list>
#include <iostream>
#include "CircularSingleLinkedList.h"

using namespace std;

int main()
{
	CircularSingleLinkedList<float> lst;

	lst.push_front(3.2);
	lst.push_front(2.2);
	lst.push_front(1.2);
	lst.push_back(4.2);


	auto iter = lst.head();
	iter = iter->Next;
	iter = iter->Next;

	lst.insert_after(iter, 10.2);

	cout << "Front : " << lst.front() << " , Back : " << lst.back() << endl;

	iter = lst.head();
	do
	{
		cout << iter->Data << "->";

		iter = iter->Next;
	} while (iter != lst.head());
	cout << iter->Data << endl;

	iter = lst.head();
	iter = iter->Next;
	lst.erase_after(iter);
}