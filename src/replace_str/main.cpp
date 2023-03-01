/**
 ******************************************************************************
 * @file           : main.cpp
 * @author         : jhZou
 * @brief          : None
 * @attention      : None
 * @date           : 2023/2/12
 ******************************************************************************
 */
#include <iostream>
#include <cstring>
#include <cstdlib>

using std::cout;
using std::endl;
using std::strlen;
using std::exit;

void streplace(char *s, int numblank, int length)
{
    int oldend = strlen(s) - 1;
    int newend = oldend + numblank * 2;

    if (newend > length)
    {
        cout << "数组内存空间不足" << endl;
        exit(EXIT_FAILURE);
    }

    while (oldend >= 0 && oldend < newend)
    {
        if (s[oldend] != ' ')
        {
            s[newend--] = s[oldend];
        }
        else
        {
            s[newend--] = '%';
            s[newend--] = '2';
            s[newend--] = '0';
        }
        oldend--;
    }
}

int main()
{
    char arr[30] = "hello world my love";
    streplace(arr, 3, sizeof(arr));
    cout << arr;
}
