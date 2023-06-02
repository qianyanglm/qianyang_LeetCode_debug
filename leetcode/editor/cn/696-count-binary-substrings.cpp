/**
<p>Given a binary string <code>s</code>, return the number of non-empty substrings that have the same number of <code>0</code>'s and <code>1</code>'s, and all the <code>0</code>'s and all the <code>1</code>'s in these substrings are grouped consecutively.</p>

<p>Substrings that occur multiple times are counted the number of times they occur.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = "00110011"
<strong>Output:</strong> 6
<strong>Explanation:</strong> There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = "10101"
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li> 
 <li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>双指针 | 字符串</details><br>

<div>👍 524, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//官方
class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        //将s按照0和1的连续分段分组
        vector<int> counts;
        int ptr = 0, n = s.size();
        while (ptr < n)
        {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c)
            {
                ++ptr;
                ++count;
            }
            counts.push_back(count);
        }
        //取出相邻数字对中的最小值即可
        int ans = 0;
        for (int i = 1; i < counts.size(); ++i)
        {
            ans += min(counts[i], counts[i - 1]);
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
    auto res = "10101";
    cout << res << endl;
    cout << s.countBinarySubstrings(res) << endl;


    return 0;
}