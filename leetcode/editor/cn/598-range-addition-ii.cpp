/**
<p>You are given an <code>m x n</code> matrix <code>M</code> initialized with all <code>0</code>'s and an array of operations <code>ops</code>, where <code>ops[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> means <code>M[x][y]</code> should be incremented by one for all <code>0 &lt;= x &lt; a<sub>i</sub></code> and <code>0 &lt;= y &lt; b<sub>i</sub></code>.</p>

<p>Count and return <em>the number of maximum integers in the matrix after performing all the operations</em>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/02/ex1.jpg" style="width: 750px; height: 176px;" /> 
<pre>
<strong>Input:</strong> m = 3, n = 3, ops = [[2,2],[3,3]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The maximum integer in M is 2, and there are four of it in M. So return 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
<strong>Output:</strong> 4
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> m = 3, n = 3, ops = []
<strong>Output:</strong> 9
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= m, n &lt;= 4 * 10<sup>4</sup></code></li> 
 <li><code>0 &lt;= ops.length &lt;= 10<sup>4</sup></code></li> 
 <li><code>ops[i].length == 2</code></li> 
 <li><code>1 &lt;= a<sub>i</sub> &lt;= m</code></li> 
 <li><code>1 &lt;= b<sub>i</sub> &lt;= n</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数组 | 数学</details><br>

<div>👍 195, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//官方
class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        int mina = m, minb = n;
        //只需要找出每次行操作和列操作的最小值即可
        for (auto &op: ops)
        {
            mina = min(mina, op[0]);
            minb = min(minb, op[1]);
        }
        return mina * minb;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{2, 2}, {3, 3}};
    auto res = "Hello LeetCode";
    cout << res << endl;
    int x = s.maxCount(3, 3, data1);
    for (auto &i: data1)
    {
        for (int j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << x << endl;

    return 0;
}