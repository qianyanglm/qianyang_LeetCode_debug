/**
<p>Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (<code>push</code>, <code>top</code>, <code>pop</code>, and <code>empty</code>).</p>

<p>Implement the <code>MyStack</code> class:</p>

<ul> 
 <li><code>void push(int x)</code> Pushes element x to the top of the stack.</li> 
 <li><code>int pop()</code> Removes the element on the top of the stack and returns it.</li> 
 <li><code>int top()</code> Returns the element on the top of the stack.</li> 
 <li><code>boolean empty()</code> Returns <code>true</code> if the stack is empty, <code>false</code> otherwise.</li> 
</ul>

<p><b>Notes:</b></p>

<ul> 
 <li>You must use <strong>only</strong> standard operations of a queue, which means that only <code>push to back</code>, <code>peek/pop from front</code>, <code>size</code> and <code>is empty</code> operations are valid.</li> 
 <li>Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.</li> 
</ul>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
<strong>Output</strong>
[null, null, null, 2, 2, false]

<strong>Explanation</strong>
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= x &lt;= 9</code></li> 
 <li>At most <code>100</code> calls will be made to <code>push</code>, <code>pop</code>, <code>top</code>, and <code>empty</code>.</li> 
 <li>All the calls to <code>pop</code> and <code>top</code> are valid.</li> 
</ul>

<p>&nbsp;</p> 
<p><strong>Follow-up:</strong> Can you implement the stack using only one queue?</p>

<details><summary><strong>Related Topics</strong></summary>栈 | 设计 | 队列</details><br>

<div>👍 723, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
////官方，也无法实现本地调试
//class MyStack
//{
//public:
//    queue<int> queue1;
//    queue<int> queue2;
//
//    MyStack()
//    {
//    }
//
//    void push(int x)
//    {
//        queue2.push(x);
//        while (!queue1.empty())
//        {
//            queue2.push(queue1.front());
//            queue1.pop();
//        }
//        swap(queue1, queue2);
//    }
//
//    int pop()
//    {
//        int r = queue1.front();
//        queue1.pop();
//        return r;
//    }
//
//    int top()
//    {
//        int r = queue1.front();
//        return r;
//    }
//
//    bool empty()
//    {
//        return queue1.empty();
//    }
//};
//栈
class MyStack
{
public:
    queue<int> que1;
    queue<int> que2;

    MyStack()
    {
    }

    void push(int x)
    {
        que1.push(x);
    }

    int pop()
    {
        int size = que1.size();
        size--;
        while (size--)
        {
            que2.push(que1.front());
            que1.pop();
        }

        int result = que1.front();
        que1.pop();
        que1 = que2;
        while (!que2.empty())
        {
            que2.pop();
        }
        return result;
    }

    int top()
    {
        return que1.back();
    }

    bool empty()
    {
        return que1.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    MyStack s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = "Hello LeetCode";
    cout << res << endl;


    return 0;
}