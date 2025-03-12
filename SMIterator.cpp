#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <assert.h>
#include <stdexcept>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){ //default
    //TODO - Implementation

    index = 0;;

}

void SMIterator::first(){ //default
    //TODO - Implementation

    index = 0; //for first elem in array
}

void SMIterator::next(){ //default
    //TODO - Implementation

    // if (index == 99) {
    //     int i = 5;
    //     int j=i;
    // }

    if (index + 1 < map.sizeOf) {
        index = index + 1;
    }
    else {
        //throw std::out_of_range("Iterator is out of range"); //exception if out of range
        index = map.sizeOf; //invalid if?????
    }
}

bool SMIterator::valid() const{ //default
    //TODO - Implementation

    // if (map.sizeOf == 0) {
    //     return false;
    // }

    if ((index < map.sizeOf) && (index >= 0)) { //TODO
        return true;

    }
    return false;

    //return false;
}

TElem SMIterator::getCurrent() const{ //default
    //TODO - Implementation

    if (valid()) {
        return map.array[index];
    }
    else {
        throw std::out_of_range("Not valid");
        //return NULL_TPAIR;
    }

    //return NULL_TPAIR;
}


