/**
<p>You are climbing a staircase. It takes <code>n</code> steps to reach the top.</p>

<p>Each time you can either climb <code>1</code> or <code>2</code> steps. In how many distinct ways can you climb to the top?</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= n &lt;= 45</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>记忆化搜索 | 数学 | 动态规划</details><br>

<div>👍 3076, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//递归会超时，弃用
//class Solution {
//public:
//    int climbStairs(int n) {
//        if ( n<=2 )
//        {
//            return n;
//        }
//        return climbStairs(n-1)+ climbStairs(n-2);
//    }
//};
//动规，根据斐波那契动规可以想出来
//class Solution
//{
//public:
//    int climbStairs(int n)
//    {
//        if (n <= 2)
//        {
//            return n;
//        }
//        vector<int> dp(n + 1);
//        dp[1] = 1;
//        dp[2] = 2;
//        for (int i = 3; i <= n; ++i)
//        {
//            dp[i] = dp[i - 1] + dp[i - 2];
//        }
//        return dp[n];
//    }
//};
//斐波那契的动规，自己重复写的
//class Solution
//{
//public:
//    int climbStairs(int n)
//    {
//        if ( n<=3 )
//        {
//            return n;
//        }
//       vector<int>dp(n+1,0);
//       dp[1]=1;
//       dp[2]=2;
//       for (int i = 3; i <= n; ++i)
//       {
//           dp[i]=dp[i-1]+dp[i-2];
//       }
//       return dp[n];
//    }
//};
//用这次学的动规
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= n; ++j)
        {
            for (int i = 1; i <= 2; ++i)
            {
                if (j >= i)
                {
                    dp[j] += dp[j - i];
                }
            }
        }
        return dp[n];
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
    cout << s.climbStairs(3) << endl;
    cout << s.climbStairs(45) << endl;


    return 0;
}