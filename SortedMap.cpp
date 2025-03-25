#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;

SortedMap::SortedMap(Relation r) {
    //theta(1)
    capacity = 2;
    array = new TElem[capacity];
    sizeOf = 0;
    compare = r;
}

TValue SortedMap::add(TKey k, TValue v) {
    //O(sizeOf)
    for (int i = 0; i < sizeOf; i++) {
        //if key k already exists in array, return TValue oldValue
        if (array[i].first == k) {
            TValue oldValue = array[i].second; //save the old value of the value of the k array[i].first for return
            array[i].second = v; //save the new value v to the key
            return oldValue; //return the old value of the k
        }
    }

    if (sizeOf == 0) {
        //sortedmap is empty
        array[0] = TElem(k, v);
        sizeOf = 1;
        return NULL_TVALUE;
    }

    if (sizeOf == 1) {
        //size of sm is 1
        if (array[0].first == k) {
            //if the key in array is the same with k as paramater from add
            TValue oldValue = array[0].second;
            array[0] = TElem(k, v);
            return oldValue;
        }
        if (compare(k, array[0].first)) {
            array[1] = array[0]; //if args should be in ascending order -> add k first, arr[] second
            array[0] = TElem(k, v);
            sizeOf += 1;
        } else {
            //if k > arr -> place k second in arr
            array[1] = TElem(k, v);
            sizeOf += 1;
        }
        return NULL_TVALUE;
    }

    if (sizeOf == capacity) {
        resizeUp(); //resize
    }

    int index = sizeOf;
    while (index > 0 && compare(k, array[index - 1].first)) {
        //general case
        array[index] = array[index - 1];
        index--;
    }
    array[index] = TElem(k, v);
    sizeOf++;

    return NULL_TVALUE;
}

TValue SortedMap::search(TKey k) const {
    //O(sizeOf)
    for (int i = 0; i < sizeOf; i++) {
        if (array[i].first == k) {
            return array[i].second;
        }
    }
    return NULL_TVALUE;
}

TValue SortedMap::remove(TKey k) {
    //O(sizeOf)
    if (sizeOf == 0) {
        return NULL_TVALUE;
    }

    if (sizeOf == 1 && array[0].first == k) {
        //TValue oldValue = array[0].second;
        //array[0] = NULL_TPAIR;
        sizeOf = 0;
        return array[0].second; //return TValue value of the key is found
    }

    bool found = false;
    int indexKeyFoundToBeRemoved = 0;
    TValue oldValue = NULL_TVALUE;
    for (int i = 0; i < sizeOf; i++) {
        if (array[i].first == k) {
            //check if the key is found in array
            found = true; //key found
            oldValue = array[i].second;
            indexKeyFoundToBeRemoved = i;
            break;
        }
    }

    if (found) {
        for (int i = indexKeyFoundToBeRemoved; i < sizeOf; i++) {
            //shift the element from the index of the key removed
            array[i] = array[i + 1];
        }
        sizeOf--;
        if (sizeOf <= capacity / 4) {
            resizeDown(); //resize down
        }
        return oldValue; //return TValue oldValue of the deleted key
    }
    return NULL_TVALUE;
}

int SortedMap::size() const {
    //theta(1)
    return sizeOf;
}

bool SortedMap::isEmpty() const {
    //theta(1)
    if (sizeOf == 0) {
        return true;
    }
    return false;
}

SMIterator SortedMap::iterator() const {
    //theta(1)
    return SMIterator(*this);
}

SortedMap::~SortedMap() {
    delete[] array;
}

void SortedMap::resizeUp() {
    //theta(sizeOf)
    capacity *= 2;
    TElem *temp = new TElem[capacity];

    for (int i = 0; i < sizeOf; i++) {
        temp[i] = array[i];
    }

    delete[] array;
    array = temp;
}

void SortedMap::resizeDown() {
    //theta(sizeOf)
    capacity /= 2;
    TElem *temp = new TElem[capacity];

    for (int i = 0; i < sizeOf; i++) {
        temp[i] = array[i];
    }

    delete[] array;
    array = temp;
}
