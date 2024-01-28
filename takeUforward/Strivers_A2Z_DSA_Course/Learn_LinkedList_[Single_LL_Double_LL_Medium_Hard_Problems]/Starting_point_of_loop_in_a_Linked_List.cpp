/*
Problem Statement: Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that the tail’s next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Examples:

Example 1:
Input:
 head = [1,2,3,4,3,6,10]
Output:
 tail connects to node index 2
Explanation:

Example 2:
Input:
 head = [1,2]
Output:
 no cycle
Explanation:

*/