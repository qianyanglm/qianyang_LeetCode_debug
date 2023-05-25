/**
<p>Write a function to find the longest common prefix string amongst an array of strings.</p>

<p>If there is no common prefix, return an empty string <code>""</code>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> strs = ["flower","flow","flight"]
<strong>Output:</strong> "fl"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> strs = ["dog","racecar","car"]
<strong>Output:</strong> ""
<strong>Explanation:</strong> There is no common prefix among the input strings.
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= strs.length &lt;= 200</code></li> 
 <li><code>0 &lt;= strs[i].length &lt;= 200</code></li> 
 <li><code>strs[i]</code> consists of only lowercase English letters.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>字典树 | 字符串</details><br>

<div>👍 2788, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//https://leetcode.cn/problems/longest-common-prefix/solution/zi-dian-shu-zui-chang-gong-gong-qian-zhu-xcvs/
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";
        //纵向比较
        for (int i = 0; strs[0][i]; i++)
        {
            for (int j = 0; j < strs.size() - 1; j++)
            {
                //每个字符同一位置的字符是否相等，一旦不相等，立刻返回
                if (strs[j][i] != strs[j + 1][i])
                    return ans;
            }
            ans.push_back(strs[0][i]);
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<string> data1{"flower", "flow", "flight"};
    auto res = "Hello LeetCode";
    cout << res << endl;
    cout << s.longestCommonPrefix(data1) << endl;

    return 0;
}