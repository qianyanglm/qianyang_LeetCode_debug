/**
<p>You are given an integer array <code>nums</code> of length <code>n</code>.</p>

<p>Assume <code>arr<sub>k</sub></code> to be an array obtained by rotating <code>nums</code> by <code>k</code> positions clock-wise. We define the <strong>rotation function</strong> <code>F</code> on <code>nums</code> as follow:</p>

<ul> 
 <li><code>F(k) = 0 * arr<sub>k</sub>[0] + 1 * arr<sub>k</sub>[1] + ... + (n - 1) * arr<sub>k</sub>[n - 1].</code></li> 
</ul>

<p>Return <em>the maximum value of</em> <code>F(0), F(1), ..., F(n-1)</code>.</p>

<p>The test cases are generated so that the answer fits in a <strong>32-bit</strong> integer.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,3,2,6]
<strong>Output:</strong> 26
<strong>Explanation:</strong>
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [100]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>n == nums.length</code></li> 
 <li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li> 
 <li><code>-100 &lt;= nums[i] &lt;= 100</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数组 | 数学 | 动态规划</details><br>

<div>👍 262, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//官方
class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int f = 0, n = nums.size();
        //计算原数组所有元素的和numSum
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        //计算原数组的函数值
        for (int i = 0; i < n; ++i)
        {
            f += i * nums[i];
        }
        int res = f;
        for (int i = n - 1; i > 0; --i)
        {
            f += numSum - n * nums[i];
            res = max(res, f);
        }
        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{4, 3, 2, 6};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = "Hello LeetCode";
    cout << res << endl;
    cout << s.maxRotateFunction(data) << endl;


    return 0;
}