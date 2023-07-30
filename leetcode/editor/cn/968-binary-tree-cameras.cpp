/**
/**
<p>You are given the <code>root</code> of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.</p>

<p>Return <em>the minimum number of cameras needed to monitor all nodes of the tree</em>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_01.png" style="width: 138px; height: 163px;" /> 
<pre>
<strong>Input:</strong> root = [0,0,null,0,0]
<strong>Output:</strong> 1
<strong>Explanation:</strong> One camera is enough to monitor all nodes if placed as shown.
</pre>

<p><strong class="example">Example 2:</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_02.png" style="width: 139px; height: 312px;" /> 
<pre>
<strong>Input:</strong> root = [0,0,null,0,null,0,null,null,0]
<strong>Output:</strong> 2
<strong>Explanation:</strong> At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li>The number of nodes in the tree is in the range <code>[1, 1000]</code>.</li> 
 <li><code>Node.val == 0</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>树 | 深度优先搜索 | 动态规划 | 二叉树</details><br>

<div>👍 629, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/

#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//贪心
class Solution
{
private:
    int result;

    int traversal(TreeNode *cur)
    {
        if (cur == NULL) return 2;

        int left = traversal(cur->left);
        int right = traversal(cur->right);

        if (left == 2 && right == 2) return 0;

        if (left == 0 || right == 0)
        {
            result++;
            return 1;
        }

        if (left == 1 || right == 1) return 2;

        return -1;
    }

public:
    int minCameraCover(TreeNode *root)
    {
        result = 0;
        if (traversal(root) == 0)
        {
            result++;
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