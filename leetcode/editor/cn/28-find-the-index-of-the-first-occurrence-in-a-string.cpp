/**
<p>Given two strings <code>needle</code> and <code>haystack</code>, return the index of the first occurrence of <code>needle</code> in <code>haystack</code>, or <code>-1</code> if <code>needle</code> is not part of <code>haystack</code>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> haystack = "sadbutsad", needle = "sad"
<strong>Output:</strong> 0
<strong>Explanation:</strong> "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> haystack = "leetcode", needle = "leeto"
<strong>Output:</strong> -1
<strong>Explanation:</strong> "leeto" did not occur in "leetcode", so we return -1.
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= haystack.length, needle.length &lt;= 10<sup>4</sup></code></li> 
 <li><code>haystack</code> and <code>needle</code> consist of only lowercase English characters.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>双指针 | 字符串 | 字符串匹配</details><br>

<div>👍 1879, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
////官方
//class Solution
//{
//public:
//    int strStr(string haystack, string needle)
//    {
//        int n = haystack.size(), m = needle.size();
//        //遍历haystack的字符
//        for (int i = 0; i + m <= n; ++i)
//        {
//            bool flag = true;
//            //遍历needle的字符
//            for (int j = 0; j < m; ++j)
//            {
//                if (haystack[i + j] != needle[j])
//                {
//                    flag = false;
//                    break;
//                }
//            }
//            if (flag)
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//};
////自己写的
//class Solution
//{
//public:
//    int strStr(string haystack, string needle)
//    {
//        int m=haystack.size();
//        int n=needle.size();
//        if (m<n) return -1;
//        for (int i = 0; i <= m-n; ++i)
//        {
//            string ans;
//            for (int j = i; j < n+i; ++j)
//            {
//                ans+=haystack[j];
//            }
//            if ( ans==needle )
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//};
//代码随想录
class Solution
{
public:
    void getNext(int *next, const string &s)
    {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            while (j > 0 && s[i] != s[j])
            {
                j = next[j - 1];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size()) return (i - needle.size() + 1);
        }
        return -1;
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
    cout << s.strStr("hello", "ll") << endl;


    return 0;
}