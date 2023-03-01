#include <iostream>

struct ABS
{
    int num, row, col;
};

/*!
 * 查找有序整型二维数组中的匹配值
 * @param mat 二维数组指针
 * @param row 行数
 * @param col 列数
 * @param founder 匹配结构体
 * @return 匹配成功返回ture,默认返回false
 */
bool searchMatrix(const int *mat, int row, int col, ABS &founder)
{
    if (row <= 0 || col <= 0 || founder.num < 0)
        throw "输入必须为正整数！！！";

    bool flag = false;
    int r = 0, c = col - 1;

    while (c >= 0 && r < row)
    {
        if (mat[r * col + c] == founder.num)
        {
            flag = true;
            break;
        }

        else if (mat[r * col + c] > founder.num)
            c--;
        else
            r++;
    }

    founder.row = r;
    founder.col = c;
    return flag;
}

int main()
{
    using std::printf;
    int arr[][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ABS founder{};

    std::cout << "输入待匹配整数:";

    try
    {
        if (std::cin >> founder.num && searchMatrix((int *)arr, 3, 3, founder))
        {
            printf("匹配数%d坐标为(%d，%d)", founder.num, founder.row, founder.col);
        }
        else
        {
            printf("匹配不存在或类型错误！！！");
        }
    }
    catch (const char *s)
    {
        std::cout << s;
    }
    return 0;
}
