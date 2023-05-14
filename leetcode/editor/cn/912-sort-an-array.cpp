/**
<p>Given an array of integers <code>nums</code>, sort the array in ascending order and return it.</p>

<p>You must solve the problem <strong>without using any built-in</strong> functions in <code>O(nlog(n))</code> time complexity and with the smallest space complexity possible.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,2,3,1]
<strong>Output:</strong> [1,2,3,5]
<strong>Explanation:</strong> After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,1,1,2,0,0]
<strong>Output:</strong> [0,0,1,1,2,5]
<strong>Explanation:</strong> Note that the values of nums are not necessairly unique.
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li> 
 <li><code>-5 * 10<sup>4</sup> &lt;= nums[i] &lt;= 5 * 10<sup>4</sup></code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数组 | 分治 | 桶排序 | 计数排序 | 基数排序 | 排序 | 堆（优先队列） | 归并排序</details><br>

<div>👍 839, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int i = left, j = right;
        //int pivot =nums[left];
        int pivot = nums[rand() % (right - left + 1) + 1];
        while (i < j)
        {
            while (i < j && nums[j] >= pivot)
            {
                j--;
            }
            nums[i] = nums[j];
            while (i < j && nums[i] <= pivot)
            {
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        //这个方法也不行，再想办法
        //        quickSort(nums,0,nums.size()-1);
        //        return nums;
        //冒泡排序可以，但是超时了，换一个办法
        //    int n=nums.size();
        //    for (int i = 0; i < n-1; ++i)
        //    {
        //        for (int j = 0; j < n-1-i; ++j)
        //        {
        //            if ( nums[j]>nums[j+1] )
        //            {
        //                //swap(nums[j],nums[j+1]);
        //                 int temp = nums[j + 1];
        //                            nums[j + 1] = nums[j];
        //                            nums[j] = temp;
        //            }
        //        }
        //    }
        //    return nums;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    auto res = "Hello LeetCode";
    cout << res << endl;

    data = s.sortArray(data);
    for (int i = 0; i < data.size(); ++i)
    {
        cout << data[i] << " ";
    }


    return 0;
}