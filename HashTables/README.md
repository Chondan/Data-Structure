# Hash Tables

## Keywords
- birthday problem
	- In probability theory, the **birthday problem** or **birthday paradox** concerns the probability that, in a set of n randomly chosen people, some pair of them will have the same birthday. By the pigeonhole principle, the probability reaches 100% when the number of people reaches 367 (since there are only 366 possible birthdays, including February 29). 
- bit masking
- universal hash function
- dynamic array
- cpu caching
- translation lookaside buffer (TLB)

## Introduction
- a data structure that implements an associative array abstract data type, a structure that can map keys to values.
- a hash table uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found.
- Ideally, the hash function will assign each key to a unqiue bucket, but most hash table desings employ an imperfect hash function, which might cause hash *collisions* where the hash function generates the same index for more than one key. 
- Many hash table desings also allow arbirary insertions and deletions of key-value pairs, at *amortized* constant average cost per operation.

## Hashing
- The idea of hashing is to distribute the entries (key/value pairs) across an array of buckets. Given a key, the algorithm computes an index that suggest where the entry can be found.

## Choosing a hash function
- A basic requirement is that the function should provide a uniform distribution of hash values. A non-uniform distribution increase the number of collistions and the cost of resolving them.
- Some hashing algoritms prefer to have the size be a *prime number*.
	- additional resoureces: https://cs.stackexchange.com/questions/11029/why-is-it-best-to-use-a-prime-number-as-a-mod-in-a-hashing-function
	- Every key in K that shares a common factor with the number of buckets m will be hashed to a bucket that is a multiple of this factor.
	- Therefore, to minimize collisions, it is important to reduce the number of common factors between m and the elements of K. How can this be achieved? By choosing m to be a number that has very few factors: a **prime number**.
- For open addressing schemas, the hash function should also avoid clustering, the mapping of two or more keys to consecutive slots. Such clustering may cause the lookup cost to skyrocket, even if the load factor is low and collisions are infrequent. The poplular multiplicative hash is claimed to have particulary poor clustering behavior.
- Crytographic hash function are believed to provide a good hash functions for any table size, either by modulo reduction or by bit masking. They may also be appropriate if there is a risk of malicious users trying to sabotage a network service by submitting requests designed to generate a large number of collisions in the server's hash tables. However, the risk of sabotage can also be avoided by cheaper methods (such as applying a secret salt to the data, or using a universal hash function). A drawback of cryptographic hashing functions is that they are often slower to compute, which means that in case where the uniformity for any size is not necessary, a non-crytographic hashing function might be preferable.

## Perfect hash function
- If all keys are known ahead of time, a perfect hash function can be used to create a perfect hash table that has no collisions. Perfect hashing allows for constant time lookups in all cases. This is in contrast to most chaining and open addressing methods, where the time for lookup is low on average, but may be very large, O(n), for instance when all the keys hash to a few values.

## Key statistics
- A critical statistic for a hash table is the *load factor*, defined as `load factor = n / k` where n is the number of entries occupied (number of elements stored in the table) in the hash table, k is the number of buckets.
- As the load factor grows larger, the hash table becomes slower, and it may even fail to work (depending on he method used). The expected constant time property of a hash table assumes that the load factor be kept below some bound. For a fixed number of buckets, the time for a lookup grows with the number of entries, and therefor the desired constant time is not achieved. In some implementations, the solution is to automatically grow (usually, double) the size of the table when the load factor bound is reached, thus forcing to re-hash all entries. 
- As a real-world example, the default load factor for a HashMap in Java is 0.75, which "offers a good trades-off between time and space costs."
- Second to the load factor, one can examine the variance of number of entries per bucket. For example, two tables both have 1,000 entries and 1,000 buckets; one has exactly one entry in each bucket, the other has all entries in the same bucket. Cleary the hashing is not working in the second one.

## Collision resolution
- Hash collisions are practically unavoidable when hashing a random subset of a large set of possible keys. For example, if 2,450 keys are hashed into a million buckets, even with a perfectly uniform random distribution, according to the *birthday problem* there is approximately a 95% chance of at least two of the keys being hashed to the same slot.

1. Seperate chaining
- In the method known as separate chaining, each bucket is independent, and has some sort of list of entries with the same index. The time for hash table operations is the time to find the bucket (which is constant) plus the time for the list operation.

### Separate chaining with linked lists
- Chained hash tables with linked lists are popular because they require only basic data structures with simple algorithms, and can use simple hash functions that are unsuitable for other methods.
- The cost of a table operation is that of scanning the entries of the selected bucket for the desired key. If the distribution of keys is sufficiently uniform, the average cost of a lookup proportional to the load factor.
- For this reason, chained hash tables remain effective even when the number of table entries n is much higher that the number of slots. For example, a chained hash table with 1,000 slots and 10,000 stored keys (load factor 10) is five to ten times slower than a 10,000-slot table (load factor); but still 1000 times faster than a plain sequential list.
- For separate-chining, the worst-case scenario is when all entries are inserted into the same bucket, in which case the hash table is ineffective and the cost is that of searching the bucket data structure. If the latter is a linear list, the lookup procedure may have to scan all its entries, so the worst-case cost is propotional to the number n of entries in the table.
- The bucket chains are often searched sequentially using the order the entries were added to the bucket. If the load factor is large and some keys are more likely to come up than others, then rearranging the chain with a move-to-front heuristic may be effective. More sophisticated data structures, such as balanced search trees, are worth considering only if the load factor is large (about 10 or more), or if the hash distribution is likely to be very non-uniform, or if one must guarantee good performance even in a worst-case scenario. However, using a larger table and/or a better hash function may be even more effective in those cases.
- Chained hash tables also inherit the disadvantages of linked lists. When storing small keys and value, the space overhead of the `next` pointer in each entry record can be significant. An additional disadvantage is that traversing a linked list has poor cache performance, making the processor cache ineffective.

### Separate chaining with list head cells
- implementations store the first record of each chain in the slot array itself. The number of pointer traversals is decreased by one for most cases. The purpose is to increase cache efficiency of hash table access.

### Separate chaining with other structures
- Instead of a list, one can use any other data structure that supports the required operations. For example, by using a self-balancin binary search tree, the theoretical worst-case time of common hash table operations (insertion, deletion, lookup) can be brought down to O(log(n)) rather than O(n). However, this introduces extra complexity into the implementation, and may cause even worse performance for smalled hash tables, where the time spent inserting into and balancing the tree is greater that the time needed to perform a linear search on all of the elements of a list. 
- A real world example of a hash table that uses a self-balancing binary search tree for buckets is the `HashMap` class in Java version 8.
- The variant called array hash table uses a dynamic array to store all the entries that hash to the same slot. Each newly inserted entry gets appended to the end of the dynamic array that is assigned to the slot. The dynamic array is resized in an exact-fit manneer, meaning it is grown only by as many bytes as needed. Alternative techniques such as growing the array by block sizes or pages were found to improve insertion performance, but at a cost in space. This variation makes more efficient use of CPU caching and the translation lookaside buffer (TLB), because slot entries are stored in sequential memory positions. It also dispenses with the `next` pointers that are required by linked lists, which saves space. 

### Open addressing
- In another strategy, called open addressing, all entry records are stored in the bucket array itself. When a new entry has to be inserted, the buckets are examined, starting with the hashed-to slot and proceeding in some probe sequence, until an unoccupied slot is found. When searching for an entry, the buckets are scanned in the same sequence, until either the target record is found, or an unused array slot is found, which indicates that there is no such key in the table.
- The name "open addressing" refers to the fact that the location ("address") of the items is not determined by its hash value. (This method is also called **closed hashing**; it should not be confused iwth "oepn hashing" or "closed addressing" that usually mean separate chaining.)
- Well-known probe sequences include:
	- *Linear probing*, in which the interval between probes is fixed (usually 1). Because of good CPU cache utilization and high performance this algorithm is most widely used on modern computer architectures in hash table implementations.
	- *Quadratic probing*, in which the interval between probes is increased by adding the successive outputs of a quadratic polynomial to the starting value given by the original hash computation.
	- *Double hashing*, in which the interval between probes is computed by a second hash function.

---

# Hashing Techniques - Simplified

## Hashing
- key sapce
- Hahs Table

> hash function is the function that maps a key sapce into the hash table.

