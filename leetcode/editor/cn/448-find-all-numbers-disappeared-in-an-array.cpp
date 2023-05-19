/**
<p>Given an array <code>nums</code> of <code>n</code> integers where <code>nums[i]</code> is in the range <code>[1, n]</code>, return <em>an array of all the integers in the range</em> <code>[1, n]</code> <em>that do not appear in</em> <code>nums</code>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> nums = [4,3,2,7,8,2,3,1]
<strong>Output:</strong> [5,6]
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> nums = [1,1]
<strong>Output:</strong> [2]
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>


<ul> 
 <li><code>n == nums.length</code></li> 
 <li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li> 
 <li><code>1 &lt;= nums[i] &lt;= n</code></li> 
</ul>

<p>&nbsp;</p> 
<p><strong>Follow up:</strong> Could you do it without extra space and in <code>O(n)</code> runtime? You may assume the returned list does not count as extra space.</p>

<details><summary><strong>Related Topics</strong></summary>数组 | 哈希表</details><br>

<div>👍 1220, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        //遍历数组，对每个元素都计算出对应的下标
        for (int i = 0; i < nums.size(); ++i)
        {
            //这里计算下标的方式为(nums[i]-1)%n
            //在该代码中，nums[i] 表示数组 nums 的第 i 个元素，(nums[i] - 1) 用于将元素值映射到从 0 开始的下标范围。
            //然后，通过取模运算 % n 将下标限定在 0 到 n-1 的范围内，其中 n 是数组 nums 的长度
            int x = (nums[i] - 1) % n;
            //将下标为x的元素加上n，作为标记
            nums[x] += n;
        }
        //再次遍历数组，如果nums[i]<=n,说明下标i没有标记过i+1计入ans中
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] <= n)
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    //vector<int> data{4,3,2,7,8,2,3,1};
    vector<int> data{1, 1, 1};
    auto res = "Hello LeetCode";
    cout << res << endl;

    vector<int> b = s.findDisappearedNumbers(data);
    for (auto b1: b)
    {
        cout << b1 << endl;
    }


    return 0;
}