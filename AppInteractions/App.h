#ifndef APP_H
#define APP_H
#include "defs.h"

#include <iostream>

using namespace std;

class App{
    public:
        // constructor
        // const string& is a read only refernce, meaning they can't be changedc
        App(const string& title, const string& description, const string& icon);
        App();
        

        // getter
        string getTitle() const;

        // other
        bool equals(const string& title) const;
        void print() const;                   //  w/o icon
        void printWithIcon() const;


    private:
        string title;
        string description;
        string icon;
};

#endif