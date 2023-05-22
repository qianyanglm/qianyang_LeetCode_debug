/**
<p>Given an <code>m x n</code> matrix <code>board</code> where each cell is a battleship <code>'X'</code> or empty <code>'.'</code>, return <em>the number of the <strong>battleships</strong> on</em> <code>board</code>.</p>

<p><strong>Battleships</strong> can only be placed horizontally or vertically on <code>board</code>. In other words, they can only be made of the shape <code>1 x k</code> (<code>1</code> row, <code>k</code> columns) or <code>k x 1</code> (<code>k</code> rows, <code>1</code> column), where <code>k</code> can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/10/battelship-grid.jpg" style="width: 333px; height: 333px;" /> 
<pre>
<strong>Input:</strong> board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> board = [["."]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>m == board.length</code></li> 
 <li><code>n == board[i].length</code></li> 
 <li><code>1 &lt;= m, n &lt;= 200</code></li> 
 <li><code>board[i][j]</code> is either <code>'.'</code> or <code>'X'</code>.</li> 
</ul>

<p>&nbsp;</p> 
<p><strong>Follow up:</strong> Could you do it in one-pass, using only <code>O(1)</code> extra memory and without modifying the values <code>board</code>?</p>

<details><summary><strong>Related Topics</strong></summary>深度优先搜索 | 数组 | 矩阵</details><br>

<div>👍 243, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//官方
class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int row = board.size();   //行
        int col = board[0].size();//列
        int ans = 0;              //战舰计数
        //遍历行列
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                //战舰X替换为.  ans+1
                if (board[i][j] == 'X')
                {
                    board[i][j] = '.';
                    //下面两个循环一次只用一个，因为战舰只能是行或者列，不会相邻,而且下面的两个循环不分先后
                    //遍历一行，行战舰X替换为.
                    for (int k = j + 1; k < col && board[i][k] == 'X'; ++k)
                    {
                        board[i][k] = '.';
                    }
                    //遍历一列,列战舰X替换为.
                    for (int k = i + 1; k < row && board[k][j] == 'X'; ++k)
                    {
                        board[k][j] = '.';
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<char>> data1{{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
    auto res = "Hello LeetCode";
    cout << res << endl;

    cout << s.countBattleships(data1) << endl;

    return 0;
}