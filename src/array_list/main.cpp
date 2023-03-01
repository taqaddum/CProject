/**
 ******************************************************************************
 * @file           : main.cpp
 * @author         : jhZou
 * @brief          : None
 * @attention      : None
 * @date           : 2023/2/17
 ******************************************************************************
 */
#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include "NumArray.h"
#include "Difference.h"

using std::cout;
using std::endl;
using std::cin;
using std::printf;
using std::string;
using std::length_error;
using std::unordered_map;

struct TwoIndices
{
    int first, second;
};

inline void rotateArray2D(int *arr, int rows, int cols)
{
    auto reverse = [rows, cols](int *arr) {
        for (int i = 0; i < rows; i++)
        {
            int start = 0, end = cols - 1;
            while (start < end)
            {
                int temp = arr[i * cols + start];
                arr[i * cols + start] = arr[i * cols + end];
                arr[i * cols + end] = temp;
                start++, end--;
            }
        }
    };

    for(int i=0;i<rows;i++){
        for (int j = i; j < cols; j++)
        {
            int temp = arr[i * cols + j];
            arr[i * cols + j] = arr[j * cols + i];
            arr[j * cols + i] = temp;
        }
    }
    reverse(arr);
}

inline TwoIndices matchSum(const int *ptr, int length, int value)
{
    int low = 0, high = length - 1;
    TwoIndices result{-1, -1};
    while (low <= high)
    {
        int sum = ptr[low] + ptr[high];
        if (sum == value)
        {
            result.first = low;
            result.second = high;
            break;
        }
        else if (sum < value)
            low++;
        else
            high--;
    }
    return result;
}

inline int binarySearch(const int *ptr, int length, int value)
{
    int low = 0, high = length - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (ptr[mid] == value)
            return mid;
        else if (ptr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

inline int binarySearchRecursion(const int *arr, int low, int high, int val){
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] < val)
        {
            return binarySearchRecursion(arr, mid + 1, high, val);
        }
        else if (arr[mid] > val)
        {
            return binarySearchRecursion(arr, low, mid - 1, val);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

inline int removeArrayElement(int *arr, int length, int value)
{
    int slow = 0, fast = 0;
    while (fast < length)
    {
        if (arr[fast] != value)
        {
            arr[slow] = arr[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}

inline int removeDuplicateArray(int *arr, int length)
{
    if (length <= 0)
        throw length_error("长度错误");
    int slow = 0, fast = 0;
    while (fast < length)
    {
        if (arr[slow] != arr[fast])
        {
            slow++;
            arr[slow] = arr[fast];
        }
        fast++;
    }
    return slow + 1;
}

inline bool isPalindrome(char *start, char *end)
{
    while (start < end)
    {
        if (*start++ != *end--)
            return false;
    }
    return true;
}

inline string getMaxPalindrome(const string &s)
{
    string res;
    auto palindrome = [s](int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    };
    for (int i = 0; i < s.length(); i++)
    {
        string s1 = palindrome(i, i);
        string s2 = palindrome(i, i + 1);
        res = res.size() > s1.size() ? res : s1;
        res = res.size() > s2.size() ? res : s2;
    }
    return res;
}

string windowSlideSubstring(string s, string t)
{
    unordered_map<char, int> windows, needs;
    for (auto x : t)
        needs[x]++;
    int left = 0, right = 0, len = INT32_MAX, valid = 0, start = 0;
    while (right < s.size())
    {
        char c = s[right];
        if (needs.count(c))
        {
            windows[c]++;
            if (windows[c] == needs[c])
            {
                valid++;
            }
        }
        right++;
        while (valid == t.size())
        {
            char d = s[left];
            if (right - left < len)
            {
                start = left, len = right - left;
            }
            if (needs.count(d))
            {
                if (windows[d] == needs[d])
                {
                    valid--;
                }
                windows[d]--;
            }
            left++;
        }
    }
    return s.substr(start, len);
}

int getNoRepeatMaxLengthSub(string s)
{
    unordered_map<char, int> windows;
    int left = 0, right = 0, res = 0;
    while (right < s.size())
    {
        char c = s[right];
        windows[c]++;
        right++;
        while (windows[c] > 1)
        {
            char d = s[left];
            windows[d]--;
            left++;
        }
        res = std::max(res, right - left);
    }
    return res;
}

int main()
{
    int arr[10] = {1, 2, 2, 2, 4, 5, 6, 6, 8, 9};
    int arrb[10] = {2, 2, 3, 1, 1, 6, 4, 7, 8, 8};
    int binarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
    int arr2d[5][4] = {{1, 2, 4, 5},
                       {3, 6, 7, 8},
                       {2, 2, 4, 8},
                       {1, 5, 6, 8},
                       {9, 10, 12, 12}};
    int arrc[4][4] = {{1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 16}};
    auto show = [](int *p, int length) {
        for (int i = 0; i < length; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    };
    cout<<getNoRepeatMaxLengthSub("abbbacadabdac")<<endl;
    cout << windowSlideSubstring("abbcada", "abc") << endl;
    rotateArray2D((int *)arrc, 4, 4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%-3d", arrc[i][j]);
        }
        cout << endl;
    }
    Difference df(binarr, 10);
    df.changeArray(1, 4, 3);
    for (auto x : binarr)
    {
        cout << x << ' ';
    }
    cout << endl;

    NumArray ndarray(binarr, 10);
    cout << "区间元素和为:" << ndarray.obtainRange(1, 6) << endl;
    NumArray ndarray2d((int *)arr2d, 5, 4);
    cout << "范围元素和为：" << ndarray2d.obtainZone({1, 1}, {3, 3}) << endl;
    auto result = matchSum(binarr, 10, 10);
    cout << result.first << ' ' << result.second << endl;
    cout << binarySearch(binarr, 10, 12) << endl;
    int len = removeDuplicateArray(arr, 10);
    int lenb = removeArrayElement(arrb, 10, 8);
    show(arr, len);
    show(arrb, lenb);
    string a;
    string b = "abc";
    cout << b.substr(2, 0) << endl;
    cout << "Input string:";
    cin >> a;
    cout << getMaxPalindrome(a) << endl;
}
