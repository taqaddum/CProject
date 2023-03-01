/**
 ******************************************************************************
 * @file           : Difference.cpp
 * @author         : jhZou
 * @brief          : None
 * @attention      : None
 * @date           : 2023/2/22
 ******************************************************************************
 */

#include <stdexcept>
#include "Difference.h"

using std::length_error;

Difference::Difference(int *arr, int length) : len_(length), arr_(arr)
{
    if(length<=0) throw length_error("Length must be Integer");
    diff_ = new int [length];
    diff_[0] = arr[0];
    for (int i = 1; i < length; i++)
    {
        diff_[i] = arr[i] - arr[i - 1];
    }
}

void Difference::changeArray(int start, int end, int val)
{
    diff_[start] += val;
    if(end < len_ - 1) diff_[end + 1] -= val;
    for(int i=1;i<len_;i++){
        arr_[i] = arr_[i - 1] + diff_[i];
    }
}
