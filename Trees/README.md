# Double Thread Binary Search Tree

Link: https://www.geeksforgeeks.org/double-threaded-binary-search-tree/

A binary search tree in which the nodes are not every left NULL pointer points to its inorder predecessor and the right NULL pointer points to the inorder successor.

The threads are also useful for fast accessing the ancestors of a node.

Double Threaded Binary Search Tree is one of the most used types of Advanced data structures used in many real-time applications like places where there are recent insertion and traversal of all elements of the search tree.

## Creation algorithm for Double Threaded Binary Search Tree
- In Double Threaded Binary search tree, there are five fields namely, data fields, left, right pointers, lbit, and rbit where lbit and rbit are boolean value stored to denote the right pointer points to an inorder successor or a new child node. Similarly, lbit denotes that the left pointer points to an inorder predecessor or a new child node.
- Base condition for the creation of the Double Threaded binary search tree is that the root node exists or not, If it doesn't exist then create a new node and store it.
- Otherwise, compare the data of the current node to the new Data to be inserted, If the new data is less than the current data then traverse to the left child node. Otherwise, traverse to the right child node.
- If the left child or right child doesn't exist then insert the node to its left and point its left and right child to the inorder predecessor and succussor respectively.