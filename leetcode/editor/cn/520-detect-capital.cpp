/**
<p>We define the usage of capitals in a word to be right when one of the following cases holds:</p>

<ul> 
 <li>All letters in this word are capitals, like <code>"USA"</code>.</li> 
 <li>All letters in this word are not capitals, like <code>"leetcode"</code>.</li> 
 <li>Only the first letter in this word is capital, like <code>"Google"</code>.</li> 
</ul>

<p>Given a string <code>word</code>, return <code>true</code> if the usage of capitals in it is right.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> word = "USA"
<strong>Output:</strong> true
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> word = "FlaG"
<strong>Output:</strong> false
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= word.length &lt;= 100</code></li> 
 <li><code>word</code> consists of lowercase and uppercase English letters.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>字符串</details><br>

<div>👍 242, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//官方
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        //若第一个字母小写，则需要判断第二个字母是否为小写
        if (word.size() >= 2 && islower(word[0]) && isupper(word[1]))
        {
            return false;
        }

        //无论第一个字母是否大写，其他字母必须与第二个字母的大小写相同
        for (int i = 2; i < word.size(); ++i)
        {
            //^位异操作符
            if (islower(word[i]) ^ islower(word[1]))
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
    auto res = "Hello";
    cout << res << endl;

    cout << s.detectCapitalUse(res) << endl;

    return 0;
}