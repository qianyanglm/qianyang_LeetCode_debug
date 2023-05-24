/**
<p>Given an integer array <code>nums</code>, handle multiple queries of the following type:</p>

<ol> 
 <li>Calculate the <strong>sum</strong> of the elements of <code>nums</code> between indices <code>left</code> and <code>right</code> <strong>inclusive</strong> where <code>left &lt;= right</code>.</li> 
</ol>

<p>Implement the <code>NumArray</code> class:</p>

<ul> 
 <li><code>NumArray(int[] nums)</code> Initializes the object with the integer array <code>nums</code>.</li> 
 <li><code>int sumRange(int left, int right)</code> Returns the <strong>sum</strong> of the elements of <code>nums</code> between indices <code>left</code> and <code>right</code> <strong>inclusive</strong> (i.e. <code>nums[left] + nums[left + 1] + ... + nums[right]</code>).</li> 
</ul>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
<strong>Output</strong>
[null, 1, -1, -3]

<strong>Explanation</strong>
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li> 
 <li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li> 
 <li><code>0 &lt;= left &lt;= right &lt; nums.length</code></li> 
 <li>At most <code>10<sup>4</sup></code> calls will be made to <code>sumRange</code>.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>设计 | 数组 | 前缀和</details><br>

<div>👍 556, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//官方
class NumArray
{
public:
    vector<int> sums;

    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 0; i < n; ++i)
        {
            sums[i + 1] = sums[i] + nums[i];
        }
    }

    //其实很简单，就是前面的每一个相加的和都记录了下来，后-前=中间的和
    int sumRange(int left, int right)
    {
        return sums[right + 1] - sums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main()
{

    vector<int> data{-2, 0, 3, -5, 2, -1};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = "Hello LeetCode";
    cout << res << endl;
    NumArray numArray(data);
    cout << numArray.sumRange(0, 2);// return 1 ((-2) + 0 + 3)
    cout << numArray.sumRange(2, 5);// return -1 (3 + (-5) + 2 + (-1))
    cout << numArray.sumRange(0, 5);// return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))


    return 0;
}