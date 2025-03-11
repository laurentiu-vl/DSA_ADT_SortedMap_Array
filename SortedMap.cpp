#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;

SortedMap::SortedMap(Relation r) {
	//TODO - Implementation

	capacity = 2;
	array = new TElem[capacity];
	ascending = r;
	sizeOf = 0;

}

TValue SortedMap::add(TKey k, TValue v) {
	//TODO - Implementation

	if (sizeOf == capacity) { //resize if condition corect?

		resize();

	}

	if (sizeOf == 0) { //add the first TElem element
		array[0] = TElem(k, v);
		sizeOf++;

		return NULL_TVALUE;
	}

	/*if (sizeOf == 1) {
		if (ascending) {
			if (k < array[0].first) {
				array[1] = arr
			}
		}
	}*/

	for (int i = 0; i < sizeOf; i++) {
		if (array[i].first == k) {

			TValue temp_value = array[i].second;
			array[i].second = v; //if key already exists -> return old value (of the same key TKEy)

			return temp_value;
		}
	}

	for (int i = sizeOf; i >= 0; i--) {

		if (ascending) {
			if (k < array[i - 1].first) {

				array[i + 1] = array[i];

			}
			else {
				array[i] = TElem(k, v);
				sizeOf++;
				break;
			}


		}

		else {
			if (k > array[i - 1].first) {

				array[i + 1] = array[i];
			}
			else {
				array[i] = TElem(k, v);
				sizeOf++;
				break;
			}

		}

	}

	return NULL_TVALUE;
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

	TElem *temp = new TElem[capacity];
	capacity *= 2;

	for (int i = 0; i < sizeOf; i++) {
		temp[i] = array[i];
	}

	delete[] array;
	array = temp;
	//resize

}

