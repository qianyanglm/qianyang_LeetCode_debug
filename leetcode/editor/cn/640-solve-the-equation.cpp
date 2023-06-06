/**
<p>Solve a given equation and return the value of <code>'x'</code> in the form of a string <code>"x=#value"</code>. The equation contains only <code>'+'</code>, <code>'-'</code> operation, the variable <code>'x'</code> and its coefficient. You should return <code>"No solution"</code> if there is no solution for the equation, or <code>"Infinite solutions"</code> if there are infinite solutions for the equation.</p>

<p>If there is exactly one solution for the equation, we ensure that the value of <code>'x'</code> is an integer.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> equation = "x+5-3+x=6+x-2"
<strong>Output:</strong> "x=2"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> equation = "x=x"
<strong>Output:</strong> "Infinite solutions"
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> equation = "2x=x"
<strong>Output:</strong> "x=0"
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>3 &lt;= equation.length &lt;= 1000</code></li> 
 <li><code>equation</code> has exactly one <code>'='</code>.</li> 
 <li><code>equation</code> consists of integers with an absolute value in the range <code>[0, 100]</code> without any leading zeros, and the variable <code>'x'</code>.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数学 | 字符串 | 模拟</details><br>

<div>👍 205, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    string solveEquation(string equation)
    {
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