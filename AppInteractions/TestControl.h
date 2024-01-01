#ifndef TESTCONTROL_H
#define TESTCONTROL_H

#include <iostream>
#include <string>
#include <random>
#include <unordered_set>
#include <sstream>
#include "AppMarket.h"
#include "DeviceManager.h"
#include "View.h"
#include "Tester.h"

using namespace std;

class TestControl {
		
	public:
		void launch();
	
	private:
		void initApps(AppMarket& am);
		int testPrintApps();
		int testPrintAppDetails();
		int testDeleteApp();


		void initDevices(DeviceManager& dm);
		int testPrintDevices();
		int testPrintDeviceDetails();
		int testDeleteDevice();

		int testAddAppToDevice();
		int testCloneDevice();
		

		View view;
		Tester tester;

		
	
};
#endif