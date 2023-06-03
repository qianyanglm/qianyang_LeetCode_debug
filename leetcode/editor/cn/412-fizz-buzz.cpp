/**
<p>Given an integer <code>n</code>, return <em>a string array </em><code>answer</code><em> (<strong>1-indexed</strong>) where</em>:</p>

<ul> 
 <li><code>answer[i] == "FizzBuzz"</code> if <code>i</code> is divisible by <code>3</code> and <code>5</code>.</li> 
 <li><code>answer[i] == "Fizz"</code> if <code>i</code> is divisible by <code>3</code>.</li> 
 <li><code>answer[i] == "Buzz"</code> if <code>i</code> is divisible by <code>5</code>.</li> 
 <li><code>answer[i] == i</code> (as a string) if none of the above conditions are true.</li> 
</ul>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> ["1","2","Fizz"]
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> n = 5
<strong>Output:</strong> ["1","2","Fizz","4","Buzz"]
</pre>
<p><strong class="example">Example 3:</strong></p> 
<pre><strong>Input:</strong> n = 15
<strong>Output:</strong> ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数学 | 字符串 | 模拟</details><br>

<div>👍 300, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//自己写的
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> a;
        for (int i = 1; i < n + 1; ++i)
        {
            string s;
            if (i % 3 == 0 && i % 5 == 0)
            {
                a.push_back("FizzBuzz");
            }
            else if (i % 3 == 0)
            {
                a.push_back("Fizz");
            }
            else if (i % 5 == 0)
            {
                a.push_back("Buzz");
            }
            else
            {
                a.push_back(to_string(i));
            }
        }
        return a;
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

    for (string a: s.fizzBuzz(3))
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}