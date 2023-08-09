/**
<details><summary><strong>Related Topics</strong></summary>数组 | 滑动窗口</details><br>

<div>👍 18, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//题解来自这里
//https://leetcode.cn/problems/1GxJYY/solutions/1875884/by-shayn-a-0tie/
class Solution
{
public:
    int beautifulBouquet(vector<int> &flowers, int cnt)
    {
        int mod = 1e9 + 7;//取模用的，不取也行
        int ans = 0;
        unordered_map<int, int> count;
        for (int left = 0, right = 0; right < flowers.size(); ++right)
        {
            ++count[flowers[right]];
            while (count[flowers[right]] > cnt)
            {
                --count[flowers[left]];
                ++left;
            }
            ans += right - left + 1;
            ans %= mod;
        }
        return ans;
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