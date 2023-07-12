/**
<p>Given the <code>root</code> of a binary tree, return <em>all root-to-leaf paths in <strong>any order</strong></em>.</p>

<p>A <strong>leaf</strong> is a node with no children.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/12/paths-tree.jpg" style="width: 207px; height: 293px;" /> 
<pre>
<strong>Input:</strong> root = [1,2,3,null,5]
<strong>Output:</strong> ["1-&gt;2-&gt;5","1-&gt;3"]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [1]
<strong>Output:</strong> ["1"]
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li>The number of nodes in the tree is in the range <code>[1, 100]</code>.</li> 
 <li><code>-100 &lt;= Node.val &lt;= 100</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>树 | 深度优先搜索 | 字符串 | 回溯 | 二叉树</details><br>

<div>👍 974, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




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
//二叉树
class Solution
{
private:
    void traversal(TreeNode *cur, vector<int> &path, vector<string> &result)
    {
        path.push_back(cur->val);
        if (cur->left == NULL && cur->right == NULL)
        {
            string sPath;
            for (int i = 0; i < path.size() - 1; ++i)
            {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        if (cur->left)
        {
            traversal(cur->left, path, result);
            path.pop_back();
        }
        if (cur->right)
        {
            traversal(cur->right, path, result);
            path.pop_back();
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        vector<int> path;
        if (root == NULL) return result;
        traversal(root, path, result);
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