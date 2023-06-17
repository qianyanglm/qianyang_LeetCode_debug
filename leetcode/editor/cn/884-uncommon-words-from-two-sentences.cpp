/**
<p>A <strong>sentence</strong> is a string of single-space separated words where each word consists only of lowercase letters.</p>

<p>A word is <strong>uncommon</strong> if it appears exactly once in one of the sentences, and <strong>does not appear</strong> in the other sentence.</p>

<p>Given two <strong>sentences</strong> <code>s1</code> and <code>s2</code>, return <em>a list of all the <strong>uncommon words</strong></em>. You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> s1 = "this apple is sweet", s2 = "this apple is sour"
<strong>Output:</strong> ["sweet","sour"]
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> s1 = "apple apple", s2 = "banana"
<strong>Output:</strong> ["banana"]
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= s1.length, s2.length &lt;= 200</code></li> 
 <li><code>s1</code> and <code>s2</code> consist of lowercase English letters and spaces.</li> 
 <li><code>s1</code> and <code>s2</code> do not have leading or trailing spaces.</li> 
 <li>All the words in <code>s1</code> and <code>s2</code> are separated by a single space.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>哈希表 | 字符串</details><br>

<div>👍 186, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//https://leetcode.cn/problems/uncommon-words-from-two-sentences/solution/liang-ju-hua-zhong-de-bu-chang-jian-dan-a8bmz/1357263
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> m;
        stringstream ss;
        ss << s1 << " " << s2;
        string s;
        while (ss >> s)
        {
            ++m[s];
        }
        vector<string> ans;
        for (auto [s, c]: m)
        {
            if (c == 1)
                ans.emplace_back(s);
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
    auto res = "Hello LeetCode";
    cout << res << endl;
    s.uncommonFromSentences("123", "456");


    return 0;
}