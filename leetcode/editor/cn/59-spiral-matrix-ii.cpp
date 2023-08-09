/**
<p>Given a positive integer <code>n</code>, generate an <code>n x n</code> <code>matrix</code> filled with elements from <code>1</code> to <code>n<sup>2</sup></code> in spiral order.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg" style="width: 242px; height: 242px;" /> 
<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> [[1,2,3],[8,9,4],[7,6,5]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> [[1]]
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= n &lt;= 20</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数组 | 矩阵 | 模拟</details><br>

<div>👍 1054, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//代码随想录，坚持左闭右开
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0, starty = 0;
        int i, j;        //i代表行，j代表列
        int loop = n / 2;//循环次数
        int mid = n / 2; //奇数项赋值
        int count = 1;
        int offset = 1;//减去的
        while (loop--)
        {
            i = startx;
            j = starty;
            for (; j < n - offset; ++j)
            {
                res[i][j] = count++;
            }

            for (; i < n - offset; ++i)
            {
                res[i][j] = count++;
            }

            for (; j > starty; --j)
            {
                res[i][j] = count++;
            }

            for (; i > startx; --i)
            {
                res[i][j] = count++;
            }

            offset++;
            starty++;
            startx++;
        }

        if (n % 2) res[mid][mid] = count;
        return res;
    }
};

////来自评论C++版本，和54题方法差不多
////https://leetcode.cn/problems/spiral-matrix-ii/solution/spiral-matrix-ii-mo-ni-fa-she-ding-bian-jie-qing-x/
//class Solution
//{
//public:
//    vector<vector<int>> generateMatrix(int n)
//    {
//        int num = 1;
//        int left = 0, top = 0, right = n - 1, bottom = n - 1;
//
//        //初始化数组
//        vector<vector<int>> res(n, vector<int>(n));
//        while (num <= n * n)
//        {
//            //左到右
//            for (int i = left; i <= right; ++i)
//            {
//                res[top][i] = num++;
//            }
//            ++top;//重新设定上边界，下同
//            //上到下
//            for (int i = top; i <= bottom; ++i)
//            {
//                res[i][right] = num++;
//            }
//            --right;
//            //从右到左
//            for (int i = right; i >= left; --i)
//            {
//                res[bottom][i] = num++;
//            }
//            --bottom;
//            //从底到上
//            for (int i = bottom; i >= top; --i)
//            {
//                res[i][left] = num++;
//            }
//            ++left;
//        }
//        return res;
//    }
//};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = "Hello LeetCode";
    cout << res << endl;

    data1 = s.generateMatrix(3);
    for (vector<int> a: data1)
    {
        for (int a1: a)
        {
            cout << a1 << "  ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}