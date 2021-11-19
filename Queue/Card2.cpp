#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

int queue[2000000] = { 0 };

int main()
{
    int N = 0;
    char command[32];
    int num = 0;
    int front = 0;
    int back = -1;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
    {
        scanf("%s", command);

        if (!strcmp(command, "push"))
        {
            scanf("%d", &num);
            queue[++back] = num;
        }
        else if (!strcmp(command, "pop"))
        {
            if (back - front == -1)
                printf("%d\n", -1);
            else
            {
                printf("%d\n", queue[front++]);
            }
        }
        else if (!strcmp(command, "size"))
        {
            printf("%d\n", back - front + 1);
        }
        else if (!strcmp(command, "empty"))
        {
            if (back - front == -1)
                printf("%d\n", 1);
            else
                printf("%d\n", 0);
        }
        else if (!strcmp(command, "front"))
        {
            if (back - front == -1)
                printf("%d\n", -1);
            else
                printf("%d\n", queue[front]);
        }
        else if (!strcmp(command, "back"))
        {
            if (back - front == -1)
                printf("%d\n", -1);
            else
                printf("%d\n", queue[back]);
        }
    }
}