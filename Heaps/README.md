# Heap - Heap Sort - Heapify - Priority Queues

## Heap using array
- Node's Index
	- Parent => `(childIndex - 2) / 2` (floor)
	- left child => `parentIndex * 2 + 1`
	- right child => `parentIndex * 2 - 1`
- Filling a new item
	- fill an item level by level.
	- if there are a missing node, so let it blank.

## Topics
1. Array Representation of BT
2. Complete Binary Tree
	- maximum #nodes = 2^(h+1) - 1
	- full binary tree -> there are maximum nodes in each height of the tree.
	- strictly complete binary tree -> each internal node has exactly 2 children.
		- element must be inserted from left to right in each level so there is no gap in an array representing binary tree.
	- complete binary tree -> each internal node does not need to have exactly 2 children.
		- element must be inserted from left to right in each level.
		- the height of complete binary tree always minimum as log(n).
3. Heap 
	- heap is a complete binary tree.
		- Max Heap
			- every node having the value greater than all of its descendants.
			- the root node has the largest value.
		- Min Heap
			- every node having the value smaller than all of its descendants.
			- the root node has the smallest value.
4. Insert & Delete
	- Insert (adjustment upwards)
		- insert at the last position (insert at the leaf) and then heapify up to adjust the tree to follow the heap property.
			- compare the value to the parent node and then swap.
		- time taken for insertion is depend on the height of the tree (minimum is `O(1)` and maximum is `O(log(n))`) 
	- Delete (adjustment downwards)
		- an element is always deleted at root of the heap.
		- replace the root element with the last element, delete the last element, and then heapify down to adjust the tree to follow the heap property.
			- find the best value to be a new root node by comparing the descendants of the node.
				- Max Heap: find the new max value
				- Min Heap: find the new min value
		- time taken for insertion is depend on the height of the tree (`O(log(n))`)
5. Heap Sort 
	- heap sort has 2 steps
		1. create a heap by inserting an element one by one. (time: `n(log(n))`)
		2. delete an element one by one and take the deleted element into the new place, then we can get sorted heap. (time: `n(log(n))`)
	- time taken for sorting is n(log(n)) + n(log(n)) = 2n(log(n)) which is `O(nlog(n))`
6. Heapify
	- heapify is the procedure to creating a heap from a binary tree that does not follow the heap property.
		- check whether a node is a heap starting from the last element to the first element (root node).
			- if not, compare to the descendants and swap it value.
	- time taken is `O(n)`
7. Priority Queue
	- the element has priority.
	- the insertion and deletion is based on the priority.
		- delete: remove the highest element (highest priority) from the queue.
	- using array 
		- it take `O(n)` time to deletion (because you need to shipf the left element up to deleted position)
	- using heap
		- heap is the best data structure for implementing a Priority Queue.
		- it take `O(log(n))` time to deletion and insertion.
		- Min Heap: smaller number, higher priority
		- Max Heap: Larger number, higher priority

--- 