/**
<p>A <strong>valid IP address</strong> consists of exactly four integers separated by single dots. Each integer is between <code>0</code> and <code>255</code> (<strong>inclusive</strong>) and cannot have leading zeros.</p>

<ul> 
 <li>For example, <code>"0.1.2.201"</code> and <code>"192.168.1.1"</code> are <strong>valid</strong> IP addresses, but <code>"0.011.255.245"</code>, <code>"192.168.1.312"</code> and <code>"192.168@1.1"</code> are <strong>invalid</strong> IP addresses.</li> 
</ul>

<p>Given a string <code>s</code> containing only digits, return <em>all possible valid IP addresses that can be formed by inserting dots into </em><code>s</code>. You are <strong>not</strong> allowed to reorder or remove any digits in <code>s</code>. You may return the valid IP addresses in <strong>any</strong> order.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = "25525511135"
<strong>Output:</strong> ["255.255.11.135","255.255.111.35"]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = "0000"
<strong>Output:</strong> ["0.0.0.0"]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = "101023"
<strong>Output:</strong> ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= s.length &lt;= 20</code></li> 
 <li><code>s</code> consists of digits only.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>字符串 | 回溯</details><br>

<div>👍 1263, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//回溯
class Solution
{
    vector<string> result;

    void backtracking(string &s, int startIndex, int pointNum)
    {
        if (pointNum == 3)
        {
            if (isValid(s, startIndex, s.size() - 1)) result.push_back(s);
            return;
        }
        for (int i = startIndex; i < s.size(); ++i)
        {
            if (isValid(s, startIndex, i))
            {
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backtracking(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);
            }
            else
                break;
        }
    }

    bool isValid(const string &s, int start, int end)
    {
        if (start > end) return false;
        if (s[start] == '0' && start != end) return false;
        int num = 0;
        for (int i = start; i <= end; ++i)
        {
            if (s[i] > '9' || s[i] < '0') return false;
            num = num * 10 + (s[i] - '0');
            if (num > 255) return false;
        }
        return true;
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        result.clear();
        if (s.size() < 4 || s.size() > 12) return result;
        backtracking(s, 0, 0);
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