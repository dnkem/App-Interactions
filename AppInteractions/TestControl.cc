
#include "TestControl.h"
#include "DeviceManager.h"
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;
#define NUM_DEVICES 4
#define NUM_OS 5
extern const  string DEVICETYPE[NUM_DEVICES];
extern const  string OS[NUM_OS];
extern const string deviceNames[5];
extern int deviceType[5];
extern int os[5];
extern const string appTitles[10];
extern const string descriptions[10];
extern const string icons[10];



void TestControl::launch(){

    vector<string> menu ={
        "Test print apps",
        "Test print app details",
        "Test delete app",
        "Test print devices",
        "Test print device apps",
        "Test delete device",
        "Test add app to device", 
        "Test clone device",
        "Test all and get mark"
    };

    int choice = -1;

    while (choice!= 0){
        view.menu(menu, choice);
        switch(choice){
            case 1: testPrintApps(); break;
            case 2: testPrintAppDetails(); break;
            case 3: testDeleteApp(); break;
            case 4: testPrintDevices(); break;
            case 5: testPrintDeviceDetails(); break;
            case 6: testDeleteDevice(); break;
            case 7: testAddAppToDevice(); break;
            case 8: testCloneDevice(); break;
            case 9: int mark = testPrintApps();
                    mark+= testPrintAppDetails();
                    mark+= testDeleteApp();
                    mark+= testPrintDevices();
                    mark+= testPrintDeviceDetails();
                    mark+= testDeleteDevice();
                    mark+= testAddAppToDevice();
                    mark+= testCloneDevice();
                    cout<<"Total mark: "<<mark<<"/16"<<endl;
                    break;
        }
    }
    cout<<"exiting program!!!"<<endl;
}

void TestControl::initApps(AppMarket& am){
    cout<<"Initializing apps..."<<endl;
    for (int i = 0; i < 10; ++i){
        am.addApp(appTitles[i], descriptions[i], icons[i]);
    }
    cout<<"Apps initialized!"<<endl;
}

void TestControl::initDevices(DeviceManager& dm){
    cout<<"Initializing devices..."<<endl;
    for (int i = 0; i < 5; ++i){
        dm.addDevice(deviceNames[i], DEVICETYPE[deviceType[i]], OS[os[i]]);
    }
    cout<<"Devices initialized!"<<endl;
}

int TestControl::testPrintApps(){
    cout<<"1. Test print apps"<<endl;
    AppMarket am;
    cout<<"Initializing app market"<<endl;
    initApps(am);
    cout<<"Printing apps..."<<endl;
    tester.initCapture();
    am.printApps();
    tester.endCapture();
    vector<int> keys = {0,1,2,3,4,5,6,7,8,9};
    int error = 0;
    tester.find(keys, appTitles, error);
    if (error>0 && error <10){
        cout<<error<<" titles not found, test failed, 1/2 marks"<<endl;
        return 1;
    }else if (error >= 10){
        cout<<"No app titles found, test failed, 0/2 marks"<<endl;
        return 0;
    }
    cout<<"All app titles found, test passed, 2 marks"<<endl;
    return 2;
}

int TestControl::testPrintAppDetails(){
    cout<<"2. Test print app details"<<endl;
    AppMarket am;
    cout<<"Initializing app market"<<endl;
    initApps(am);
    cout<<"Printing selected apps..."<<endl;
    vector<int> keys;
    tester.ran(keys, 4, 10);
    tester.initCapture();
    for (int i: keys){
        am.printAppDetails(i);
    }
    tester.endCapture();
    
    int error = 0;
    int marks = 2;
    tester.findInOrder(keys, appTitles, error);
    if (error>0){
        cout<<"Some titles our of order, -1"<<endl;
        --marks;
    }
    cout<<"All app titles found in order, test passed"<<endl;
    cout<<"Searching for icons"<<endl;
    error = 0;
    tester.findInOrder(keys, icons, error);
    if (error>0){
        cout<<"Some icons out of order, -1"<<endl;
        --marks;
    }
    cout<<"All icons found in order, test passed"<<endl;
    cout<<"Mark: "<<marks<<"/2"<<endl;
    return marks;
}
		
int TestControl::testDeleteApp(){
    cout<<"3. Test delete app"<<endl;
    AppMarket am;
    cout<<"Initializing app market"<<endl;
    initApps(am);
    cout<<"Printing apps..."<<endl;
    tester.initCapture();
    am.printApps();
    tester.endCapture();
    vector<int> keys = {0,1,2,3,4,5,6,7,8,9};
    int error = 0;
    tester.find(keys, appTitles, error);
    if (error>0){
        cout<<error<<" titles not found, test aborted"<<endl;
        return 0;
    }
    vector<int> todelete;
    tester.ran(todelete, 4, 10);
    // sort todelete
    sort(todelete.begin(), todelete.end());
    int count = 0;
    for (int i: todelete){
        am.deleteApp(i-count);
        for (int j = 0; j < keys.size(); ++j){
            if (keys[j] == i){
                keys.erase(keys.begin()+j);
                break;
            }
        }
        ++count;
    }
    cout<<"Printing apps after delete..."<<endl;
    tester.initCapture();
    am.printApps();
    tester.endCapture();
    error = 0;
    tester.find(keys, appTitles, error);
    if (error>0){
        cout<<error<<" titles not found, test failed"<<endl;
        return 0;
    }
    error = 0;
    tester.find(todelete, appTitles, error);
    if (error!=todelete.size()){
        cout<<"Deleted apps found, test failed"<<endl;
        return 0;
    }
    cout<<"Delete app test successful, 2 marks"<<endl;
    return 2;
}


int TestControl::testPrintDevices(){
    cout<<"4. Test print devices"<<endl;
    DeviceManager dm;
    cout<<"Initializing device manager"<<endl;
    initDevices(dm);
    cout<<"Printing devices..."<<endl;
    tester.initCapture();
    dm.printDevices();
    tester.endCapture();
    vector<int> keys = {0,1,2,3,4};
    int error = 0;
    tester.find(keys, deviceNames, error);
    if (error>0 && error <5){
        cout<<error<<" device names not found, test failed, 1/2 marks"<<endl;
        return 1;
    }else if (error >= 10){
        cout<<"No device names found, test failed, 0/2 marks"<<endl;
        return 0;
    }
    cout<<"All device names found, test passed, 2 marks"<<endl;
    return 2;
}


// half marks here, half marks after we test loading apps
int TestControl::testPrintDeviceDetails(){
    cout<<"5. Test print device details"<<endl;
    DeviceManager dm;
    cout<<"Initializing device manager"<<endl;
    initDevices(dm);
    cout<<"Printing selected devices..."<<endl;
    vector<int> keys;
    tester.ran(keys, 4, 5);
    tester.initCapture();
    for (int i: keys){
        cout<<"Testing device "<<i<<endl;
        dm.printDeviceDetails(i);
    }
    tester.endCapture();
    
    int error = 0;
    tester.findInOrder(keys, deviceNames, error);
    if (error>0){
        cout<<"Some titles not found or out of order, test failed"<<endl;
        return 0;
    }
    cout<<"All device names found in order, test passed, 2 marks"<<endl;
    return 2;
}

int TestControl::testDeleteDevice(){
    cout<<"6. Test delete device"<<endl;
    DeviceManager dm;
    cout<<"Initializing device manager"<<endl;
    initDevices(dm);
    cout<<"Printing devices..."<<endl;
    tester.initCapture();
    dm.printDevices();
    tester.endCapture();
    vector<int> keys = {0,1,2,3,4};
    int error = 0;
    tester.find(keys, deviceNames, error);
    if (error>0){
        cout<<error<<" device names not found, test aborted"<<endl;
        return 0;
    }
    vector<int> todelete;
    tester.ran(todelete, 2, 5);
    // sort todelete
    sort(todelete.begin(), todelete.end());
    cout<<"Deleting: "<<endl;
    for (int i: todelete){
        cout<<deviceNames[i]<<" "<<i<<endl;
    }  
    int count = 0;
    for (int i: todelete){
        dm.deleteDevice(i-count);
        for (int j = 0; j < keys.size(); ++j){
            if (keys[j] == i){
                keys.erase(keys.begin()+j);
                break;
            }
        }
        ++count;
    }
     
    cout<<"Printing devices after delete..."<<endl;
    tester.initCapture();
    dm.printDevices();
    tester.endCapture();
    error = 0;
    tester.find(keys, deviceNames, error);
    if (error>0){
        cout<<error<<" device names not found, test failed"<<endl;
        return 0;
    }
    error = 0;
    tester.find(todelete, deviceNames, error);
    if (error!=todelete.size()){
        cout<<"Deleted devices found, test failed"<<endl;
        return 0;
    }
    cout<<"Delete device test successful, 2 marks"<<endl;
    return 2;
}

int TestControl::testAddAppToDevice(){
    cout<<"7. Test add app to device"<<endl;
    AppMarket am;
    cout<<"Initializing app market"<<endl;
    initApps(am);
    DeviceManager dm;
    cout<<"Initializing device manager"<<endl;
    initDevices(dm);
    vector<int> appKeys1;
    vector<int> appKeys2;
    vector<int> deviceKeys;
    tester.ran(appKeys1, 4, 10);
    tester.ran(appKeys2, 4, 10);
    tester.ran(deviceKeys, 2, 5);
    cout<<"Adding apps to devices"<<endl;
    Device* d1 = dm.getDevice(deviceKeys[0]);
    Device* d2 = dm.getDevice(deviceKeys[1]);
    for (int i: appKeys1){
        // dm.downloadToDevice(deviceKeys[0], i, am);
        const App* a = am.getApp(i);
        d1->addApp(*a);
    }
    for (int i: appKeys2){
        // dm.downloadToDevice(deviceKeys[1], i, am);
        const App* a = am.getApp(i);
        d2->addApp(*a);
    }
    cout<<"Printing device details"<<endl;
    tester.initCapture();
    dm.printDeviceDetails(deviceKeys[0]);
    tester.endCapture();
    int error = 0;
    tester.findInOrder(appKeys1, appTitles, error);
    if (error>0){
        cout<<"Some apps not found, test failed"<<endl;
        return 0;
    }
    tester.initCapture();
    dm.printDeviceDetails(deviceKeys[1]);
    tester.endCapture();
    error = 0;
    tester.findInOrder(appKeys2, appTitles, error);
    if (error>0){
        cout<<"Some apps not found, test failed"<<endl;
        return 0;
    }
    cout<<"All apps found, test passed, 2 marks"<<endl;
    return 2;
}
		
int TestControl::testCloneDevice(){
    cout<<"8. Test clone device"<<endl;
    AppMarket am;
    cout<<"Initializing app market"<<endl;
    initApps(am);
    DeviceManager dm;
    cout<<"Initializing device manager"<<endl;
    initDevices(dm);
    vector<int> appKeys;
    vector<int> deviceKeys;
    tester.ran(deviceKeys, 2, 5);
    sort(deviceKeys.begin(), deviceKeys.end()); 
    tester.ran(appKeys, 4, 10);
    cout<<"Adding apps to device"<<endl;
    Device* d1 = dm.getDevice(deviceKeys[0]);
    for (int i: appKeys){
        //dm.downloadToDevice(deviceKeys[0], i, am);
        const App* a = am.getApp(i);
        d1->addApp(*a);
    }
    cout<<"Printing original device details"<<endl;
    dm.printDeviceDetails(deviceKeys[0]);
    cout<<"Cloning above device to "<<deviceNames[deviceKeys[1]]<<endl;
    tester.pressEnterToContinue();
    tester.pressEnterToContinue(); 
    dm.cloneDevice(deviceKeys[1], deviceKeys[0]);
    cout<<"Printing clone device details"<<endl;
    tester.initCapture();
    dm.printDeviceDetails(deviceKeys[1]);
    tester.endCapture();
    int error = 0;
    tester.findInOrder(appKeys, appTitles, error);
    if (error>0){
        cout<<"Some apps not found, test failed"<<endl;
        return 0;
    }
    cout<<"All apps found, test passed"<<endl;
    cout<<"Deleting original device (did you do a deep copy of the apps?)"<<endl;
    tester.pressEnterToContinue();
    dm.deleteDevice(deviceKeys[0]);
    cout<<"Printing clone device details"<<endl;
    tester.initCapture();
    dm.printDeviceDetails(deviceKeys[1]-1);
    tester.endCapture();
    error = 0;
    tester.findInOrder(appKeys, appTitles, error);
    if (error>0){
        cout<<"Some apps not found, test failed"<<endl;
        return 2;
    }
    cout<<"All apps found, test passed, 2 marks"<<endl;
    return 4;
}

#define NUM_DEVICES 4
#define NUM_OS 5

const  string DEVICETYPE[NUM_DEVICES]={"PHONE", "TABLET", "LAPTOP", "DESKTOP"};
const  string OS[NUM_OS] = {"ANDROID", "IOS", "WINDOWS", "MACOS", "LINUX"};


// random titles
const string deviceNames[5] = {"My Android Phone", "My iPad", "My Gaming Desktop", "My Macbook", "My Linux Laptop"};
int deviceType[5] = {0, 1, 3, 2, 2};
int os[5] = {0, 1, 2, 3, 4};


const string appTitles[10] = {"Flappy Birds", "Office", "Snapchat", "VirtualBox", "Grand Theft Auto 6", "Messages", "Netflix", "iTunes", "Photoshop", "Gimp"};
const string descriptions[10] = {"Video game", "Office apps", "Social Media", "OS Virtualization", "AAA Game", "Text Messages", "Video Streaming", "Music and Video Streaming", "Editing", "Image Editing"};

const string icons[10] = {
R"(
  ___
 / _ \
| (_) |
 \___/
)",

R"(
  ,--.
 /  0 \
|   .  |
 \___/
)",

R"(
  ,--.
 /  0 \
|   |  |
 \___/
)",

R"(
  ,--.
 /  0 \
|   |  |
 \__O/
)",

R"(
   /\
  /  \
 |    |
 |----|
 |    |
 |----|
)",

R"(
   /\
  /  \
 | [] |
 |----|
 |    |
 |----|
)",

R"(
 ______
/ 0  0 \
|    ∆   |
 \_____/
)",

R"(
  ____
 /  00\
|    0 |
|______|
)",

R"(
   ,--.
  / 00\
 |  |  |
  \__/
)",

R"(
  ,--,
 /    \
|  ☏   |
 \    /
  '--'
)"
};
