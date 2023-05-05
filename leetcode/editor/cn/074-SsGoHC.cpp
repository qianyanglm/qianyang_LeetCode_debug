/**
<p>English description is not available for the problem. Please switch to Chinese.</p>

<details><summary><strong>Related Topics</strong></summary>数组 | 排序</details><br>

<div>👍 54, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
        if(n==1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> vec;
        vec.push_back(intervals[0]);
        int j =0;
        for(int i = 1;i<n;i++){
            if(intervals[i][0]<=vec[j][1])
                vec[j][1]=max(vec[j][1],intervals[i][1]);
            else{
                vec.push_back(intervals[i]);
                j++;
            }
        }
        return vec;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> data{1,3};
    vector<int> data1{2,6};
    vector<int> data3{11,15};
    vector<int> data2{8,10};
    vector<vector<int>>a;
    a.push_back(data);
    a.push_back(data1);
    a.push_back(data3);
    a.push_back(data2);
    auto res = "Hello LeetCode";
    cout<<res<<endl;
    a=s.merge(a);
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout<<a[i][j]<<" ";
        }
    }

}