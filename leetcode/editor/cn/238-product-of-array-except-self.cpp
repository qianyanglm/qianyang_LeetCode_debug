/**
<p>Given an integer array <code>nums</code>, return <em>an array</em> <code>answer</code> <em>such that</em> <code>answer[i]</code> <em>is equal to the product of all the elements of</em> <code>nums</code> <em>except</em> <code>nums[i]</code>.</p>

<p>The product of any prefix or suffix of <code>nums</code> is <strong>guaranteed</strong> to fit in a <strong>32-bit</strong> integer.</p>

<p>You must write an algorithm that runs in&nbsp;<code>O(n)</code>&nbsp;time and without using the division operation.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> [24,12,8,6]
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> nums = [-1,1,0,-3,3]
<strong>Output:</strong> [0,0,9,0,0]
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li> 
 <li><code>-30 &lt;= nums[i] &lt;= 30</code></li> 
 <li>The product of any prefix or suffix of <code>nums</code> is <strong>guaranteed</strong> to fit in a <strong>32-bit</strong> integer.</li> 
</ul>

<p>&nbsp;</p> 
<p><strong>Follow up:</strong>&nbsp;Can you solve the problem in <code>O(1)&nbsp;</code>extra&nbsp;space complexity? (The output array <strong>does not</strong> count as extra space for space complexity analysis.)</p>

<details><summary><strong>Related Topics</strong></summary>数组 | 前缀和</details><br>

<div>👍 1457, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//官方
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int length = nums.size();
        //L R分贝是左右两侧乘积列表
        vector<int> L(length, 0), R(length, 0);
        vector<int> answer(length);
        //L[i]表示索引i左侧所有元素的乘积，L[0]=1,因为左侧没有元素
        L[0] = 1;
        for (int i = 1; i < length; ++i)
        {
            L[i] = nums[i - 1] * L[i - 1];
        }
        //R[i]为索引i右侧所有元素成绩length-1右侧没有元素，所以R[length-1]=1
        R[length - 1] = 1;
        for (int i = length - 2; i >= 0; --i)
        {
            R[i] = nums[i + 1] * R[i + 1];
        }
        //L[i]就是i左右两侧所有元素成绩
        for (int i = 0; i < length; ++i)
        {
            answer[i] = L[i] * R[i];
        }
        return answer;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{1, 2, 3, 4};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = "Hello LeetCode";
    cout << res << endl;
    data = s.productExceptSelf(data);
    for (int a: data)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}