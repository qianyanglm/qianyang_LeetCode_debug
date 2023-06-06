/**
<p>The <strong>count-and-say</strong> sequence is a sequence of digit strings defined by the recursive formula:</p>

<ul> 
 <li><code>countAndSay(1) = "1"</code></li> 
 <li><code>countAndSay(n)</code> is the way you would "say" the digit string from <code>countAndSay(n-1)</code>, which is then converted into a different digit string.</li> 
</ul>

<p>To determine how you "say" a digit string, split it into the <strong>minimal</strong> number of substrings such that each substring contains exactly <strong>one</strong> unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.</p>

<p>For example, the saying and conversion for digit string <code>"3322251"</code>:</p> 
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/23/countandsay.jpg" style="width: 581px; height: 172px;" /> 
<p>Given a positive integer <code>n</code>, return <em>the </em><code>n<sup>th</sup></code><em> term of the <strong>count-and-say</strong> sequence</em>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> "1"
<strong>Explanation:</strong> This is the base case.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 4
<strong>Output:</strong> "1211"
<strong>Explanation:</strong>
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= n &lt;= 30</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>字符串</details><br>

<div>👍 1016, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//官方
class Solution
{
public:
    string countAndSay(int n)
    {

        string prev = "1";
        for (int i = 2; i <= n; ++i)
        {
            string curr = "";
            //定义两个指针start和pos,start指向当前数字开始的位置,pos指向当前数字结束的位置
            int start = 0;
            int pos = 0;

            while (pos < prev.size())
            {
                //当pos指向的数字与start指向的数字相同时,pos继续后移。否则,已经检测到一个新的数字
                while (pos < prev.size() && prev[pos] == prev[start])
                {
                    pos++;
                }
                //此时,将start到pos之间数字的个数与具体数字拼接到下一序列curr中
                curr += to_string(pos - start) + prev[start];
                //更新start为pos,继续检查pos指向的数字。
                start = pos;
            }
            prev = curr;
        }
        return prev;
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
    cout << s.countAndSay(3) << endl;


    return 0;
}
