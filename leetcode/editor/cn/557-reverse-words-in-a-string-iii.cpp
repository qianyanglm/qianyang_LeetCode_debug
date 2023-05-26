/**
<p>Given a string <code>s</code>, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> s = "Let's take LeetCode contest"
<strong>Output:</strong> "s'teL ekat edoCteeL tsetnoc"
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> s = "God Ding"
<strong>Output:</strong> "doG gniD"
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li> 
 <li><code>s</code> contains printable <strong>ASCII</strong> characters.</li> 
 <li><code>s</code> does not contain any leading or trailing spaces.</li> 
 <li>There is <strong>at least one</strong> word in <code>s</code>.</li> 
 <li>All the words in <code>s</code> are separated by a single space.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>双指针 | 字符串</details><br>

<div>👍 549, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//官方
class Solution
{
public:
    string reverseWords(string s)
    {
        string ret;
        int length = s.length();
        int i = 0;
        while (i < length)
        {
            int start = i;
            while (i < length && s[i] != ' ')
            {
                i++;
            }
            for (int p = start; p < i; ++p)
            {
                ret.push_back(s[start + i - 1 - p]);
            }
            while (i < length && s[i] == ' ')
            {
                i++;
                ret.push_back(' ');
            }
        }
        return ret;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    string res = "Hello LeetCode";
    string res1;
    cout << res << endl;
    res1 = s.reverseWords(res);
    cout << res1 << endl;


    return 0;
}