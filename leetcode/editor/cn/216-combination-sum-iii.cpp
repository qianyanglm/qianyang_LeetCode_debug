/**
<p>Find all valid combinations of <code>k</code> numbers that sum up to <code>n</code> such that the following conditions are true:</p>

<ul> 
 <li>Only numbers <code>1</code> through <code>9</code> are used.</li> 
 <li>Each number is used <strong>at most once</strong>.</li> 
</ul>

<p>Return <em>a list of all possible valid combinations</em>. The list must not contain the same combination twice, and the combinations may be returned in any order.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> k = 3, n = 7
<strong>Output:</strong> [[1,2,4]]
<strong>Explanation:</strong>
1 + 2 + 4 = 7
There are no other valid combinations.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> k = 3, n = 9
<strong>Output:</strong> [[1,2,6],[1,3,5],[2,3,4]]
<strong>Explanation:</strong>
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> k = 4, n = 1
<strong>Output:</strong> []
<strong>Explanation:</strong> There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 &gt; 1, there are no valid combination.
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>2 &lt;= k &lt;= 9</code></li> 
 <li><code>1 &lt;= n &lt;= 60</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数组 | 回溯</details><br>

<div>👍 710, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//回溯
class Solution
{
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int targetSum, int k, int sum, int startIndex)
    {
        if (path.size() == k)
        {
            if (sum == targetSum) result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9; ++i)
        {
            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        result.clear();
        path.clear();
        backtracking(n, k, 0, 1);
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