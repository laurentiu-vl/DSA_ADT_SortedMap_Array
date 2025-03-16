#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;

SortedMap::SortedMap(Relation r) {
	//TODO - Implementation

	capacity = 2;
	array = new TElem[capacity];
	sizeOf = 0;
	compare = r;

}

TValue SortedMap::add(TKey k, TValue v) {

	for ( int i = 0; i < sizeOf; i++) {
			if  (array[i].first == k) {
				TValue oldValue = array[i].second; //save the old value of the value of the k array[i].first for return
				array[i].second = v; //save the new value v to the key
				return oldValue; //return the old value of the k
			}
	}

	if (sizeOf == capacity) {
		resize();
	}







	// OLD ADD BEFORE RELATION ADDED IN CONSTRUCTOR
	// if (sizeOf == capacity) { //resize if condition corect?
	//
	// 	resize();
	//
	// }
	//
	// if (sizeOf == 0) { //add the first TElem element
	// 	array[0] = TElem(k, v);
	// 	sizeOf++;
	//
	// 	return NULL_TVALUE;
	// }
	//
	// for (int i = 0; i < sizeOf; i++) {
	// 	if (array[i].first == k) {
	//
	// 		TValue temp_value = array[i].second;
	// 		array[i].second = v; //if key already exists -> return old value (of the same key TKEy)
	//
	// 		return temp_value;
	// 	}
	// }
	//
	// for (int i = sizeOf; i >= 0; i--) {
	//
	// 	if (ascending) { //if Relation(a, b) trebuie modificat
	// 		if (k < array[i - 1].first) {
	//
	// 			array[i] = array[i - 1];
	//
	// 		}
	// 		else {
	// 			array[i] = TElem(k, v);
	// 			sizeOf++;
	// 			break;
	// 		}
	// 	}
	// 	else {
	// 		if (k > array[i - 1].first) {
	//
	// 			array[i] = array[i - 1];
	// 		}
	// 		else {
	// 			array[i] = TElem(k, v);
	// 			sizeOf++;
	// 			break;
	// 		}
	// 	}
	// }
	// return NULL_TVALUE;
}

TValue SortedMap::search(TKey k) const {
	//TODO - Implementation

	for (int i = 0; i < sizeOf; i++) {
		if (array[i].first == k) {
			return array[i].second;
		}
	}
	return NULL_TVALUE;
}

TValue SortedMap::remove(TKey k) {
	//TODO - Implementation

	if (sizeOf == 0) {
		return NULL_TVALUE;
	}

	if (sizeOf == 1) {
		TValue temp_value = array[0].second;
		array[0] = NULL_TPAIR;
		sizeOf--;

		return temp_value;
	}

	bool controlFound = false;
	for (int i = 0; i < sizeOf; i++) {
		if (array[i].second == k) {
			TValue temp_value = array[i].second;
			int controlFound = true;

			sizeOf--;
			for (int j = i; j < sizeOf; j++) {
				array[j] = array[j + 1];
			}
			return temp_value;
			break;
		}
	}
	if (controlFound == false) {
		return NULL_TVALUE;
	}

	//return NULL_TVALUE;
}

int SortedMap::size() const {
	//TODO - Implementation

	return sizeOf;

	//return 0;
}

bool SortedMap::isEmpty() const {
	//TODO - Implementation

	if (sizeOf == 0) {
		return true;
	}
	else {
		return false;
	}

	//return false;
}

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

SortedMap::~SortedMap() {
	//TODO - Implementation

	delete[] array;

}

void SortedMap::resize() {

	capacity *= 2;
	TElem *temp = new TElem[capacity];

	for (int i = 0; i < sizeOf; i++) {
		temp[i] = array[i];
	}

	array = temp;
	//resize

}

