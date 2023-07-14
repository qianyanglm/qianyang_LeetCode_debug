/**
English description is not available for the problem. Please switch to Chinese.
<details><summary><strong>Related Topics</strong></summary>数组 | 矩阵 | 模拟</details><br>

<div>👍 557, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//
//    }
//};
//代码随想录
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};
        int rows = matrix.size(), columns = matrix[0].size();
        int total = rows * columns;
        vector<int> res(total);
        int startx = 0, starty = 0;
        int loop = min(rows, columns) / 2;
        int mid = min(rows, columns) / 2;
        int count = 0;
        int offset = 1;
        int i, j;
        while (loop--)
        {
            i = startx;
            j = starty;
            for (j = starty; j < starty + columns - offset; j++)
                res[count++] = matrix[startx][j];
            for (i = startx; i < startx + rows - offset; i++)
                res[count++] = matrix[i][j];
            for (; j > starty; j--)
                res[count++] = matrix[i][j];
            for (; i > startx; i--)
                res[count++] = matrix[i][starty];

            startx++;
            starty++;
            offset += 2;
        }
        if (min(rows, columns) % 2)
        {
            if (rows > columns)
            {
                for (int i = mid; i < mid + rows - columns + 1; ++i)
                {
                    res[count++] = matrix[i][mid];
                }
            }
            else
            {
                for (int i = mid; i < mid + columns - rows + 1; ++i)
                {
                    res[count++] = matrix[mid][i];
                }
            }
        }
        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = "Hello LeetCode";
    cout << res << endl;


    return 0;
}