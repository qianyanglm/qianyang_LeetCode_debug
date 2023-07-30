/**
<p>Given a string <code>s</code>, partition <code>s</code> such that every <span data-keyword="substring-nonempty">substring</span> of the partition is a <span data-keyword="palindrome-string"><strong>palindrome</strong></span>. Return <em>all possible palindrome partitioning of </em><code>s</code>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> s = "aab"
<strong>Output:</strong> [["a","a","b"],["aa","b"]]
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> s = "a"
<strong>Output:</strong> [["a"]]
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= s.length &lt;= 16</code></li> 
 <li><code>s</code> contains only lowercase English letters.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>字符串 | 动态规划 | 回溯</details><br>

<div>👍 1577, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//回溯
class Solution
{
    vector<vector<string>> result;
    vector<string> path;//放已经回文的子串

    void backtracking(const string &s, int startIndex)
    {
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); ++i)
        {
            if (isPalindrome(s, startIndex, i))//是回文子串
            {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else
            {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    bool isPalindrome(const string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; ++i, j--)
        {
            if (s[i] != s[j]) return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        result.clear();
        path.clear();
        backtracking(s, 0);
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