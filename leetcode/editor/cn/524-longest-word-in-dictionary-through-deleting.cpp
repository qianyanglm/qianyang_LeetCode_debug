/**
<p>Given a string <code>s</code> and a string array <code>dictionary</code>, return <em>the longest string in the dictionary that can be formed by deleting some of the given string characters</em>. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
<strong>Output:</strong> "apple"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = "abpcplea", dictionary = ["a","b","c"]
<strong>Output:</strong> "a"
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= s.length &lt;= 1000</code></li> 
 <li><code>1 &lt;= dictionary.length &lt;= 1000</code></li> 
 <li><code>1 &lt;= dictionary[i].length &lt;= 1000</code></li> 
 <li><code>s</code> and <code>dictionary[i]</code> consist of lowercase English letters.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数组 | 双指针 | 字符串 | 排序</details><br>

<div>👍 338, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting/solution/suan-fa-xiao-ai-shuang-zhi-zhen-xiang-ji-6rey/
class Solution
{
public:
    //判断t是否是s的子序列
    bool isSubsequence(string s, string t)
    {
        int n = s.size(), m = t.size();
        //t长度大于s,一定不是子序列
        if (m > n) return false;
        //记录当前s中匹配到了哪个位置
        int i = 0;
        for (char ch: t)
        {
            while (i < n && s[i] != ch)
            {
                i++;
            }
            if (i >= n)
            {
                return false;
            }
            i++;
            //此时s[i]=ch，下次从s[i+1]开始匹配
        }
        return true;
    }

    string findLongestWord(string s, vector<string> &dictionary)
    {
        //更长的、字典序更小的排在前面，这样只需要找到就是结果了
        sort(dictionary.begin(), dictionary.end(), [&](string &a, string &b) {
            if (a.size() == b.size()) return a < b;
            return a.size() > b.size();
        });
        for (string &t: dictionary)
        {
            if (isSubsequence(s, t))
            {
                return t;
            }
        }
        //没找到的话
        return "";
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<string> res = {"ale", "apple", "monkey", "plea"};
    cout << s.findLongestWord("abpcplea", res) << endl;


    return 0;
}