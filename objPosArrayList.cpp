#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.

objPosArrayList::objPosArrayList() 
{
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;
    aList = new objPos[sizeArray];
}

objPosArrayList::~objPosArrayList() 
{
    delete[] aList;
}

int objPosArrayList::getSize() 
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos) 
{
    if (sizeList < sizeArray) {
        for (int i = sizeList; i > 0; --i) { // element shift for head
            aList[i] = aList[i - 1];
        }
        aList[0] = thisPos;
        ++sizeList;
    }
    // case where the array is full, and resizing is needed
}

void objPosArrayList::insertTail(objPos thisPos) 
{
    if (sizeList < sizeArray) {
        aList[sizeList] = thisPos;
        ++sizeList;
    }
    // case where the array is full, and resizing is needed
}

void objPosArrayList::removeHead() 
{
    if (sizeList > 0) {
        for (int i = 0; i < sizeList - 1; ++i) {
            aList[i] = aList[i + 1];
        }
        --sizeList;
    }
}

void objPosArrayList::removeTail() 
{
    if (sizeList > 0) {
        --sizeList;
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos) 
{
    if (sizeList > 0) {
        returnPos = aList[0];
    }
}

void objPosArrayList::getTailElement(objPos &returnPos) 
{
    if (sizeList > 0) {
        returnPos = aList[sizeList - 1];
    }
}

void objPosArrayList::getElement(objPos &returnPos, int index) 
{
    if (index >= 0 && index < sizeList) {
        returnPos = aList[index];
    }
    // case where the index is out of bounds
}