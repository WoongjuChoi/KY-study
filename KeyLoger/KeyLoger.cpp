#include <iostream>
#include <list>
#include <string>

using namespace std;

void Command(list<char>& lst, list<char>::iterator& iter, char c)
{
    switch (c)
    {
    case '<':
        if (iter != lst.begin())
        {
            --iter;
        }
        break;
    case '>':
        if (iter != lst.end())
        {
            ++iter;
        }
        break;
    case '-':
        if (iter != lst.begin())
        {
            iter = lst.erase(--iter);
        }
        break;
    default:
        lst.insert(iter, c);
        break;
    }
}

void GetPassword()
{
    list<char> tempPass;
    list<char>::iterator iter = tempPass.end();
    string input;
    
    cin >> input;
    for (int i = 0; i < input.size(); ++i)
    {
        Command(tempPass, iter, input.at(i));
    }

    input.clear();

    for (iter = tempPass.begin(); iter != tempPass.end(); ++iter)
    {
        cout << *iter;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    int num = 0;

    cin >> num;
    for (int i = 0; i < num; ++i)
    {
        GetPassword();
        cout << endl;
    }
}