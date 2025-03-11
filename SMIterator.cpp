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

    if (index == 99) {
        int i = 5;
        int j=i;
    }

    if (index + 1 < map.sizeOf) {
        index = index + 1;
    }
    else {
        throw std::out_of_range("Iterator is out of range"); //exception if out of range
    }
}

bool SMIterator::valid() const{ //default
    //TODO - Implementation

    if (index < map.sizeOf) {
        return true;

    }
    else {
        return false;
    }

    //return false;
}

TElem SMIterator::getCurrent() const{ //default
    //TODO - Implementation

    if (valid()) {
        return map.array[index];
    }
    else {
        throw std::out_of_range("Not valid");
    }

    //return NULL_TPAIR;
}


