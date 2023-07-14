/**
<p>Given two strings <code>s</code> and <code>t</code>, return <code>true</code> <em>if</em> <code>t</code> <em>is an anagram of</em> <code>s</code><em>, and</em> <code>false</code> <em>otherwise</em>.</p>

<p>An <strong>Anagram</strong> is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> s = "anagram", t = "nagaram"
<strong>Output:</strong> true
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> s = "rat", t = "car"
<strong>Output:</strong> false
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= s.length, t.length &lt;= 5 * 10<sup>4</sup></code></li> 
 <li><code>s</code> and <code>t</code> consist of lowercase English letters.</li> 
</ul>

<p>&nbsp;</p> 
<p><strong>Follow up:</strong> What if the inputs contain Unicode characters? How would you adapt your solution to such a case?</p>

<details><summary><strong>Related Topics</strong></summary>哈希表 | 字符串 | 排序</details><br>

<div>👍 784, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
////自己根据389题写的
//class Solution
//{
//public:
//    bool isAnagram(string s, string t)
//    {
//        vector<int> cnt(26, 0);
//        int l1 = s.length();
//        int l2 = t.length();
//        if (l1 != l2)
//        {
//            return false;
//        }
//        for (char ch: s)
//        {
//            cnt[ch - 'a']++;
//        }
//        for (char ch: t)
//        {
//            cnt[ch - 'a']--;
//            if (cnt[ch - 'a'] < 0)
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};
////尝试一下暴力解法来自这个人
////https://leetcode.cn/problems/valid-anagram/solutions/2037644/by-ni-ming-vs-3oev/
//class Solution
//{
//public:
//    bool isAnagram(string s, string t)
//    {
//        if (s.size()!=t.size()) return false;
//        sort(s.begin(),s.end());
//        sort(t.begin(),t.end());
//        for (int i = 0; i < s.size(); ++i)
//        {
//            if (s[i]!=t[i]) return false;
//        }
//        return true;
//    }
//};
//尝试一下哈希表，代码随想录
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> s1;
        for (char so: s)
        {
            s1[so]++;
        }
        for (char to: t)
        {
            s1[to]--;
        }
        for (char i: s)
        {
            if (s1[i] != 0) return false;
        }
        return true;
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
    cout << s.isAnagram(string("anagram"), string("nagaram")) << endl;

    return 0;
}