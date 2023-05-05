/**
<p>给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。</p>

<p>请必须使用时间复杂度为 <code>O(log n)</code> 的算法。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5,6], target = 5
<strong>输出:</strong> 2
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5,6], target = 2
<strong>输出:</strong> 1
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,3,5,6], target = 7
<strong>输出:</strong> 4
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul> 
 <li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li> 
 <li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li> 
 <li><code>nums</code> 为&nbsp;<strong>无重复元素&nbsp;</strong>的&nbsp;<strong>升序&nbsp;</strong>排列数组</li> 
 <li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数组 | 二分查找</details><br>

<div>👍 2007, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/

#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int n=nums.size();
    int left=0,right=n-1,ans=n;
    while ( left<=right  )
    {
        int mid=((right-left)>>1)+left;//除以二
        if ( target<=nums[mid] )
        {
            ans=mid;
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{1,2,3,4,5,6};
    auto res = "Hello LeetCode";
    cout<<res<<endl;
    cout<<s.searchInsert(data,5);
}