#ifndef APPMARKET_H
#define APPMARKET_H

#include "AppArray.h"

class AppMarket{
    public:
        void addApp(const string&, const string&, const string&);
        void deleteApp(int index);
        const App* getApp(int) const;

        void printApps() const;
        void printAppDetails(int index)const;

    private:
        // AppArray* apps = new AppArray();
        AppArray apps;

};

#endif