/**
 ******************************************************************************
 * @file           : test.cpp
 * @author         : jhZou
 * @brief          : None
 * @attention      : None
 * @date           : 2023/2/12
 ******************************************************************************
 */
#include <iostream>
#include <memory>//智能指针的头文件
class test
{
public:
    test(int d) :data(d){}
    int data;
};

inline void func(const int (&a)[3]){
    std::cout << a[0] << std::endl;
}

inline int** func1(int rows, int cols){
    auto prefix2d_ = new int *[rows + 1];
    for (int i = 0; i <= rows; i++)
        prefix2d_[i] = new int[cols + 1];
    prefix2d_[0][0] = 5;
    return prefix2d_;
}

int main()
{
    auto a = func1(2, 2);
    std::cout << a[0][0] << std::endl;
    func({1, 3, 4});
    test *p = new test(10);//初始化一个test对象
    std::shared_ptr<test> ptr(p);//构造一个智能指针对象，普通指针转智能指针
    std::cout << ptr->data<<std::endl;//智能指针的行为看起来和普通指针基本一致
    test *q;
    q = ptr.get();//ptr看起来是指针，但本质是对象，它也有成员函数
    std::cout << q->data;
    return 0;
}