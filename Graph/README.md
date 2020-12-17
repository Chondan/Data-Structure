# Graph Traversals - BFS & DFS-Breadth First Search and Depth First Search 

## Terms
1. Visiting a vertex
2. Exploration of vertex -> visit all adjacent vertices of particular vertex\
3. BFS Spanning Tree
4. DFS Spanning TRee
5. back edges

A graph is also a tree:
- BFS is like a 'Level-order' traversal in a tree.
- DFS is like a 'pre-order' traversal in a tree.

## Breadth First Search (BFS)
- You can start 'BFS' from any vertex you like.
- When you explored any vertex then you can visit an adjacent vertex in any order you like.
- Rules
	1. When you are selected a vertex for exploration you must visit all of it adjacent vertices then only you should go to next vertex for exploration.
	2. You must select the next vertex for exploration from 'Queue' only, so 'Queue' and exploration should be completely done.

## Depth Frist Search
- Depth First Traversal (or Search) for a graph is similar to Depth First Traversal of a tree. The onlyh catch here is, unlike trees, graphs may contain cycles, a node may be visited twice. To avoid processing a node more than once, use a boolean visited array.
- A stack is a data structure used here.
- You can start 'DFS' from any vertex you like.
- Rules
	1. Once you have reached a new vertex, start exploring that new vertex.
	2. Suspend the remaining vertex (unsuccessful exploration) by adding to the 'Stack' for coming back to exploration.