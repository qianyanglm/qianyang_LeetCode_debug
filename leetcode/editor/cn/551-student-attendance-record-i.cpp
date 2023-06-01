/**
<p>You are given a string <code>s</code> representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:</p>

<ul> 
 <li><code>'A'</code>: Absent.</li> 
 <li><code>'L'</code>: Late.</li> 
 <li><code>'P'</code>: Present.</li> 
</ul>

<p>The student is eligible for an attendance award if they meet <strong>both</strong> of the following criteria:</p>

<ul> 
 <li>The student was absent (<code>'A'</code>) for <strong>strictly</strong> fewer than 2 days <strong>total</strong>.</li> 
 <li>The student was <strong>never</strong> late (<code>'L'</code>) for 3 or more <strong>consecutive</strong> days.</li> 
</ul>

<p>Return <code>true</code><em> if the student is eligible for an attendance award, or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = "PPALLP"
<strong>Output:</strong> true
<strong>Explanation:</strong> The student has fewer than 2 absences and was never late 3 or more consecutive days.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = "PPALLL"
<strong>Output:</strong> false
<strong>Explanation:</strong> The student was late 3 consecutive days in the last 3 days, so is not eligible for the award.
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= s.length &lt;= 1000</code></li> 
 <li><code>s[i]</code> is either <code>'A'</code>, <code>'L'</code>, or <code>'P'</code>.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>字符串</details><br>

<div>👍 149, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//自己写的
class Solution
{
public:
    bool checkRecord(string s)
    {
        int length = s.length();
        int count = 0;
        for (int i = 0; i < length - 2; ++i)
        {
            if (s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L')
            {
                return false;
            }
        }
        for (int i = 0; i < length; ++i)
        {
            if (s[i] == 'A')
            {
                ++count;
            }
        }
        if (count < 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = "PPALL";
    cout << res << endl;
    cout << s.checkRecord(res) << endl;


    return 0;
}