#ifndef DEVICEMANAGER
#define DEVICEMANAGER

#include "DeviceArray.h"

class DeviceManager{
    public:
        bool addDevice(const string& name, const string& type, const string& os);
        bool deleteDevice(int index);
        bool cloneDevice(int cloneTo, int cloneFrom);
        Device* getDevice(int index) const;

        void printDevices() const;
        void printDeviceDetails(int index) const;


    private:
        DeviceArray devices;
};

#endif