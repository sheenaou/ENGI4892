#ifndef __HASH_WITH_CHAINING_
#define __HASH_WITH_CHAINING_

#include <vector>
#include "HashTable.hxx"
#include <iostream>

using namespace std;


/**
 * This class uses separate chaining as described in class, but instead
 * of using linked lists, it uses vectors.
 * The idea and complexity is the same, but you're probably more accustomed
 * to using vectors vs. linked lists.
 */

template<class K, class V>
class HashWithChaining : public HashTable<K,V>
{
  public:
    // c'tor (initializes hashcode lambda function and size)
    HashWithChaining(std::function<int(K)> hc) : hashcode(hc), size(0) { 
	}

    // Add key/value pair to the hashtable by using 'key' to determine
    // the index for initial placement.
    // pre-condition:  a valid hashtable
    // post-condition: 'value' is added at position determined by 'key'
    bool insert(const K& key, const V& value) override{
   	int code=hashcode(key)%capacity;
	data[code].push_back( HTEntry(key,value) ); 
	size++;
	keyCheck++;
	return true;
    }

    // pre-condition:  a valid hashtable
    // post-condition: the value associated with 'key', else nullptr
    const V* find(const K& key) override {
    	int code=hashcode(key)%capacity;
	if( data[code].empty() == true ){
		keyCheck++;
		return nullptr;
	}
	else if( data[code].empty() == false ){
		for( int i=0 ; i < data[code].size() ; i++){
			if ( key == data[code].at(i).key){
				keyCheck++;
				return & (data[code].at(i).value);
			}
			else
				keyCheck++;
		}	
	}
	return nullptr;
    }

    // pre-condition:  a valid hashtable
    // post-condition: return the load factor; hashtable is not modified
    float loadFactor() const override {	
	return (float)size/capacity;
    }

    // pre-condition:  a valid hashtable
    // post-condition: return total keys examined so far;
    //                 hashtable is not modified
    int totalKeysExamined() const override{
	return keyCheck;
    }

    // pre-condition:  a valid hashtable
    // post-condition: hashtable is not modified
    void print() const override{
	for(int i=0 ; i<capacity ; i++){
		cout<< "table["<<i<<"]:";
		if ( data[i].empty() != true){
			for (int j=0; j<(data[i].size()) ; j++){		
				cout<<" key="<<data[i].at(j).key<<"  value="<<data[i].at(j).value<<"     ";
			}
			cout<<endl;		
		}	
		else if (data[i].empty() == true){
				cout<<endl;
		}
	}
    }

  private:
    static constexpr int capacity = 211;
    std::function<int(K)> hashcode;

    // Contains key/value pairs for the hashtable
    struct HTEntry {
      K key;
      V value;

      HTEntry(const K& k = K(), const V& v = V()) : key(k), value(v) { }
    };

    // A bucket array of vectors (each vector contains type 'HTEntry')
    vector<HTEntry> data[capacity];
    int size;
    int keyCheck=0;
};

#endif
