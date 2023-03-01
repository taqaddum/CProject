/**
 ******************************************************************************
 * @file           : NumArray.h
 * @author         : jhZou
 * @brief          : None
 * @attention      : None
 * @date           : 2023/2/20
 ******************************************************************************
 */

#ifndef COFFER_NUMARRAY_H
#define COFFER_NUMARRAY_H

class NumArray{
private:
    int *prefix_ = nullptr;
    int **prefix2d_ = nullptr;
    int r_ = 0;
public:
    NumArray(const int *arr, int length);
    NumArray(const int *arr, int rows, int cols);
    ~NumArray();
    int obtainRange(int low, int high);
    int obtainZone(const int (&left_up)[2], const int (&right_low)[2]);
};

#endif // COFFER_NUMARRAY_H
