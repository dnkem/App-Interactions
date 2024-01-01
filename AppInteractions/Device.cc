#include "Device.h"

Device::Device(const string& n, const string& dType, const string& operateS){
    name = n;
    deviceType = dType;
    os = operateS;
}
Device::~Device(){
    // cout<<"DESTRUCT"<<endl;
    // delete &apps;
}
string Device::getName()const{
    return name;
}
bool Device::equals(const string& n) const{
    return (n == name);
}
bool Device::addApp(const App& a){
    if (apps.isFull()) return false;
    App* aPtr = new App(a);
    if (apps.add(aPtr))return true;
    // delete aPtr;
    return false;
}
bool Device::deleteApp(const string& t){
    App* a = apps.remove(t);
    if (a != nullptr) return true;
    return false;
}

void Device::cloneApps(Device& dev){ // copy from dev
    // clear all the apps first
    cout<<"Cloning Apps"<<endl;
    for (int i=0; i<numApps(); i++){
        App* a = apps.get(i);
        deleteApp(a->getTitle());
    }
    // add the new apps from dev
    for (int i=0; i<dev.numApps(); i++){
        App* a = dev.apps.get(i);
        addApp(*a);
    }
}

int Device::numApps()const{
    return apps.getSize();
}
void Device::print() const{
    // cout<<endl;
    cout<<"Device Name:   "<< name <<endl;
    cout<<"Device Type:   "<< deviceType <<endl;
    cout<<"Device OS:     "<< os <<endl;
    cout<<"No. of Apps:   "<< numApps() <<endl;

}
void Device::printWithApps() const{
    print();
    cout<<endl;
    apps.print();  
}