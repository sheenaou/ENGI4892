#ifndef __HASH_WITH_QUADRATIC_
#define __HASH_WITH_QUADRATIC_

#include "HashTable.hxx"

/**
 * This class uses open-addressing, specifically quadratic probing to
 * resolve collisions.
 */

template<class K, class V>
class HashWithQuadratic : public HashTable<K,V>{
public:
	HashWithQuadratic<K,V>(std::function<int(K)> hc)
		: hashcode(hc), size(0) 
	{
		int temp=0;
		for (int i=0;i<capacity;i++){
			data[i]= nullptr;
			temp++;
		}
	};
    // Add key/value pair to the hashtable by using 'key' to determine
    // the index for initial placement.
    // pre-condition:  a valid hashtable
    // post-condition: 'value' is added at position determined by 'key'
	bool insert(const K& key, const V& value) override{
		int code=hashcode(key)%capacity;
		int upper=0;
		int lower=0;
		if( data[code]==nullptr){
			data[code]=new HTEntry(key,value);
			size++;
			keyCheck++;
			return true;
		}
		else if (data[code] != nullptr) {
			for (int i=1; i<capacity ; i++){
				upper=code+(i*i);	
				lower=code-(i*i);
				if( upper > capacity){	//if the value is greater than the capacity
					upper=upper-capacity;	//go to the end then start back at the beginning
				}
				else if (lower<0){	
					lower=capacity+lower;	//if you reach the beginning start back at the end
				}
				if( data[upper] == nullptr){	//if the +i position is empty put the value here
					data[upper]=new HTEntry(key,value);
					size++;
					keyCheck++;
					return true;
				}
				else if( data[upper] != nullptr){
					keyCheck++;
				}
				else if (data[lower]==nullptr)	{		//if the position is empty, put the value here
					data[lower]= new HTEntry(key,value); 
					size++;
					keyCheck++;
					return true;
				}		//if it wasn't empty, increment i and try again
				else if (data[lower]!=nullptr){
					keyCheck++;
				}
			}
		}
	return false;
	}

    // pre-condition:  a valid hashtable
    // post-condition: the value associated with 'key', else nullptr
	const V* find(const K& key) override{
		int code=hashcode(key)%capacity;
		int upper=0;
		int lower=0;
		
		if ( key == data[code]->key){
			return &data[code]->value;
		}
		else if ( key != data[code]->key){
			for (int i=1 ; i<capacity ; i++){
				upper=code+(i*i);	
				lower=code-(i*i);
				if( upper > capacity){	//if the value is greater than the capacity
					upper=upper-capacity;	//go to the end then start back at the beginning
				}
				else if (lower<0){	
					lower=capacity+lower;	//if you reach the beginning start back at the end
				}
				if ( data[upper] != nullptr ){
					keyCheck++;
					if (key == data[upper]->key)
						return &data[upper]->value;
				}
				else if ( data[upper] == nullptr ){
					keyCheck++;
					return nullptr;
				}
				else if ( data[lower] != nullptr ){
					keyCheck++;
					if (key == data[lower]->key)
						return &data[lower]->value;
				}
				else if (data[lower] == nullptr){
					keyCheck++;
					return nullptr;
				}
			}
		}
	}

    // pre-condition:  a valid hashtable
    // post-condition: return the load factor; hashtable is not modified
	float loadFactor() const override{
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
		for( int i=0 ; i<capacity ; i++){
			if (data[i] != nullptr)
				cout<<"Table["<<i<<"]: key="<<data[i]->key<<"  value="<<data[i]->value<<endl;
			else if ( data[i] == nullptr)
				cout<<"Table["<<i<<"]:"<<endl;
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

    // An array of type 'HTEntry' pointers (nullptr indicates that the
    // position is empty)
    	HTEntry* data[capacity];
    	int size;
	int keyCheck=0;
};

#endif
