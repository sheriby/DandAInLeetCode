# From LeetCode 142. [Linked List Cycle II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

## Description

**Given a linked list, return the node where the cycle begins. If there is no cycle, return `null`.*

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.


## Example1

> **Input**: head = [3,2,0,-4], pos = 1  
>
> **Output**: tail connects to node index 1  
>
> **Explanation**: There is a cycle in the linked list, where tail connects to the second node.

![](img\circularlinkedlist.png)

## Example2

> **Input**: head = [1, 2], pos = 0  
>
> **Output**: tail connects to node index 0
>
> **Explanation**: There is a cycle in the linked list, where tail connects to the first node.

![](img\circularlinkedlist_test2.png)

## Example3

> **Input**: head = [1], pos = -1  
>
> **Output**: no cycle
>
> **Explanation**: TThere is no cycle in the linked list.

![](img\circularlinkedlist_test3.png)

## Follow up
Can you solve it without using extra space?



