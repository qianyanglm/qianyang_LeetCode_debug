/**
<p>Given two strings <code>ransomNote</code> and <code>magazine</code>, return <code>true</code><em> if </em><code>ransomNote</code><em> can be constructed by using the letters from </em><code>magazine</code><em> and </em><code>false</code><em> otherwise</em>.</p>

<p>Each letter in <code>magazine</code> can only be used once in <code>ransomNote</code>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> ransomNote = "a", magazine = "b"
<strong>Output:</strong> false
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> ransomNote = "aa", magazine = "ab"
<strong>Output:</strong> false
</pre>
<p><strong class="example">Example 3:</strong></p> 
<pre><strong>Input:</strong> ransomNote = "aa", magazine = "aab"
<strong>Output:</strong> true
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= ransomNote.length, magazine.length &lt;= 10<sup>5</sup></code></li> 
 <li><code>ransomNote</code> and <code>magazine</code> consist of lowercase English letters.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>哈希表 | 字符串 | 计数</details><br>

<div>👍 725, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//自己根据389题写的，改一下就行
//class Solution
//{
//public:
//    bool canConstruct(string ransomNote, string magazine)
//    {
//        vector<int> cnt(26, 0);
//        for (char ch: magazine)
//        {
//            cnt[ch - 'a']++;
//        }
//        for (char ch: ransomNote)
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
////暴力解法
//class Solution
//{
//public:
//    bool canConstruct(string ransomNote, string magazine)
//    {
//        for (int i = 0; i < magazine.length(); ++i)
//        {
//            for (int j = 0; j <ransomNote.length() ; ++j)
//            {
//                if ( magazine[i]==ransomNote[j] )
//                {
//                    ransomNote.erase(ransomNote.begin()+j);
//                    break ;
//                }
//            }
//        }
//
//        if ( ransomNote.length()==0 )
//        {
//            return true;
//        }
//        return false;
//    }
//};
//哈希表
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> map;
        for (char ch: magazine)
        {
            map[ch]++;
        }
        for (char ch: ransomNote)
        {
            map[ch]--;
        }
        for (char i: ransomNote)
        {
            if (map[i] < 0)
            {
                return false;
            }
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
    cout << s.canConstruct("ta", "ta");


    return 0;
}