#include <iostream>

struct ABS
{
    int num, row, col;
};

/*!
 * �����������Ͷ�ά�����е�ƥ��ֵ
 * @param mat ��ά����ָ��
 * @param row ����
 * @param col ����
 * @param founder ƥ��ṹ��
 * @return ƥ��ɹ�����ture,Ĭ�Ϸ���false
 */
bool searchMatrix(const int *mat, int row, int col, ABS &founder)
{
    if (row <= 0 || col <= 0 || founder.num < 0)
        throw "�������Ϊ������������";

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

    std::cout << "�����ƥ������:";

    try
    {
        if (std::cin >> founder.num && searchMatrix((int *)arr, 3, 3, founder))
        {
            printf("ƥ����%d����Ϊ(%d��%d)", founder.num, founder.row, founder.col);
        }
        else
        {
            printf("ƥ�䲻���ڻ����ʹ��󣡣���");
        }
    }
    catch (const char *s)
    {
        std::cout << s;
    }
    return 0;
}
