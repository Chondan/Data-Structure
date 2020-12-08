# Data Structure

## RECAP
- [x] Linked List ( Linkedlist -> head, Node -> value, next pointer )
	- Singly
		- Each node contain a pointer that point to the next node.
		- The pointer of the last node of the linkedlist point to NULL.
	- Doubly
		- Each node contains a pointer that point to the previous node and the next node.
		- The previous pointer of the head node of the linkedlist point to NULL.
	- Circular
		- The next pointer of the last node point to the head node of the linkedlist.
- [x] Stacks ( Stack -> top and Node -> value, next pointer (point from top to down))
	- Each node contains a pointer and value.
	- The next pointer of the base node (the bottom of the stack) point to NULL.
- [x] Queue ( Queue -> front and rear, Node -> value, next (point to the node behind) )
	- The next pointer of the last queue point to null.
- [x] Trees
- [ ] Heaps
- [ ] Graphs
- [ ] Hash Tables

---

- A data structure is a model where data is organized, managed and stored in a format that enables efficient access and modification of data.
- Different forms of data may require different types of data structures.
- A program built using improper data structures will be therefore inefficient or unnecessarily complex. It is neccessary to have a good knowledge of data structures and understand where to use the best one.

## Inbuilt Data Structure
Inbuild data structurs are provided by most programming languages. They may used to derive other data structures.
- Arrays -> Stores elements of the same type in a contiguous block of memory, can accessed by a common identifier.
- Structures -> Creates a data type that can be used to group items of different types into a single type.

## Abstract Data Type (ADT)
Abstract Data Types are defined by its behaviour from the point of view of the user of the data. 

It defines it in terms of:
- Possible values
- Operations on data
- The behaviour of these operations.

The difinition of ADT only mentions what operations are to be performed but not how these operations will be implemented. It does not specify how the data is being handled under the hood, this is known as **abstraction**.

Example of ADT:
- Linked Lists: Consists of nodes, where each node points to some other node forming a sequence.
- Stacks: The insdrtion and deletion operations are performed at only one end. It follows the LIFO principle.
- Queues: The insertion and deletion operations are performed at two different ends. It follows the FIFO principle.
- Trees: Hierarchical data structure where the information is represented in the form of a parent and children.
- Heaps: Specialized tree-based data structure that satisfies the heap property.
- Graphs: Consists of nodes and edges used to represent relations between pairs of objects.
- Hash Tables: Data is stored in an associative manner. A hash function is used to map the data to array positions.

---

### Linked List
- Operations
		- Inserting at the Beginning, Inserting at the End, Inserting at a specific position
		- Deleting at the Beginning, Deleting at the End, Deleting at a specific position
		- Show List, Get value at position, Get size

#### Advantage over an array
- Not Fixed in Size
- Efficient Insertion and Deletion: Insertion and deletion are efficient and take constant time as only the links are manipulated, not the actual memory location of the actual elements.

#### Disadvantage over an array
- Slightly more memory usage
- Sequential Access
- Difficult revers traversal: Difficulties arise in liked lists when it comes to revers traversing in a singly linked list. This can be resolved using doubly linked list, but this again increase memory as we have to store the previous reference pointer.

#### Uses of a Linked List
- **Implementation other data structure:** It is used to implement other data structures such as stacks, queues and non-linear ones like trees and graphs.
- **Hash Chaining:** It has used in hash chaining for the implementation in open chaining.

#### Types of Linked List
1. Singly Linked List 
	- A singly linked list is the simplest type of linked list in which every node contains some data and a pointer to the next node.
	- Allows traversal of data only in one way.
2. Doubly Linked List 
	- Every node has two pointers: next and previous. This allows for reverse traversal anywhere in the list.
3. Circular Linked List
	- Last node connect to the first node, forming a loop.
	- The last node contain a pointer to the first node of the list.
	- While traversing a circular linked list, we can begin at any node and traverse the list in any direction, forward or backward, until we reach the same node where we started.

---

### Stack
A stack is a linear data structure which stores its elements in particular order. This order followed by a stack is known as LIFO (Last in First Out).

An example of real life phenomena of stacks is of plates stacked over one another on a table. The plate which is at the top is the first one to be removed, it is not possible to remove the last plate unless the above plates have been removed, following the principle Last In First Out.

#### Examples in Programming
1. **UNDO functionality in text editors:** are based on a stack. Every change in the document is added to stack and upon an UNDO request, the last change is referred by popping it from the stack.
2. **Parentheses checker:** the ordered manner of the stack could be used for checking the proper closing of parentheses. Every opening parentheses is pushed on to the stack and for every correct closing parentheses, it is poped off. Irregularities can then be detected if they mismatch.
3. **Expression parsing:** using stacks can help evaluate expressions faster using postfix or prefix notation.

#### Properties
1. Follows LIFO (Last In First Out Order), the last element that is inserted is pushed out first.
2. A pointer keeps track of the stack's topmost (or last) element. This is manipulated on the basis of operations to be performed to know keep track of most recent element.

#### Stack Manipulation Operations
1. Push Operation: When an element is inserted into the stack, it is said that the element is pushed into the stack. The top pointer is moved up to point to the element that is inserted.
2. Pop Operation: When an element is removed from the stack, it is said that the element is popped from the stack. The top pointer is moved down to point to the element below the removed element.
3. Peek Operation: Peek is an operation that returns the value of the topmost element of the stack without deleting it from the stack.

---

### Queues
Queue is a linear data structure which unlike the stack is open at both ends. If follows the FIFO (First In First Out) principle, which means that the element that is inserted first is removed first.

#### Real Life Examples of Queus
1. An example of a queue is the queue we see everyday in our lives. People join a queue from the end and get out of the queue from the front, following the FIFO principle.
2. A queue is used in process scheduling in the Operating System. A series of precesses wait in a queue waiting to be executed when required resources are free.

#### Properties
1. Follows the FIFO (First In First Out Order), the first element that is inserted, is removed first.
2. Two pointers keep track of the front and rear ot the queue, whenever insertion or deletion takes place, these two pointers are updated accordingly to track the last and first element.
3. Insertion takes place from the rear and deletion from the front.

#### Types of Queues
Queues and their functions can be modified to have some additional advantages, some of the other types of queues are:
1. Double Ended Queus (Deque)
A deque is a list in which the elements can be inserted or deleted at either end. These are further of two types:
	1. Input Restricted Queue: Where insertion takes place only from the rear end, deletion can take place from both ends.
	2. Output Restricted Queue: Where deletion takes place from only the front, however insertion can take place from both ends.
2. Priority Queues
Priority queue is like a regular queue or stack data structure, but where additionally each element has a 'priority' associated with it. In a priority queue, an element with high priority is served before an element with low priority.

This can be helped in operations where priority is important for executing operations in a certain order.

3. Circular Queue (Circular Buffer)
Additional resources: https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/

A circular queue is a queue that uses a single, fixed-size buffer as if it were connected end-to-end.

Circular queue is a good implementation for a queue that has fixed maximum size, as their is no shifting involved and the whole queue can be used up for storing all the elements, which is not possible in an array implementation of linear queue.

Circular Queue is a linear data structure in which the operations are preformed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called **'Ring Buffer'**.

In a normal Queue, we can insert elements until queue becomes full. But once queue becomes full, we can not insert the next element even if there is a space in front of queue.

---

### Trees

#### Additional Resources
- https://www.gatevidyalay.com/tree-data-structure-tree-terminology/
- https://www.geeksforgeeks.org/extended-binary-tree/


A tree is widely used data structure that simulates a hierarchical tree structure, with a root value and the subtrees as children, represented as a set of linked nodes. The children of each node could be accessed by traversing the tree until te specific value is reached.

#### Advantages of trees
1. Trees (with some ordering e.b., BST) provide moderate access/search (quicker than a Linked List).
2. Trees provide moderate insertion/deletion (quicker that Arrays) speed.

#### Uses in programming
1. File System structure: directories and subdirectories of a file system can be efficiently be represented by trees.
2. DOM structure: HTML pages are rendered using a DOM structure which contains all the tags used in the page under a tree-like structure.
3. Router algorithms: use trees to figure out a path for the data to follow efficiently.

#### Terminology used in trees
- Root: The first node in a tree is called as Root Node. Every tree must have one Root Node.
- Parent Node: The node which is a predecessor of any node is called as Parent Node, that is, the node which has a branch from it to any other node is called as the Parent node.
- Child Node: The node which is descendant of any node is called as Child Node. Any parent node can have any number of child nodes. All the nodes except root are child nodes.
- Sibling: Nodes which belong to the same Parent are called as Siblings.
- Leaf Node: In a tree data structure, the node which does not have a child is called a Leaf Node. They are also known as External Nodes or Terminal Nodes.
- Internal Nodes
	- The node which has at least one child is called an Internal Node.
	- Internal nodes are also called as non-terminal nodes.
	- Every non-leaf node is an internal node.
- External Nodes: The node which has no child is called an External Node.
- Degree
	- Degree of a node is the total number of children of that node.
	- Degree of a tree is the highest degree of a node among all the nodes in the tree.
- Level
	- In a tree, each step from top to bottom is called as level of a tree.
	- The level count starts with 0 and increments by 1 at each level or step.
- Height
	- Total number of edges that lies on the longest path from any leaf node to a particular node is called as height of that node.
	- Height of a tree is the height of root node.
	- Height of all leaf nodes = 0.
- Depth
	- Total number of edges from root node to a particular node is called as depth of that node.
	- Depth of a tree is the total number of edges from root node to a leaf node in the longest path.
	- Depth of the root node = 0.
	- The terms "level" and "depth" are used interchaneably.
- Path: The sequence of Nodes and Edges from one node to another node is called as PATH between that two Nodes.
- Subtree
	- In a tree, each child from a node forms a subtree recursively.
	- Every child node forms a subtree on its parent node.
- Forest
	- A forest is a set of disjoint trees.

#### Types of trees
1. Binary Trees
	- In a normal tree, every node can have any number of children. A Binary tree is a special type of tree in which every node can have a maximum of 2 children. One is known as left child and the other as right child.
	- Binary Tree Representation
		- Array Representation: The binary tree is represented in a 1-Dimensional array.
		- Linked List Representation: A doubly linked list is used to represent a binary tree. Here, every node consists of 3 fields. First field for storing left child's address, second for storing data and third for storing right child's address.
	- Types of Binary Trees
		1. Strictly Binary Tree: A binary tree in which every node has either two or zero children is a Strictly Binary Tree.
		2. Complete Binary Tree: A binary tree in which every internal node has exactly two children and all leaf nodes are at same level is a Complete Binary Tree.
		3. Extended Binary Tree
			- The full binary tree obtained by adding dummy nodes to a binary tree is called as Extended Binary Tree.
			- Extended binary tree is a type of binary tree in which *all the null sub tree of the original tree* are replaced with special nodes called external nodes whereas other nodes are called internal nodes.
		4. Threaded Binary Tree
			- Threaded Binary Tree is also binary tree in which all left child pointers that are NULL points to its in-order predecessor, and all right child pointers that are NULL points to its in-order successor.
			- Inorder traversal of a Binary tree can either be done using recursion or with the use of a auxiliary stack. The idea of threaded binary trees is to make inorder traversal faster and do it without stack and without recursion. A binary tree is made threaded by making all right child pointers that would normally be NULL point to the inorder successor of the node (if it exists).
			- There are two types of threaded binary trees.
				1. Single Threaded: Where a NULL right pointers is made to point to the inorder successor (if successor exists)
				2. Double Threaded: Where both left and right NULL pointers are made to point to inorder predecessor and inorder successor respectively. The predecessor threads are useful for reverse inorder traversal and postorder traversal. 
			- The threads are also useful for fast accessing ancestors of a node.
2. Binary Search Trees
	- Terminologies:
		- Inorder successor
		- Inorder predecessor
	- Additional Resources:
		- https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
	- A Binary Search Tree is a binary tree that additionally satisfies the binary search property.
	- Binary Tree Property
		- This property state that the key in each node must be greater than or equal to any key stored in the left sub-tree, and less than or equal to any key stored in the right sub-tree.
	- Operations in Binary Search Tree
		- Searching
		- Insertion
		- Deletion 
3. Multiway Search Trees
	- A multiway tree can have more than one value per node. They are written as m-way trees where the m means the order of the tree. A multiway tree can have m-1 values per node and m children (m ways). Although, not every node needs to have m-1 values or m children.
4. AVL Trees
	- An AVL tree is a self-balancing binary search tree. A binary tree is said to be balanced, if the difference between the heights of left and right subtrees of every node in the tree is either -1, 0, or +1. This is known as the Balance Factor.
	- Balance Factor
		- Balance Factor = height(left_subtree) - height(right_subtree)
	- Rebalancing
		- During a modifying operation (e.g. insert, delete), if the height difference of more than 1 arises between two subtrees, the parent subtree has to be 'rebalanced' to satisfy the AVL property.
		- These are done by tree rotations, which moves the keys in such a manner that there order is preserved, but the balance factor is also satisfied.
	- AVL Tree Rotations
		- Rotation is the process of moving the nodes to either left or right to make tree balanced. There are 4 types of rotations:
			1. Single Left Rotation (LL Rotation)
			2. Single Right Rotation (RR Rotation)
			3. Left Right Rotation (LR Rotation)
			4. Right Left Rotation (RL Rotation)

#### Binary Tree Traversals
A binary tree is traversed when one needs to access or display its elements. Each method produces a different order of elements that may be useful in scenarios when needed.

- Traversal Methods
	1. Inorder [Left - Root - Right]
		- In this traversal, the left child node is visited first, then the root node is visited and later we go for visiting right child node.
	2. Preorder [Root - Left - Right]
		- In this traversal, the root node is visited first, then its left child and later its right child.
	3. Postorder [Left - Right - Root]
		- In this traversal, left child node is visited first, then its right child and then its root node.

---