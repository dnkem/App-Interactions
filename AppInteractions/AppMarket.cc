#include "AppMarket.h"

void AppMarket::addApp(const string& t, const string& d, const string& o){
    if (apps.isFull()) return;
    App* a = new App(t, d, o);
    apps.add(a);
    return;
}
void AppMarket::deleteApp(int index){
    App* aPtr = apps.remove(index);
    // check if this is null
    // if (aPtr == null)

}
const App* AppMarket::getApp(int index) const{
    App* aPtr = apps.get(index);
    return aPtr;
}
void AppMarket::printApps() const{
    cout<<endl;
    cout<<"Apps: "<<endl;
    App* aPtr;
    for(int i=0; i<apps.getSize(); i++){
        aPtr = apps.get(i);
        cout<<i<<":"<<endl;
        aPtr->print();
        cout<<endl;
    }
}

void AppMarket::printAppDetails(int index) const{
    cout<<"App Details at index: "<< index <<endl;
    App* aPtr;
    aPtr = apps.get(index);
    aPtr->printWithIcon();
}
