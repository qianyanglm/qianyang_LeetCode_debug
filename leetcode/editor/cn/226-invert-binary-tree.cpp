/**
<p>Given the <code>root</code> of a binary tree, invert the tree, and return <em>its root</em>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg" style="width: 500px; height: 165px;" /> 
<pre>
<strong>Input:</strong> root = [4,2,7,1,3,6,9]
<strong>Output:</strong> [4,7,2,9,6,3,1]
</pre>

<p><strong class="example">Example 2:</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg" style="width: 500px; height: 120px;" /> 
<pre>
<strong>Input:</strong> root = [2,1,3]
<strong>Output:</strong> [2,3,1]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li>The number of nodes in the tree is in the range <code>[0, 100]</code>.</li> 
 <li><code>-100 &lt;= Node.val &lt;= 100</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>树 | 深度优先搜索 | 广度优先搜索 | 二叉树</details><br>

<div>👍 1627, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




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
// //二叉树翻转，前序递归遍历交换
//class Solution {
//public:
//    TreeNode* invertTree(TreeNode* root) {
//        if ( root==NULL )
//        {
//            return root;
//        }
//        swap(root->left,root->right);
//        invertTree(root->left);
//        invertTree(root->right);
//        return root;
//    }
//};
// //二叉树翻转，后序递归遍历交换
//class Solution {
//public:
//    TreeNode* invertTree(TreeNode* root) {
//        if ( root==NULL )
//        {
//            return root;
//        }
//        invertTree(root->left);
//        invertTree(root->right);
//        swap(root->left,root->right);
//        return root;
//    }
//};
// //二叉树翻转，层序递归遍历交换
//class Solution {
//public:
//    TreeNode* invertTree(TreeNode* root) {
//        queue<TreeNode*>que;
//        if ( root!=NULL )
//        {
//            que.push(root);
//        }
//        while ( !que.empty()  )
//        {
//            int size=que.size();
//            for (int i = 0; i < size; ++i)
//            {
//                TreeNode*node=que.front();
//                que.pop();
//                swap(node->left,node->right);
//                if ( node->left )
//                {
//                    que.push(node->left);
//                }
//                if ( node->right )
//                {
//                    que.push(node->right);
//                }
//            }
//        }
//        return root;
//    }
//};
//二叉树翻转，中序递归遍历交换
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return root;
        }
        invertTree(root->left);
        swap(root->left, root->right);
        //这里还要遍历左子树，因为左子树翻转一次了。
        invertTree(root->left);
        return root;
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