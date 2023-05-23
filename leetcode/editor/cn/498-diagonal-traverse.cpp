/**
<p>Given an <code>m x n</code> matrix <code>mat</code>, return <em>an array of all the elements of the array in a diagonal order</em>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/10/diag1-grid.jpg" style="width: 334px; height: 334px;" /> 
<pre>
<strong>Input:</strong> mat = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [1,2,4,7,5,3,6,8,9]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> mat = [[1,2],[3,4]]
<strong>Output:</strong> [1,2,3,4]
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>m == mat.length</code></li> 
 <li><code>n == mat[i].length</code></li> 
 <li><code>1 &lt;= m, n &lt;= 10<sup>4</sup></code></li> 
 <li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li> 
 <li><code>-10<sup>5</sup> &lt;= mat[i][j] &lt;= 10<sup>5</sup></code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数组 | 矩阵 | 模拟</details><br>

<div>👍 447, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//https://leetcode.cn/problems/diagonal-traverse/solution/dui-jiao-xian-bian-li-fen-xi-ti-mu-zhao-zhun-gui-l/
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        vector<int> nums;
        int m = mat.size();   //行
        int n = mat[0].size();//列
        int i = 0;            //i是x+y的和
        while (i < m + n)
        {
            //第1 3 5。。奇数趟
            int x1 = (i < m) ? i : m - 1;//确定x y的初始值
            int y1 = i - x1;
            while (x1 >= 0 && y1 < n)
            {
                nums.push_back(mat[x1][y1]);
                x1--;
                y1++;
            }

            i++;
            if (i >= m + n)
            {
                break;
            }
            //第2 4 6。。。趟
            int y2 = (i < n) ? i : n - 1;//确定x y的初始值
            int x2 = i - y2;
            while (y2 >= 0 && x2 < m)
            {
                nums.push_back(mat[x2][y2]);
                x2++;
                y2--;
            }
            i++;
        }
        return nums;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = "Hello LeetCode";
    cout << res << endl;
    for (int a: s.findDiagonalOrder(data1))
    {
        cout << a << " ";
    }
    cout << endl;


    return 0;
}