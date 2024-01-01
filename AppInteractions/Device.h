#ifndef DEVICE_H
#define DEVICE_H

#include "AppArray.h"

class Device{
    public:
        // ctor & dtor
        Device(const string& name, const string& deviceType, const string& os);
        ~Device();

        // getters
        string getName() const;
        bool equals(const string& name) const;
        bool addApp(const App&);
        bool deleteApp(const string& title);
        void cloneApps(Device&);
        int numApps() const;
        void print() const;
        void printWithApps() const;

    private:
        string name, deviceType, os;
        AppArray apps; 
};

#endif