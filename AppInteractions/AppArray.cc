#include <iostream>
using namespace std;

#include "AppArray.h"

AppArray::AppArray(){
    size = 0;
    elements = new App*[MAX_ARRAY];
}

/*
    Usually bad form to delete elements in a list,
    since they may be stored in more than one list.
    However, we can delete the List.
*/
AppArray::~AppArray(){  // don't delete the apps cause they were'nt created here
    for (int i=0; i<size; i++){
        delete elements[i];
    }
    delete [] elements;
}

bool AppArray::add(App* a){
    if (isFull()) return false;
    // assign a to the back of array
    elements[size] = a;
    ++size;
    return true;
}


App* AppArray::get(const string& name) const{
    App* aPtr;
    for (int i = 0; i < size; ++i){
        if (name == elements[i]->getTitle()){
            aPtr = elements[i];
            return aPtr;
        }
    }
    return nullptr;
}

App* AppArray::get(const int index) const{
    if (index < 0 || index >= size) return nullptr;
    App* aPtr = elements[index];
    return aPtr;
}

App* AppArray::remove(const string& name){
    
    int index = 0;
    //we want to find the index of the element to remove
    while (name != elements[index]->getTitle()&& index < size){
        ++index;
    }

    //did we fall off the end of the List?
    if (index == size) return nullptr;

    //we have found what we wanted to remove,
    //assign the output value
    App* a = elements[index];
    delete elements[index];

    //copy everything after index left one position
    while (index < size - 1){
        elements[index] = elements[index + 1];
        ++index;
    }
    --size;
    return a;

}
App* AppArray::remove(int index){
    //finds the right index for date
    if (index >= size || index < 0) {
        cerr<<"Error: index is out of bounds"<<endl; 
        return nullptr;
    }
    else{
        App* a = elements[index];
        delete elements[index];
        int i = index;
        while (i < size){
            elements[i] = elements[i+1];
            ++i;
        }
        --size;
        return a;
    }
}

// void AppArray::removeUpTo(const string& name, AppArray& arr){
//     //find index of the first adent who comes after name
//     int index = 0;

//     while (name >= elements[index]->getTitle()&& index < size){
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

bool AppArray::isFull() const{
    return (size >= MAX_ARRAY);
}
void AppArray::print() const{
    cout<<"Apps:"<<endl;
    for (int i=0; i<size; ++i){
        if (elements[i] == nullptr){
            continue;
        }
        else{
            elements[i]->printWithIcon();
            cout<<endl;
        }
    }
    // for (int i=0; i<size; ++i){
    //     elements[i]->print();
    // }
}