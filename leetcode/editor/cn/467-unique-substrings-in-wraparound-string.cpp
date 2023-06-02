/**
<p>We define the string <code>base</code> to be the infinite wraparound string of <code>"abcdefghijklmnopqrstuvwxyz"</code>, so <code>base</code> will look like this:</p>

<ul> 
 <li><code>"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd...."</code>.</li> 
</ul>

<p>Given a string <code>s</code>, return <em>the number of <strong>unique non-empty substrings</strong> of </em><code>s</code><em> are present in </em><code>base</code>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = "a"
<strong>Output:</strong> 1
<strong>Explanation:</strong> Only the substring "a" of s is in base.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = "cac"
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two substrings ("a", "c") of s in base.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = "zab"
<strong>Output:</strong> 6
<strong>Explanation:</strong> There are six substrings ("z", "a", "b", "za", "ab", and "zab") of s in base.
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li> 
 <li><code>s</code> consists of lowercase English letters.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>字符串 | 动态规划</details><br>

<div>👍 383, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//官方
class Solution
{
public:
    int findSubstringInWraproundString(string s)
    {
        vector<int> dp(26);
        int k = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (i && (s[i] - s[i - 1] + 26) % 26 == 1)
            {
                ++k;
            }
            else
            {
                k = 1;
            }
            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = "cd";
    cout << res << endl;
    cout << s.findSubstringInWraproundString(res) << endl;


    return 0;
}