#include <vector>

#include "PriorityQueue.h"

template<class K, class V>
class HeapPriorityQueue : public PriorityQueue<K,V>
{
  public:
    HeapPriorityQueue() =default;
    ~HeapPriorityQueue() = default;

    	// Adds the key/value pair to the internal heap
	//pre-condition: a valid heap was already created
	//post-condition: element will be added in the correct position, heap will still be valid
    	void enqueue(const K& key, const V& value) override;

    	// Removes the best key from the heap and returns associated value
	//pre-condition: a valid heap and contains an element
	//post-condition: the max value in the heap will be returned
    	V dequeue() override;

    	// Test for empty
	//pre-condition: a valid heap was already created
	//post-condition: return true if the heap contains nothing and false if it does
   	 bool isEmpty() const override;

    	// Prints contents of queue (key/value pairs) using level-order traversal
	//pre-condition: a valid heap exists
	//post-condition: the elements of the heap will be printed in order
    	void print() const override;

    	// Auxiliary methods to re-heapify the heap
	//pre-condition: a valid integer must be passed, a valid heap exists
	//post-condition: heap property is preserved from the start node to the root
    	void trickleUp(int i);
	//pre-condition: a valid integer must be passed, a valid heap exists
	//post-condition: heap property is preserved from the start node to the leaves
    	void trickleDown(int i);

    	// The contents of the priority queue (a key/value pair)
    	// 'key' is used for priority, 'value' is the relevant data
   	 struct PQEntry{
   	  K key;
    	  V value;
  	  PQEntry(const K& k, const V& v) : key(k), value(v) { }
  	 };
	
    	// We use a vector so we don't have to worry about running
    	// out of space
    	std::vector<PQEntry> heap;
	
	int size_=0;
};

