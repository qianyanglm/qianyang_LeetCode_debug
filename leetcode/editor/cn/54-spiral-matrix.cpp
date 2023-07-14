/**
<p>Given an <code>m x n</code> <code>matrix</code>, return <em>all elements of the</em> <code>matrix</code> <em>in spiral order</em>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg" style="width: 242px; height: 242px;" /> 
<pre>
<strong>Input:</strong> matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [1,2,3,6,9,8,7,4,5]
</pre>

<p><strong class="example">Example 2:</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg" style="width: 322px; height: 242px;" /> 
<pre>
<strong>Input:</strong> matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
<strong>Output:</strong> [1,2,3,4,8,12,11,10,9,5,6,7]
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>m == matrix.length</code></li> 
 <li><code>n == matrix[i].length</code></li> 
 <li><code>1 &lt;= m, n &lt;= 10</code></li> 
 <li><code>-100 &lt;= matrix[i][j] &lt;= 100</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数组 | 矩阵 | 模拟</details><br>

<div>👍 1382, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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

////这题官方比较拉，代码来自这里
////https://leetcode.cn/problems/spiral-matrix/solution/cxiang-xi-ti-jie-by-youlookdeliciousc-3/
//class Solution
//{
//public:
//    vector<int> spiralOrder(vector<vector<int>> &matrix)
//    {
//        vector<int> ans;
//        if (matrix.empty())
//        {
//            return ans;//数组为空，直接返回答案
//        }
//        //为了好记忆上下左右，我把原来代码的变量名字改了
//        int top = 0;                     //赋值上下左右边界
//        int bottom = matrix.size() - 1;  //下
//        int left = 0;                    //左
//        int right = matrix[0].size() - 1;//右
//        while (true)
//        {
//            //向右移动直到最右
//            for (int i = left; i <= right; ++i)
//                ans.push_back(matrix[top][i]);
//            if (++top > bottom) break;//重新设定上边界，上边界大于下边界，遍历结束
//            //向下移动到最下
//            for (int i = top; i <= bottom; ++i)
//                ans.push_back(matrix[i][right]);
//            if (--right < left) break;//重新设定右边界
//            //向左
//            for (int i = right; i >= left; --i)
//                ans.push_back(matrix[bottom][i]);
//            if (--bottom < top) break;//重新设定下边界
//            //向上
//            for (int i = bottom; i >= top; --i)
//                ans.push_back(matrix[i][left]);
//            if (++left > right) break;//重新设定左边界
//        }
//        return ans;
//    }
//};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = "Hello LeetCode";
    cout << res << endl;
    data = s.spiralOrder(data1);
    for (int a: data)
    {
        cout << a << " ";
    }
    cout << endl;


    return 0;
}