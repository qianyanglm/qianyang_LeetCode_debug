/**
<p>Given two binary strings <code>a</code> and <code>b</code>, return <em>their sum as a binary string</em>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> a = "11", b = "1"
<strong>Output:</strong> "100"
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> a = "1010", b = "1011"
<strong>Output:</strong> "10101"
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= a.length, b.length &lt;= 10<sup>4</sup></code></li> 
 <li><code>a</code> and <code>b</code> consist&nbsp;only of <code>'0'</code> or <code>'1'</code> characters.</li> 
 <li>Each string does not contain leading zeros except for the zero itself.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>位运算 | 数学 | 字符串 | 模拟</details><br>

<div>👍 1032, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//自己
class Solution
{
public:
    string addBinary(string a, string b)
    {
        //现在确保a的长度等于b的长度
        int m = a.length();
        int n = b.length();
        while (m < n)
        {
            a = '0' + a;
            ++m;
        }
        while (m > n)
        {
            b = '0' + b;
            ++n;
        }
        string c(m + 1, '0');
        for (int i = m - 1; i >= 0; --i)
        {
            //10，01，00
            if (c[i + 1] != '1')
            {
                //相加为1的情况
                if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
                {
                    c[i + 1] = '1';
                }
                //相加为0，0+0
                else if (a[i] == '0' && b[i] == '0')
                {
                    c[i + 1] = '0';
                }
                //相加为0，1+1
                else
                {
                    c[i + 1] = '0';
                    c[i] = '1';
                }
            }
            else//c[i]为1的情况，就分3 2 1 三种情况讨论一下就行。也不难感觉。
            {
                if (a[i] == '1' && b[i] == '1')
                {
                    c[i + 1] = '1';
                    c[i] = '1';
                }
                else if ((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0'))
                {
                    c[i + 1] = '0';
                    c[i] = '1';
                }
                //都是0的情况不用处理
            }
        }
        if (c[0] == '1')
        {
            return c;
        }
        else
        {
            return c.substr(1, m);
        }
    }
};

//https://leetcode.cn/problems/add-binary/solution/c-xiang-xi-ti-jie-bu-zou-qing-xi-by-youlookdelicio/
//class Solution {
//public:
//    string addBinary(string a, string b) {
//        //现在确保a的长度等于b的长度
//        int m=a.length();
//        int n=b.length();
//        while ( m<n  )
//        {
//            a='0'+a;
//            ++m;
//        }
//        while ( m>n  )
//        {
//            b='0'+b;
//            ++n;
//        }
//       //从后到前遍历所有的位数，同位相加
//        for (int j = a.size()-1; j >0; --j)
//        {
//            a[j]=a[j]-'0'+b[j];
//            //若大于等于'2'进一
//            if ( a[j]>='2' )
//            {
//                a[j]=(a[j]-'0')%2+'0';
//                a[j-1]=a[j-1]+1;
//            }
//        }
//        //将a,b的第0为相加
//        a[0]=a[0]-'0'+b[0];
//        if ( a[0]>='2' )//大于等于'2'进一
//        {
//            a[0]=(a[0]-'0')%2+'0';
//            a='1'+a;
//        }
//        return a;
//    }
//};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = "Hello LeetCode";
    cout << res << endl;
    string a = "11";
    string b = "1";
    string c = s.addBinary(a, b);
    cout << c << endl;


    return 0;
}