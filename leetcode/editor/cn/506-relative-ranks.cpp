/**
<p>You are given an integer array <code>score</code> of size <code>n</code>, where <code>score[i]</code> is the score of the <code>i<sup>th</sup></code> athlete in a competition. All the scores are guaranteed to be <strong>unique</strong>.</p>

<p>The athletes are <strong>placed</strong> based on their scores, where the <code>1<sup>st</sup></code> place athlete has the highest score, the <code>2<sup>nd</sup></code> place athlete has the <code>2<sup>nd</sup></code> highest score, and so on. The placement of each athlete determines their rank:</p>

<ul> 
 <li>The <code>1<sup>st</sup></code> place athlete's rank is <code>"Gold Medal"</code>.</li> 
 <li>The <code>2<sup>nd</sup></code> place athlete's rank is <code>"Silver Medal"</code>.</li> 
 <li>The <code>3<sup>rd</sup></code> place athlete's rank is <code>"Bronze Medal"</code>.</li> 
 <li>For the <code>4<sup>th</sup></code> place to the <code>n<sup>th</sup></code> place athlete, their rank is their placement number (i.e., the <code>x<sup>th</sup></code> place athlete's rank is <code>"x"</code>).</li> 
</ul>

<p>Return an array <code>answer</code> of size <code>n</code> where <code>answer[i]</code> is the <strong>rank</strong> of the <code>i<sup>th</sup></code> athlete.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> score = [5,4,3,2,1]
<strong>Output:</strong> ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
<strong>Explanation:</strong> The placements are [1<sup>st</sup>, 2<sup>nd</sup>, 3<sup>rd</sup>, 4<sup>th</sup>, 5<sup>th</sup>].</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> score = [10,3,8,9,4]
<strong>Output:</strong> ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
<strong>Explanation:</strong> The placements are [1<sup>st</sup>, 5<sup>th</sup>, 3<sup>rd</sup>, 2<sup>nd</sup>, 4<sup>th</sup>].

</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>n == score.length</code></li> 
 <li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li> 
 <li><code>0 &lt;= score[i] &lt;= 10<sup>6</sup></code></li> 
 <li>All the values in <code>score</code> are <strong>unique</strong>.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数组 | 排序 | 堆（优先队列）</details><br>

<div>👍 217, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {

        vector<string> result;
        vector<int> score1(score);
        sort(score.rbegin(), score.rend());
        map<int, string> a;
        int n = score.size();
        for (int i = 0; i < n; ++i)
        {
            if (i == 0)
            {
                a[score[0]] = "Gold Medal";
            }
            if (i == 1)
            {
                a[score[1]] = "Silver Medal";
            }
            if (i == 2)
            {
                a[score[2]] = "Bronze Medal";
            }
            if (i >= 3)
            {
                a[score[i]] = to_string(i + 1);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            result.push_back(a[score1[i]]);
        }
        return result;
    }
};//自己写的

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{5, 4, 3, 2, 1};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = "Hello LeetCode";
    cout << res << endl;
    for (string &s1: s.findRelativeRanks(data))
    {
        cout << s1 << " ";
    }
    cout << endl;


    return 0;
}