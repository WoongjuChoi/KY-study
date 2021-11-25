#include <set>
#include <queue>
#include "Set.h"
#include "Heap.h"

using namespace std;

int main()
{
    //std::set<int> set = { 8, 3, 2, 5, 4, 10, 14, 11, 16 };
    //// 2 3 4 5 8 10 11 14 16
    //for (int data : set)
    //{
    //    cout << data << ' ';
    //}
    //cout << endl;
    //if (set.end() != set.find(2))
    //{
    //    cout << "Found 2\n";
    //}
    //if (set.end() == set.find(12))
    //{
    //    cout << "Not Found 12\n";
    //}
    //// 9
    //cout << "Size : " << set.size() << endl;
    //// false
    //cout << boolalpha << set.empty() << endl;
    //auto iter = set.begin(); // 2
    //++iter; // 3
    //++iter; // 4
    //set.erase(iter); // 4가 사라진다.
    //// 8
    //cout << "Size : " << set.size() << endl;

    //if (set.find(4) == set.end())
    //{
    //    cout << "Not Found 4\n";
    //}
    //set.clear();
    //// true
    //cout << set.empty() << endl;
    //puts("---------------------------------");
    //Set mySet;
    //mySet.insert(8);
    //mySet.insert(3);
    //mySet.insert(2);
    //mySet.insert(5);
    //mySet.insert(4);
    //mySet.insert(10);
    //mySet.insert(14);
    //mySet.insert(11);
    //mySet.insert(16);
    //if (mySet.find(2))
    //{
    //    cout << "Found 2\n";
    //}
    //if (mySet.find(12) == nullptr)
    //{
    //    cout << "Not Found 12\n";
    //}
    //// 9
    //cout << "Size : " << mySet.size() << endl;
    //// false
    //cout << mySet.empty() << endl;
    //mySet.erase(4);
    //// 8
    //cout << "Size : " << mySet.size() << endl;
    //if (mySet.find(4) == nullptr)
    //{
    //    cout << "Not Found 4\n";
    //}
    //// 8 3 2 5 10 14 11 16
    //mySet.traverseByPreorder();
    //puts("");

    //// 2 3 5 8 10 11 14 16
    //mySet.traverseByInorder();
    //puts("");
    //// 2 5 3 11 16 14 10 8
    //mySet.traverseByPostorder();
    //puts("");
    //// 8 3 10 2 5 14 11 16
    //mySet.traverseByLevelorder();
    //// 3
    //cout << "Height : " << mySet.height() << ' ' << mySet.height2() << endl;
    //mySet.clear();
    //// true
    //cout << mySet.empty() << endl;

    // -----------------------------------------------------------------------------------

    vector<int> data = { 77, 18, 58, 28, 12, 17, 19, 9, 44, 69 };
    priority_queue<int> q;
    for (int d : data)
    {
        q.push(d);
    }

    // 77 69 58 44 28 19 18 17 12 9
    while (false == q.empty())
    {
        int d = q.top();
        q.pop();

        cout << d << ' ';
    }

    puts("");
    puts("--------------------------------");

    Heap h;
    for (int d : data)
    {
        h.push(d);
    }

    // 77 69 58 44 28 19 18 17 12 9
    while (false == h.empty())
    {
        int d = h.top();
        h.pop();

        cout << d << ' ';
    }
}