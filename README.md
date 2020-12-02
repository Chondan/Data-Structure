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

### Linked List

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
	- Operations
		- Inserting at the Beginning, Inserting at the End, Inserting at a specific position
		- Deleting at the Beginning, Deleting at the End, Deleting at a specific position
		- Show List, Get value at position, Get size
2. Doubly Linked List 
	- Every node has two pointers: next and previous. This allows for reverse traversal anywhere in the list.
	
