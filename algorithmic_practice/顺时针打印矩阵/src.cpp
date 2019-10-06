#include <stdio.h>
#include <vector>

using namespace std;

// 边界条件总是考虑有问题，最终参考了别人的代码😥
vector<int> printMatrix(vector<vector<int> > matrix) 
{
    vector<int> res;
    if (matrix.empty())
    {
        return res;
    }

    int ring = 0;
    int column = matrix[0].size();
    int row = matrix.size();
    int cycle = ((row < column ? row : column) - 1) / 2 + 1;
    while (ring < cycle)
    {
        // 1
        for (int i = ring; i < column - ring; i++)
        {
            res.push_back(matrix[ring][i]);
        }

        // 2
        for (int i = ring + 1; i < row - ring; i++)
        {
            res.push_back(matrix[i][column - ring - 1]);
        }

        // 3
        for (int i = column - ring - 2; i >= ring && row - ring - 1 != ring; i--)
        {
            res.push_back(matrix[row - ring - 1][i]);
        }

        // 4
        for (int i = row - ring - 2; i > ring && column - ring - 1 != ring; i--)
        {
            res.push_back(matrix[i][ring]);
        }

        ring++;
    }

    return res;
}

// 另一个思路更清晰的代码
vector<int> printMatrix1(vector<vector<int> > matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> res;

    // 输入的二维数组非法，返回空的数组
    if (row == 0 || col == 0)  return res;

    // 定义四个关键变量，表示左上和右下的打印范围
    int left = 0, top = 0, right = col - 1, bottom = row - 1;
    while (left <= right && top <= bottom)
    {
        // left to right
        for (int i = left; i <= right; ++i)  
            res.push_back(matrix[top][i]);
        // top to bottom
        for (int i = top + 1; i <= bottom; ++i)  
            res.push_back(matrix[i][right]);
        // right to left
        if (top != bottom)
            for (int i = right - 1; i >= left; --i) 
                res.push_back(matrix[bottom][i]);
        // bottom to top
        if (left != right)
            for (int i = bottom - 1; i > top; --i)  
                res.push_back(matrix[i][left]);
        left++, top++, right--, bottom--;
    }
    return res;
}

int main()
{
    //vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
    vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12}/*,{13,14,15,16}*/ };
    //vector<vector<int>> matrix = { {1,2,3},{5,6,7},{9,10,11},{13,14,15} };
    //vector<vector<int>> matrix = { {1,2,3,4} };
    //vector<vector<int>> matrix = { {1}, {2}, {3}, {4} };

    vector<int> res = printMatrix1(matrix);
    for (auto &itr : res)
    {
        printf("%d ", itr);
    }

    getchar();
    return 0;
}