#include <iostream>
#include <string>
using namespace std;

/*******************************************
Declaration of Node class
*******************************************/
template<class K, class V>
class Node{
 public:
	// pre-condition:   A valid key and/or value will be passed
	// post-condition:  A node with these values stored will be created
 	Node(K,V); //constructor
	K name_=0;		//variable to store the name of the person
	V data_=0;		//variable to store the number of the person
	Node<K,V>* left = nullptr;	//pointer to the left child of the person
	Node<K,V>* right = nullptr;	//pointer to the right child of the person
};

/*******************************************
Declaration of Map class
*******************************************/
template<class K, class V>
class Map {
  public:
    // pre-condition:   a valid key/value pair
    // post-condition:  pair will be added to the BST, if not already present
    //                  Return true if insert succeeded, else false
    virtual bool insert(const K& key, const V value) = 0;

    // pre-condition:   a valid key
    // post-condition:  if key was present, key/value pair is removed
    //                  Return true if remove succeeded, else false
    virtual bool remove(const K key) = 0;

    // pre-condition:   a valid key
    // post-condition:  return the corresponding value for key, else nullptr
    //                  the BST is not changed
    virtual V* search(const K key) = 0;

    // pre-condition:   a valid BST
    // post-condition:  return whether or not BST contains any items
    //                  the BST is not changed
    virtual bool isEmpty()  = 0;

    // pre-condition:   a valid BST
    // post-condition:  prints contents of BST in sorted order
    //                  the BST is not changed
    virtual void print()  = 0;
	Map(){}
};

/*******************************************
Declaration of BSTMap class
*******************************************/
template<class K, class V>
class BSTMap : public Map<K,V> {
  public:
	BSTMap(){}
	Node<K,V>* root=nullptr;	// pointer to the root of the tree/BSTMap
	Node<K,V>* temp=nullptr;	// temp,prev,hold,temp2 are multi use pointers used in implementation of methods
	Node<K,V>* prev=nullptr;
	Node<K,V>* hold=nullptr;
	Node<K,V>* temp2=nullptr;
	// pre-condition:   a valid key/value pair
	// post-condition:  pair will be added to the BST, if not already present
	//                  Return true if insert succeeded, else false
	bool insert(const K& key, const V value) override;

	// pre-condition:   a valid key
    	// post-condition:  if key was present, key/value pair is removed
    	//                  Return true if remove succeeded, else false
	bool remove(const K key) override;

	// pre-condition:   a valid key
    	// post-condition:  return the corresponding value for key, else nullptr
    	//                  the BST is not changed
	V* search(const K key) override;

	// pre-condition:   a valid BST
	// post-condition:  return whether or not BST contains any items
	//                  the BST is not changed
	bool isEmpty() override;

	// pre-condition:   a valid BST
	// post-condition:  prints contents of BST in sorted order
	//                  the BST is not changed
	void print() override;  
  
	// pre-condition:   A valid node is passed
	// post-condition:  method will traverse through the Map in order
	void inorder(Node<K,V>* other);
};



