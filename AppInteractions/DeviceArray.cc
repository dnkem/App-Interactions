#include <iostream>
using namespace std;

#include "DeviceArray.h"

DeviceArray::DeviceArray(){
    size = 0;
    elements = new Device*[MAX_ARRAY];
}

/*
    Usually bad form to delete elements in a list,
    since they may be stored in more than one list.
    However, we can delete the List.
*/
DeviceArray::~DeviceArray(){  // don't delete the apps cause they were'nt created here
    for (int i=0; i<size; i++){
        delete elements[i];
    }
    delete [] elements;
}

bool DeviceArray::add(Device* d){
    if (isFull()) return false;
    // assign a to the back of array
    elements[size] = d;
    ++size;
    return true;
}


Device* DeviceArray::get(const string& name) const{
    for (int i = 0; i < size; ++i){
        if (name == elements[i]->getName()){
            Device* d = elements[i];
            return d;
        }
    }
    return nullptr;
}

Device* DeviceArray::get(int index) const{
    if (index < 0 || index >= size) return nullptr;
    Device* d = elements[index];
    return d;
}

Device* DeviceArray::remove(const string& name){
    
    int index = 0;
    //we want to find the index of the element to remove
    while (name != elements[index]->getName()&& index < size){
        ++index;
    }

    //did we fall off the end of the List?
    if (index == size) return nullptr;

    //we have found what we wanted to remove,
    //assign the output value
    Device* d = elements[index];
    delete elements[index];

    //copy everything after index left one position
    while (index < size - 1){
        elements[index] = elements[index + 1];
        ++index;
    }
    --size;
    return d;

}
Device* DeviceArray::remove(int index){
    //finds the right index for date
    if (index >= size || index < 0) {
        cerr<<"Error: index is out of bounds"<<endl; 
        return nullptr;
    }
    else{

        Device* d = elements[index];
        delete elements[index];

        int i = index;
        while (i < size){
            elements[i] = elements[i+1];
            ++i;
        }
        --size;
        return d;
    }
}


// void DeviceArray::removeUpTo(const string& name, DeviceArray& arr){
//     //find index of the first adent who comes after name
//     int index = 0;

//     while (name >= elements[index]->getName()&& index < size){
//         //return them to the calling function
//         arr.add(elements[index++]);
//     }

//     //the number of items to remove
//     int toRemove = index;
//     while(index < size){
//         elements[index - toRemove] = elements[index];
//         ++index;
//     }

//     size -= toRemove;
// }

bool DeviceArray::isFull() const{
    return (size >= MAX_ARRAY);
}
void DeviceArray::print() const{
    for (int i=0; i<size; ++i){
        elements[i]->print();
    }
}