/**
<p>Given a non-negative integer <code>x</code>, return <em>the square root of </em><code>x</code><em> rounded down to the nearest integer</em>. The returned integer should be <strong>non-negative</strong> as well.</p>

<p>You <strong>must not use</strong> any built-in exponent function or operator.</p>

<ul> 
 <li>For example, do not use <code>pow(x, 0.5)</code> in c++ or <code>x ** 0.5</code> in python.</li> 
</ul>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> x = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> The square root of 4 is 2, so we return 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> x = 8
<strong>Output:</strong> 2
<strong>Explanation:</strong> The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>0 &lt;= x &lt;= 2<sup>31</sup> - 1</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数学 | 二分查找</details><br>

<div>👍 1391, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//官方题解 ， 二分查找
class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 0, right = x, ans = -1;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if ((long long) middle * middle <= x)
            {
                ans = middle;
                left = middle + 1;
            }
            else
                right = middle - 1;
        }
        return ans;
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
    cout << s.mySqrt(2) << endl;


    return 0;
}