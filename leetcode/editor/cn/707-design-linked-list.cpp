/**
<p>Design your implementation of the linked list. You can choose to use a singly or doubly linked list.<br /> A node in a singly linked list should have two attributes: <code>val</code> and <code>next</code>. <code>val</code> is the value of the current node, and <code>next</code> is a pointer/reference to the next node.<br /> If you want to use the doubly linked list, you will need one more attribute <code>prev</code> to indicate the previous node in the linked list. Assume all nodes in the linked list are <strong>0-indexed</strong>.</p>

<p>Implement the <code>MyLinkedList</code> class:</p>

<ul> 
 <li><code>MyLinkedList()</code> Initializes the <code>MyLinkedList</code> object.</li> 
 <li><code>int get(int index)</code> Get the value of the <code>index<sup>th</sup></code> node in the linked list. If the index is invalid, return <code>-1</code>.</li> 
 <li><code>void addAtHead(int val)</code> Add a node of value <code>val</code> before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.</li> 
 <li><code>void addAtTail(int val)</code> Append a node of value <code>val</code> as the last element of the linked list.</li> 
 <li><code>void addAtIndex(int index, int val)</code> Add a node of value <code>val</code> before the <code>index<sup>th</sup></code> node in the linked list. If <code>index</code> equals the length of the linked list, the node will be appended to the end of the linked list. If <code>index</code> is greater than the length, the node <strong>will not be inserted</strong>.</li> 
 <li><code>void deleteAtIndex(int index)</code> Delete the <code>index<sup>th</sup></code> node in the linked list, if the index is valid.</li> 
</ul>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
<strong>Output</strong>
[null, null, null, null, 2, null, 3]

<strong>Explanation</strong>
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1-&gt;2-&gt;3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1-&gt;3
myLinkedList.get(1);              // return 3
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>0 &lt;= index, val &lt;= 1000</code></li> 
 <li>Please do not use the built-in LinkedList library.</li> 
 <li>At most <code>2000</code> calls will be made to <code>get</code>, <code>addAtHead</code>, <code>addAtTail</code>, <code>addAtIndex</code> and <code>deleteAtIndex</code>.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>设计 | 链表</details><br>

<div>👍 850, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.gitee.io/article/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>




*/
#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
//单向链表
//class MyLinkedList {
//public:
//    MyLinkedList() {
//        this->size=0;
//        this->head=new ListNode(0);
//    }
//
//    int get(int index) {
//        if ( index<0||index>=size )
//        {
//            return -1;
//        }
//        ListNode*cur=head;
//        for (int i = 0; i <=index; ++i)
//        {
//            cur=cur->next;
//        }
//        return cur->val;
//    }
//
//    void addAtHead(int val) {
//        addAtIndex(0,val);
//    }
//
//    void addAtTail(int val) {
//        addAtIndex(size,val);
//    }
//
//    void addAtIndex(int index, int val) {
//        if ( index>size )
//        {
//            return ;
//        }
//        index= max(0,index);
//        size++;
//        ListNode*pred=head;
//        for (int i = 0; i < index; ++i)
//        {
//            pred=pred->next;
//        }
//        ListNode*toAdd=new ListNode(val);
//        toAdd->next=pred->next;
//        pred->next=toAdd;
//    }
//
//    void deleteAtIndex(int index) {
//        if ( index<0||index>=size )
//        {
//            return ;
//        }
//        size--;
//        ListNode*pred=head;
//        for (int i = 0; i < index; ++i)
//        {
//            pred=pred->next;
//        }
//        ListNode*p=pred->next;
//        pred->next=pred->next->next;
//        delete p;
//    }
//private:
//    int size;
//    ListNode *head;
//};
//双向链表,官方方法二，删除了没用的头或者尾遍历
struct DLinkListNode
{
    int val;
    DLinkListNode *prev, *next;

    DLinkListNode(int _val): val(_val), prev(nullptr), next(nullptr) {}
};

class MyLinkedList
{
public:
    MyLinkedList()
    {
        this->size = 0;
        this->head = new DLinkListNode(0);
        this->tail = new DLinkListNode(0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            return -1;
        }
        DLinkListNode *curr;
        curr = head;
        for (int i = 0; i <= index; ++i)
        {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
        {
            return;
        }
        index = max(0, index);
        DLinkListNode *pred, *succ;
        pred = head;
        for (int i = 0; i < index; ++i)
        {
            pred = pred->next;
        }
        succ = pred->next;
        size++;
        DLinkListNode *toAdd = new DLinkListNode(val);
        toAdd->prev = pred;
        toAdd->next = succ;
        pred->next = toAdd;
        succ->prev = toAdd;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        DLinkListNode *pred, *succ;
        pred = head;
        for (int i = 0; i < index; ++i)
        {
            pred = pred->next;
        }
        succ = pred->next->next;
        size--;
        DLinkListNode *p = pred->next;
        pred->next = succ;
        succ->prev = pred;
        delete p;
    }

private:
    int size;
    DLinkListNode *head;
    DLinkListNode *tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    MyLinkedList s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    vector<vector<int>> data1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = "Hello LeetCode";
    cout << res << endl;


    return 0;
}