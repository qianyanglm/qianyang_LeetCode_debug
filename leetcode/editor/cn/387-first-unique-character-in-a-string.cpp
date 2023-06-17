/**
<p>Given a string <code>s</code>, <em>find the first non-repeating character in it and return its index</em>. If it does not exist, return <code>-1</code>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> s = "leetcode"
<strong>Output:</strong> 0
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> s = "loveleetcode"
<strong>Output:</strong> 2
</pre>
<p><strong class="example">Example 3:</strong></p> 
<pre><strong>Input:</strong> s = "aabb"
<strong>Output:</strong> -1
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li> 
 <li><code>s</code> consists of only lowercase English letters.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>队列 | 哈希表 | 字符串 | 计数</details><br>

<div>👍 672, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
////官方
//class Solution
//{
//public:
//    int firstUniqChar(string s)
//    {
//        unordered_map<int, int> frequency;
//        //第一次遍历，用哈希映射统计字符串中每个字符出现的次数
//        for (char ch: s)
//        {
//            ++frequency[ch];
//        }
//        //第二次遍历，只要遍历到一个出现一次的字符，就返回它的索引
//        for (int i = 0; i < s.size(); ++i)
//        {
//            if (frequency[s[i]] == 1)
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//};
//模仿写
class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> map;
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            //map[s[i]] 表示哈希表 map 中键为 s[i] 的值。如果该键不存在，会自动创建并初始化为默认值（对于 int 类型，默认值为 0）。
            ++map[s[i]];
        }
        for (int i = 0; i < n; ++i)
        {
            if (map[s[i]] == 1)
            {
                return i;
            }
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
    string res = "loveleetcode";
    cout << res << endl;
    cout << s.firstUniqChar(res) << endl;


    return 0;
}