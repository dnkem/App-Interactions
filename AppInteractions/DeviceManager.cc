#include "DeviceManager.h"

bool DeviceManager::addDevice(const string& name,const string& type, const string& os) {
    if (devices.isFull()) return false;

    Device* dPtr = new Device(name, type, os);
    if (devices.add(dPtr))return true;
    //adding a Student has failed - delete the Student object 
    //to prevent memory leaks
    delete dPtr;
    return false;
}

bool DeviceManager::deleteDevice(int index){
    Device* dPtr = devices.remove(index);
    if (dPtr != nullptr){return true;}
    return false;
}

bool DeviceManager::cloneDevice(int cloneTo, int cloneFrom){
    //**************************HELP************************
    // check bounds
    if (cloneTo >= devices.getSize() || cloneTo < 0 || cloneFrom >= devices.getSize() || cloneFrom < 0){
        cout<<"One or both of the devices do not exist"<<endl;
        return false;
    }
    else{
        cout<<"Neither are NULL"<<endl;
        Device* dPtr = devices.get(cloneTo);// d currently contains info from this index
        Device* copy = devices.get(cloneFrom);
        dPtr->cloneApps(*copy);
        return true;
    }
}

Device* DeviceManager::getDevice(int index)const{
    if (index >= MAX_ARRAY || index <0) return nullptr;
    Device* dPtr = devices.get(index);
    return dPtr;
}

void DeviceManager::printDevices()const{
    cout<<endl;
    cout<<"All Devices: "<<endl;
    cout<<endl;
    for(int i=0; i<devices.getSize(); i++){
        Device* dPtr = devices.get(i);
        if (dPtr == nullptr) {
            continue;
        }
        else {
            cout<<i<<":"<<endl;
            dPtr->print();
            cout<<endl;
        }
    }
}

void DeviceManager::printDeviceDetails(int index) const{
    cout<<endl;
    cout<<"Devices at index: "<< index <<endl;
    Device* dPtr = devices.get(index);
    dPtr->printWithApps();
}

