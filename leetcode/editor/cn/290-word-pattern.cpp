/**
<p>Given a <code>pattern</code> and a string <code>s</code>, find if <code>s</code>&nbsp;follows the same pattern.</p>

<p>Here <b>follow</b> means a full match, such that there is a bijection between a letter in <code>pattern</code> and a <b>non-empty</b> word in <code>s</code>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> pattern = "abba", s = "dog cat cat dog"
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> pattern = "abba", s = "dog cat cat fish"
<strong>Output:</strong> false
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> pattern = "aaaa", s = "dog cat cat dog"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= pattern.length &lt;= 300</code></li> 
 <li><code>pattern</code> contains only lower-case English letters.</li> 
 <li><code>1 &lt;= s.length &lt;= 3000</code></li> 
 <li><code>s</code> contains only lowercase English letters and spaces <code>' '</code>.</li> 
 <li><code>s</code> <strong>does not contain</strong> any leading or trailing spaces.</li> 
 <li>All the words in <code>s</code> are separated by a <strong>single space</strong>.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>哈希表 | 字符串</details><br>

<div>👍 576, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//其实和205题思路一样，只是c++不好处理字符串，故需要处理下字符串间空格的分割过程
//还有就是多判断了pattern和s的长度问题
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<string, char> str2ch;
        unordered_map<char, string> ch2str;
        int m = s.length();
        int i = 0;
        for (auto ch: pattern)
        {
            if (i >= m)//已经遍历完毕s,但pattern还有剩余
            {
                return false;
            }
            int j = i;
            while (j < m && s[j] != ' ')
            {
                j++;
            }
            const string &tmp = s.substr(i, j - i);
            if (str2ch.count(tmp) && str2ch[tmp] != ch)
            {
                return false;
            }
            if (ch2str.count(ch) && ch2str[ch] != tmp)
            {
                return false;
            }
            str2ch[tmp] = ch;
            ch2str[ch] = tmp;
            i = j + 1;
        }
        return i >= m;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    string res = "abba";
    cout << res << endl;
    cout << s.wordPattern(res, "dog cat cat dog") << endl;


    return 0;
}