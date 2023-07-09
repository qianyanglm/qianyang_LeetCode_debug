//
// Created by A on 2023/7/9.
//
#ifndef LEETCODE_DEBUG_LEETCODE_EDITOR_CN_INCLUDE_NODE_H_
#define LEETCODE_DEBUG_LEETCODE_EDITOR_CN_INCLUDE_NODE_H_
#include <vector>

class Node
{
public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
#endif//LEETCODE_DEBUG_LEETCODE_EDITOR_CN_INCLUDE_NODE_H_
