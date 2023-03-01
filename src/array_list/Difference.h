/**
 ******************************************************************************
 * @file           : Difference.h
 * @author         : jhZou
 * @brief          : None
 * @attention      : None
 * @date           : 2023/2/22
 ******************************************************************************
 */

#ifndef COFFER_DIFFERENCE_H
#define COFFER_DIFFERENCE_H

class Difference
{
private:
    int *diff_ = nullptr, *arr_= nullptr, len_= 0;
public:
    Difference(int *arr, int length);
    ~Difference(){delete[] diff_;}
    void changeArray(int start, int end, int val);
};

#endif // COFFER_DIFFERENCE_H
