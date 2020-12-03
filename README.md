# Data Structure

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
A circular queue is a queue that uses a single, fixed-size buffer as if it were connected end-to-end.

Circular queue is a good implementation for a queue that has fixed maximum size, as their is no shifting involved and the whole queue can be used up for storing all the elements, which is not possible in an array implementation of linear queue.