/**
<p>Given two strings <code>s</code> and <code>t</code>, return <code>true</code><em> if </em><code>s</code><em> is a <strong>subsequence</strong> of </em><code>t</code><em>, or </em><code>false</code><em> otherwise</em>.</p>

<p>A <strong>subsequence</strong> of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., <code>"ace"</code> is a subsequence of <code>"<u>a</u>b<u>c</u>d<u>e</u>"</code> while <code>"aec"</code> is not).</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> s = "abc", t = "ahbgdc"
<strong>Output:</strong> true
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> s = "axc", t = "ahbgdc"
<strong>Output:</strong> false
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>0 &lt;= s.length &lt;= 100</code></li> 
 <li><code>0 &lt;= t.length &lt;= 10<sup>4</sup></code></li> 
 <li><code>s</code> and <code>t</code> consist only of lowercase English letters.</li> 
</ul>

<p>&nbsp;</p> 
<strong>Follow up:</strong> Suppose there are lots of incoming 
<code>s</code>, say 
<code>s<sub>1</sub>, s<sub>2</sub>, ..., s<sub>k</sub></code> where 
<code>k &gt;= 10<sup>9</sup></code>, and you want to check one by one to see if 
<code>t</code> has its subsequence. In this scenario, how would you change your code?

<details><summary><strong>Related Topics</strong></summary>双指针 | 字符串 | 动态规划</details><br>

<div>👍 875, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//官方
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s[i] == t[j])
            {
                i++;
            }
            j++;
        }
        return i == n;
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
    cout << s.isSubsequence("abc", "ahbgdc") << endl;


    return 0;
}