/**
<p>Given a string <code>s</code>, return <em>the number of segments in the string</em>.</p>

<p>A <strong>segment</strong> is defined to be a contiguous sequence of <strong>non-space characters</strong>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = "Hello, my name is John"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The five segments are ["Hello,", "my", "name", "is", "John"]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = "Hello"
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>0 &lt;= s.length &lt;= 300</code></li> 
 <li><code>s</code> consists of lowercase and uppercase English letters, digits, or one of the following characters <code>"!@#$%^&amp;*()_+-=',.:"</code>.</li> 
 <li>The only space character in <code>s</code> is <code>' '</code>.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>字符串</details><br>

<div>👍 208, 👎 0<span style='float: right;'></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//官方
class Solution
{
public:
    int countSegments(string s)
    {

        int countSegments = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
            {
                countSegments++;
            }
        }
        return countSegments;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    string res = "    ";
    cout << res << endl;

    for (char ch: res)
    {
        cout << ch << " ";
    }
    cout << endl;
    cout << s.countSegments(res) << endl;

    return 0;
}