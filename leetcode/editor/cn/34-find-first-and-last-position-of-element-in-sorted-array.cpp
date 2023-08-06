/**
<p>Given an array of integers <code>nums</code> sorted in non-decreasing order, find the starting and ending position of a given <code>target</code> value.</p>

<p>If <code>target</code> is not found in the array, return <code>[-1, -1]</code>.</p>

<p>You must&nbsp;write an algorithm with&nbsp;<code>O(log n)</code> runtime complexity.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> nums = [5,7,7,8,8,10], target = 8
<strong>Output:</strong> [3,4]
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> nums = [5,7,7,8,8,10], target = 6
<strong>Output:</strong> [-1,-1]
</pre>
<p><strong class="example">Example 3:</strong></p> 
<pre><strong>Input:</strong> nums = [], target = 0
<strong>Output:</strong> [-1,-1]
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>0 &lt;= nums.length &lt;= 10<sup>5</sup></code></li> 
 <li><code>-10<sup>9</sup>&nbsp;&lt;= nums[i]&nbsp;&lt;= 10<sup>9</sup></code></li> 
 <li><code>nums</code> is a non-decreasing array.</li> 
 <li><code>-10<sup>9</sup>&nbsp;&lt;= target&nbsp;&lt;= 10<sup>9</sup></code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数组 | 二分查找</details><br>

<div>👍 2405, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//二分法
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
        if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};
        return {-1, -1};
    }

private:
    int getRightBorder(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) right = middle - 1;
            else
            {
                left = middle + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }

    int getLeftBorder(vector<int> nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] >= target)
            {
                right = middle - 1;
                leftBorder = right;
            }
            else
                left = middle + 1;
        }
        return leftBorder;
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
