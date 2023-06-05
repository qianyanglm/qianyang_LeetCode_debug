/**
<p>Given a string <code>expression</code> representing an expression of fraction addition and subtraction, return the calculation result in string format.</p>

<p>The final result should be an <a href="https://en.wikipedia.org/wiki/Irreducible_fraction" target="_blank">irreducible fraction</a>. If your final result is an integer, change it to the format of a fraction that has a denominator <code>1</code>. So in this case, <code>2</code> should be converted to <code>2/1</code>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> expression = "-1/2+1/2"
<strong>Output:</strong> "0/1"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> expression = "-1/2+1/2+1/3"
<strong>Output:</strong> "1/3"
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> expression = "1/3-1/2"
<strong>Output:</strong> "-1/6"
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li>The input string only contains <code>'0'</code> to <code>'9'</code>, <code>'/'</code>, <code>'+'</code> and <code>'-'</code>. So does the output.</li> 
 <li>Each fraction (input and output) has the format <code>±numerator/denominator</code>. If the first input fraction or the output is positive, then <code>'+'</code> will be omitted.</li> 
 <li>The input only contains valid <strong>irreducible fractions</strong>, where the <strong>numerator</strong> and <strong>denominator</strong> of each fraction will always be in the range <code>[1, 10]</code>. If the denominator is <code>1</code>, it means this fraction is actually an integer in a fraction format defined above.</li> 
 <li>The number of given fractions will be in the range <code>[1, 10]</code>.</li> 
 <li>The numerator and denominator of the <strong>final result</strong> are guaranteed to be valid and in the range of <strong>32-bit</strong> int.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数学 | 字符串 | 模拟</details><br>

<div>👍 136, 👎 0<span style='float: right;'></span></div>




*/
#include "include/headers.h"


//leetcode submit region begin(Prohibit modification and deletion)
//官方
class Solution
{
public:
    string fractionAddition(string expression)
    {
        long long x = 0, y = 1;//分子和分母
        int index = 0, n = expression.size();
        while (index < n)
        {
            long long x1 = 0, sign = 1;
            if (expression[index] == '-' || expression[index] == '+')
            {
                sign = expression[index] == '-' ? -1 : 1;
                index++;
            }
            while (index < n && isdigit(expression[index]))
            {
                //这一步是将字符表示的数字转换为实际的数字值，并将其用作分数的分子
                //*10是因为分子可能大于9，分母也同理
                x1 = x1 * 10 + expression[index] - '0';
                index++;
            }
            x1 = sign * x1;
            index++;

            //读取分母
            long long y1 = 0;
            while (index < n && isdigit(expression[index]))
            {
                y1 = y1 * 10 + expression[index] - '0';
                index++;
            }

            x = x * y1 + x1 * y;
            y *= y1;
        }
        if (x == 0)
        {
            return "0/1";
        }
        //这里改了一下gcd的引用
        long long g = __gcd(abs(x), y);
        return to_string(x / g) + "/" + to_string(y / g);
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = "-1/2+1/2";
    cout << res << endl;
    cout << s.fractionAddition(res) << endl;


    return 0;
}