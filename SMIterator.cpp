#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <assert.h>
#include <stdexcept>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){ //default

    index = 0;;

}

void SMIterator::first(){ //default

    index = 0; //for first elem in array

}

void SMIterator::next(){ //default

    if (!valid()) {
        throw out_of_range("Iterator out of range");
    }
    index++;

    if (index >= map.size()) {
        index = map.size();
    }

    // if (index < map.sizeOf) {
    //     index = index + 1;
    // }
    // else {
    //     throw std::out_of_range("Iterator is out of range"); //exception if out of range
    //     //index = map.sizeOf; //invalid if?????
    // }
}

bool SMIterator::valid() const{ //default

    if ((index < map.sizeOf) && (index >= 0)) { //TODO
        return true;

    }
    return false;
}

TElem SMIterator::getCurrent() const{ //default

    if (valid()) {
        return map.array[index];
    }
    throw std::out_of_range("Not valid");
    //return NULL_TPAIR;
}


