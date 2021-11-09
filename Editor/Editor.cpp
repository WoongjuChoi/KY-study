#include <iostream>
#include <stdio.h>
#include <list>
#include <string>


using namespace std;


void EditorControl(list<char>& lst, list<char>::iterator& iter)
{
    char input;

    cin >> input;

    if (input == 'L')
    {
        if (iter != lst.begin())
        {
            --iter;
        }
    }
    else if (input == 'D')
    {
        if (iter != lst.end())
        {
            ++iter;
        }
    }
    else if (input == 'B')
    {
        if (iter != lst.begin())
        {
            iter = lst.erase(--iter);
        }
    }
    else if (input == 'P')
    {
        char ch;
        cin >> ch;
        lst.insert(iter, ch);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    string str;
    int num = 0;
    char temp;

    getline(cin, str);
    list<char> lst(str.begin(), str.end());

    list<char>::iterator iter = lst.end();

    cin >> num;
    
    for (int i = 0; i < num; ++i)
    {
        EditorControl(lst, iter);
    }

    for (iter = lst.begin(); iter != lst.end(); ++iter)
    {
        cout << *iter;
    }
}