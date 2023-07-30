/**
<p>Given two integers <code>n</code> and <code>k</code>, return <em>all possible combinations of</em> <code>k</code> <em>numbers chosen from the range</em> <code>[1, n]</code>.</p>

<p>You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 4, k = 2
<strong>Output:</strong> [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
<strong>Explanation:</strong> There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1, k = 1
<strong>Output:</strong> [[1]]
<strong>Explanation:</strong> There is 1 choose 1 = 1 total combination.
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= n &lt;= 20</code></li> 
 <li><code>1 &lt;= k &lt;= n</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>回溯</details><br>

<div>👍 1438, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//回溯
class Solution
{
    vector<vector<int>> result;//存放符合条件结果的集合
    vector<int> path;          //存放符合条件结果

    void backtracking(int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; ++i)
        {
            path.push_back(i);        //处理节点
            backtracking(n, k, i + 1);//递归
            path.pop_back();          //回溯，撤销处理的节点
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;
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