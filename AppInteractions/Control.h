#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include "AppMarket.h"
#include <random>
#include <unordered_set>
#include <sstream>
#include "DeviceManager.h"
#include "View.h"

using namespace std;

class Control {
		
	public:
		void launch();
	
	private:
		void initApps();
		void initDevices();
		void printApps();
		void printDevices();
		void printAppDetails();
		void printDeviceDetails();
		void addAppsToDevice();
		void deleteApp();
		void deleteDevice();
		void cloneDevice();
		

		View view;

		AppMarket appMarket;
		DeviceManager deviceManager;
	
};
#endif