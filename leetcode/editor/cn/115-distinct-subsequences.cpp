/**
<p>Given two strings <code>s</code> and <code>t</code>, return <em>the number of distinct</em> <span data-keyword="subsequence-string"><strong><em>subsequences</em></strong></span><em> of </em><code>s</code><em> which equals </em><code>t</code>.</p>

<p>The test cases are generated so that the answer fits on a 32-bit signed integer.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = "rabbbit", t = "rabbit"
<strong>Output:</strong> 3
<strong>Explanation:</strong>
As shown below, there are 3 ways you can generate "rabbit" from s.
<span><code><strong><u>rabb</u></strong>b<strong><u>it</u></strong></code></span>
<span><code><strong><u>ra</u></strong>b<strong><u>bbit</u></strong></code></span>
<span><code><strong><u>rab</u></strong>b<strong><u>bit</u></strong></code></span>
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = "babgbag", t = "bag"
<strong>Output:</strong> 5
<strong>Explanation:</strong>
As shown below, there are 5 ways you can generate "bag" from s.
<span><code><strong><u>ba</u></strong>b<u><strong>g</strong></u>bag</code></span>
<span><code><strong><u>ba</u></strong>bgba<strong><u>g</u></strong></code></span>
<span><code><u><strong>b</strong></u>abgb<strong><u>ag</u></strong></code></span>
<span><code>ba<u><strong>b</strong></u>gb<u><strong>ag</strong></u></code></span>
<span><code>babg<strong><u>bag</u></strong></code></span></pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= s.length, t.length &lt;= 1000</code></li> 
 <li><code>s</code> and <code>t</code> consist of English letters.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>字符串 | 动态规划</details><br>

<div>👍 1059, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//动规,注意需要冲无符号长整型
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        vector<vector<uint64_t>> dp(n + 1, vector<uint64_t>(t.size() + 1));
        for (int i = 0; i < n; ++i)
        {
            dp[i][0] = 1;
        }
        for (int j = 1; j < t.size(); ++j)
        {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= t.size(); ++j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][t.size()];
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
    string s1 = "rabbbit", t = "rabbit";
    cout << s.numDistinct(s1, t) << endl;


    return 0;
}