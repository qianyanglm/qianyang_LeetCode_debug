/**
<p>Given an array of strings <code>strs</code>, group <strong>the anagrams</strong> together. You can return the answer in <strong>any order</strong>.</p>

<p>An <strong>Anagram</strong> is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> strs = ["eat","tea","tan","ate","nat","bat"]
<strong>Output:</strong> [["bat"],["nat","tan"],["ate","eat","tea"]]
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> strs = [""]
<strong>Output:</strong> [[""]]
</pre>
<p><strong class="example">Example 3:</strong></p> 
<pre><strong>Input:</strong> strs = ["a"]
<strong>Output:</strong> [["a"]]
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= strs.length &lt;= 10<sup>4</sup></code></li> 
 <li><code>0 &lt;= strs[i].length &lt;= 100</code></li> 
 <li><code>strs[i]</code> consists of lowercase English letters.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数组 | 哈希表 | 字符串 | 排序</details><br>

<div>👍 1496, 👎 0<span style='float: right;'></span></div>




*/
#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//官方
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        //排序之后的字符串作为哈希表的键
        for (string &str: strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<string> data1{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = "Hello LeetCode";
    cout << res << endl;
    for (auto i: s.groupAnagrams(data1))
    {
        for (auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}