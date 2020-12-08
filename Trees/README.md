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

---

# B Tree
B-tree is a self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time.

## Specifications of B-Tree
given 'B' is the branching factor (the bound of the number of children at each node)
1. B <= #of child < 2B
2. B - 1 <= #of keys < 2B - 1
3. It's completely balanced. (All the leaves are at the same depth)
4. All the keys in the node are sorted.

For example: 2-3 Tree 
- branchind factor = 2
- it can have 2 to 3 child and 1 to 2 keys at each child (node)

## Operations on B-Tree
- Searching 
	- Look the value to find in key's node
	- If found, then it's done.
	- If not found, go down to the node btween the key smaller than looking value and the key larger than looking value.
	- Do until we found the looking value, If we reach the leaf node and no looking value here then there is no looking value at this tree.
- Insertion
	- split (when node is overfull after inserting a new element into the node)
		- take the element (key) in the middle of the node and move to the parent node.
		- If the parent node is overfull after inserting, then keep doing this kind of process until that last node is not overfull. (may be we have a new root node at the top)
- Deletion
	- nothing special (just delete) or replace with the leftmost of the right sub tree
	- Balancing the tree after deleting
		- merge
		- donate the key and do the rotation

---

# B-Tree & B+ Tree

## Topics
1. Disk Structure
	- Tracks, sectors -> address of block is in form of (track number, sector number)
	- 1 block' size is typically 512 byte -> address of byte is called offset.
2. How Data is stored on Disk?
3. What is Indexing?
4. What is Multilevel Indexing
	- adding more index to reduce the number of block to access
5. M-way Search Trees
	- M-way Search Trees -> m children and m-1 keys
6. B-Trees
	- each node must have at least m/2 (ceiling) children.
	- root can have minimum 2 children.
	- all leaf nodes must be at same level.
	- creation process is bottom-up.
7. Insertion & Deletion - B-Trees
	- whenever the node is becoming filled, we are splitting it and send it to the key of the parent.
	- for using with database to store an index, each key in a node contains keys, address of the record of that index and child's address.
8. B+ Tree
	- there are only record pointers on leaf node.
	- every key in the tree will definitely present in a leaf and each leaf node is connected each other like a linkelist.


---

# AVL Trees

## Topics
1. What is Binary Search Tree (BST)?
	- A tree which each node can have at most 2 children.
	- the node on the left sub-tree is less than the parent node.
	- the node on the right sub-tree is greater than the parent node.
	- the searching time is depend on the height of the tree.
		- min height = log(n)
		- max height = n
	- there is no duplicate value (node) on the BST.
	- the shape of the BST is depend of the order of an insertion (even both set of keys are the same  but if the insertion orders are different, it gonna makes the shape of the tree different.)
		- the searching time is depend on how keys are inserted.
		- n keys -> there are possible n! insert way, there are at most n! shape (some insert way can give the same shape)
		- so we want to keep the height of the tree as minimum as possible. (that's why we need to rotate to re-shape the tree or balancing the tree)
2. Drawback of BST
3. How BST can be improved?
	- inorder to improved the searching time we want to minimize the height of the BST.
		- we can rotate the BST to re-shape the tree -> rotate right or rotate left.
		- sometime we need to rotate more than one time.
		- rotations are done only on three nodes.
4. What is an AVL Tree?
	- AVL Tree is a height balanced binary search tree.
	- balance factor -> tell whether the tree is balanced or not.
		- balance factor = height of left subtree - height of right subtree
		- `balance factor (bf) = hl - hr = { -1, 0, 1 }` (for balanced tree)
		- `|bf| = |hl-hr| <= 1` (for balanced tree)
		- we calculate balance factor for each node.
	- if the node is imbalance, we should perform rotations for balancing that one.
5. Rotations in AVL Tree
	- types of imbalance
		- `LL-imbalance` (Left of left imbalance) -> performs `LL-rotation`
		- `LR-imbalance` -> performs 2 steps rotation (`LR-rotation`)
			- we can do another single step rotation
				1. bring the last node to the first node (imbalance node)
				2. then bring the old imbalance node to the right of the new node (the node recently replaced with the last node)
		- `RR-imbalance` -> performs `RR-rotation`
		- `RL-imbalance` -> performs 2 steps rotation (`RL-rotation`)
	- balance factor > 1 -> means that it is heavy on the right side.
	- balance factor < -1 -> means that it is heavy on the left side.
6. How to create AVL Tree?
	- insert node -> check balance factor -> performs rotation
	- if multiple node becoming imbalance, which one of node do we should perform rotation?
		- perform rotation the first ancestor (starting from the new inserted node) which became imbalance after inseting a new node to the tree.
	- don't allow any node has balance factor exceed -2 or 2.

---