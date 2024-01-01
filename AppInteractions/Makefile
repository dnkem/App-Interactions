
objects = View.o DeviceManager.o AppMarket.o DeviceArray.o Device.o AppArray.o App.o Tester.o 

all: a2 a2test

a2: main.o $(objects) Control.o
	g++ -o  a2 main.o $(objects) Control.o

a2test: testmain.o $(objects) TestControl.o
	g++ -o a2test testmain.o $(objects) TestControl.o

testmain.o: testmain.cc
	g++ -c testmain.cc

main.o: main.cc
	g++ -c main.cc 

View.o: View.h View.cc 
	g++ -c View.cc

Control.o: Control.h Control.cc
	g++ -c Control.cc

TestControl.o: TestControl.h TestControl.cc 
	g++ -c TestControl.cc

DeviceManager.o: DeviceManager.h DeviceManager.cc 
	g++ -c DeviceManager.cc

AppMarket.o: AppMarket.h AppMarket.cc
	g++ -c AppMarket.cc

DeviceArray.o: DeviceArray.h DeviceArray.cc
	g++ -c DeviceArray.cc

Device.o: Device.cc Device.h
	g++ -c Device.cc

AppArray.o: AppArray.cc AppArray.h
	g++ -c AppArray.cc
	
App.o: App.cc App.h 
	g++ -c App.cc

Tester.o: Tester.cc Tester.h
	g++ -c Tester.cc

clean:
	rm -f a2 a2test *.o	