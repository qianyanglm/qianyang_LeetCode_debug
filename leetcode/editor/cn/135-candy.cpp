/**
<p>There are <code>n</code> children standing in a line. Each child is assigned a rating value given in the integer array <code>ratings</code>.</p>

<p>You are giving candies to these children subjected to the following requirements:</p>

<ul> 
 <li>Each child must have at least one candy.</li> 
 <li>Children with a higher rating get more candies than their neighbors.</li> 
</ul>

<p>Return <em>the minimum number of candies you need to have to distribute the candies to the children</em>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> ratings = [1,0,2]
<strong>Output:</strong> 5
<strong>Explanation:</strong> You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> ratings = [1,2,2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>n == ratings.length</code></li> 
 <li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li> 
 <li><code>0 &lt;= ratings[i] &lt;= 2 * 10<sup>4</sup></code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>贪心 | 数组</details><br>

<div>👍 1255, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//贪心
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> candyVec(ratings.size(), 1);
        //右比左大
        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }
        //左比右大
        for (int i = ratings.size() - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        //统计结果
        int result = 0;
        for (int i = 0; i < candyVec.size(); ++i)
        {
            result += candyVec[i];
        }
        return result;
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


    return 0;
}