/**
<p>A magical string <code>s</code> consists of only <code>'1'</code> and <code>'2'</code> and obeys the following rules:</p>

<ul> 
 <li>The string s is magical because concatenating the number of contiguous occurrences of characters <code>'1'</code> and <code>'2'</code> generates the string <code>s</code> itself.</li> 
</ul>

<p>The first few elements of <code>s</code> is <code>s = "1221121221221121122……"</code>. If we group the consecutive <code>1</code>'s and <code>2</code>'s in <code>s</code>, it will be <code>"1 22 11 2 1 22 1 22 11 2 11 22 ......"</code> and the occurrences of <code>1</code>'s or <code>2</code>'s in each group are <code>"1 2 2 1 1 2 1 2 2 1 2 2 ......"</code>. You can see that the occurrence sequence is <code>s</code> itself.</p>

<p>Given an integer <code>n</code>, return the number of <code>1</code>'s in the first <code>n</code> number in the magical string <code>s</code>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 6
<strong>Output:</strong> 3
<strong>Explanation:</strong> The first 6 elements of magical string s is "122112" and it contains three 1's, so return 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>双指针 | 字符串</details><br>

<div>👍 183, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//官方
//这题主要是看懂意思，否则很难搞
class Solution
{
public:
    int magicalString(int n)
    {
        if (n < 4)
        {
            return 1;//前三个字符串为122
        }
        string s(n, '0');
        s[0] = '1', s[1] = '2', s[2] = '2';
        int res = 1;
        //i表示构造1/2的个数
        int i = 2;
        //j表示现在需要构造的位置
        int j = 3;
        while (j < n)
        {
            int size = s[i] - '0';         //表示需要构造1/2的个数
            int num = 3 - (s[j - 1] - '0');//表示j处需要构造1还是2，j构造1/2和s[j-1]有关
            while (size > 0 && j < n)
            {
                s[j] = '0' + num;//构造j处位置
                if (num == 1)
                {
                    ++res;
                }
                ++j;
                --size;
            }
            ++i;
        }
        return res;
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
    cout << s.magicalString(3) << endl;


    return 0;
}