#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <assert.h>
#include <stdexcept>
#include <iostream>

using namespace std;

SMIterator::SMIterator(const SortedMap &m) : map(m) { //theta(1)
    //default

    index = 0;
}

void SMIterator::first() { //theta(1)
    //default

    index = 0; //for first elem in array
}

void SMIterator::next() { //theta(1)
    //default

    if (!valid()) {
        throw out_of_range("Iterator out of range");
    }
    index++;
}

bool SMIterator::valid() const { //theta(1)
    //default

    if (index >= 0 && index < map.size()) {
        return true;
    }
    return false;
}

TElem SMIterator::getCurrent() const { //theta(1)
    //default

    if (valid()) {
        return map.array[index];
    }
    throw out_of_range("Iterator out of range");
}
