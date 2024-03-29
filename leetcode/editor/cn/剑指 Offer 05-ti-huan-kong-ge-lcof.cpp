/**
<p>English description is not available for the problem. Please switch to Chinese.</p>

<details><summary><strong>Related Topics</strong></summary>字符串</details><br>

<div>👍 511, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//https://leetcode.cn/problems/ti-huan-kong-ge-lcof/discussion/comments/2060446
//class Solution
//{
//public:
//    string replaceSpace(string s)
//    {
//        string ans;
//        for (char ch: s)
//        {
//            if (ch == ' ')
//            {
//                ans += "%20";
//            }
//            else
//            {
//                ans += ch;
//            }
//        }
//        return ans;
//    }
//};
////自己写的
//class Solution
//{
//public:
//    string replaceSpace(string s)
//    {
//       string ans;
//       for (int i = 0; i < s.length(); ++i)
//       {
//           if ( s[i]==' ' )
//           {
//               ans+="%20";
//           }
//           else
//           {
//                ans+=s[i];
//           }
//       }
//
//       return ans;
//    }
//};
//双指针法
class Solution
{
public:
    string replaceSpace(string s)
    {
        int count = 0;
        int oldSize = s.size();
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                ++count;
            }
        }
        s.resize(s.size() + count * 2);
        int newSize = s.size();
        for (int i = newSize - 1, j = oldSize - 1; j < i; --i, --j)
        {
            if (s[j] != ' ')
            {
                s[i] = s[j];
            }
            else
            {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
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
    cout << s.replaceSpace(string("We are happy.")) << endl;


    return 0;
}