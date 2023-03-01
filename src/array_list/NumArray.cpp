/**
 ******************************************************************************
 * @file           : NumArray.cpp
 * @author         : jhZou
 * @brief          : None
 * @attention      : None
 * @date           : 2023/2/20
 ******************************************************************************
 */

#include "NumArray.h"
#include <stdexcept>

using std::length_error;

NumArray::NumArray(const int *arr, int length)
{
    if (length <= 0)
        throw length_error("长度必须为正整数");
    prefix_ = new int[length + 1];
    for (int i = 1; i <= length; i++)
    {
        prefix_[i] = prefix_[i - 1] + arr[i - 1];
    }
}

NumArray::NumArray(const int *arr, int rows, int cols) : r_(rows)
{
    prefix2d_ = new int *[rows + 1];
    for (int i = 0; i <= rows; i++)
        prefix2d_[i] = new int[cols + 1];

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            prefix2d_[i][j] =
                prefix2d_[i - 1][j] + prefix2d_[i][j - 1] + arr[(i - 1) * cols + (j - 1)] - prefix2d_[i - 1][j - 1];
        }
    }
}

NumArray::~NumArray()
{
    delete[] prefix_;
    for (int i = 0; i < r_; i++)
    {
        delete[] prefix2d_[i];
    }
    delete[] prefix2d_;
}

int NumArray::obtainRange(int low, int high)
{
    return prefix_[high + 1] - prefix_[low];
}
/*!
 * 求二维数组指定区域内元素和
 * @param left_up 起始元素所在行列
 * @param right_low 终止元素所在行列
 * @return 返回元素和
 */
int NumArray::obtainZone(const int (&left_up)[2], const int (&right_low)[2])
{
    int x1 = left_up[0], y1 = left_up[1], x2 = right_low[0], y2 = right_low[1];
    return prefix2d_[x2 + 1][y2 + 1] - prefix2d_[x1][y2 + 1] - prefix2d_[x2 + 1][y1] + prefix2d_[x1][y1];
}
