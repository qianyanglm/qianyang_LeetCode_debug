/**
<p>Given a string <code>s</code> containing an out-of-order English representation of digits <code>0-9</code>, return <em>the digits in <strong>ascending</strong> order</em>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> s = "owoztneoer"
<strong>Output:</strong> "012"
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> s = "fviefuro"
<strong>Output:</strong> "45"
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li> 
 <li><code>s[i]</code> is one of the characters <code>["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"]</code>.</li> 
 <li><code>s</code> is <strong>guaranteed</strong> to be valid.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>哈希表 | 数学 | 字符串</details><br>

<div>👍 198, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//官方
class Solution
{
public:
    string originalDigits(string s)
    {
        //哈希表统计每个字母出现次数
        unordered_map<char, int> c;
        for (char ch: s)
        {
            ++c[ch];
        }

        //统计每个数字出现次数
        vector<int> cnt(10);
        cnt[0] = c['z'];
        cnt[2] = c['w'];
        cnt[4] = c['u'];
        cnt[6] = c['x'];
        cnt[8] = c['g'];

        cnt[3] = c['h'] - cnt[8];
        cnt[5] = c['f'] - cnt[4];
        cnt[7] = c['s'] - cnt[6];

        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4];
        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8];

        //        for (int i = 0; i < 10; ++i)
        //        {
        //            cout<<cnt[i]<<" ";
        //        }
        //        cout<<endl;
        string ans;
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < cnt[i]; ++j)
            {
                ans += char(i + '0');
            }
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
    auto res = "owoztneoer";
    cout << res << endl;
    cout << s.originalDigits(res) << endl;


    return 0;
}