#ifndef DEVICEARRAY_H
#define DEVICEARRAY_H

#include "Device.h"

class DeviceArray{
  public:
    DeviceArray();
    ~DeviceArray();

    bool add(Device*);
    Device* get(const string& name) const;
    Device* get(int index) const;
    Device* remove(const string& name);
    Device* remove(int index);
    // void removeUpTo(const string& name, DeviceArray& goners);
    bool isFull() const;
    int getSize() const {return size;}
    void print() const;
    

  private:
    Device** elements;
    int size;
   
};

#endif

