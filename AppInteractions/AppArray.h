#ifndef APPARRAY_H
#define APPARRAY_H

#include "App.h"

class AppArray{
  public:
    AppArray();
    ~AppArray();

    bool add(App*);
    App* get(const string& name) const;
    App* get(int index) const;
    App* remove(const string& name);
    App* remove(int index);
    // void removeUpTo(const string& name, AppArray& goners);
    bool isFull() const;

    // Add all students on the honour roll to hr.
    // This is why we don't delete - students may be in 
    // more than one List. If we delete automatically,
    // when we delete the honour roll all those students 
    // would be lost.
    // void getHonourRoll(AppArray& hr);
    inline int getSize() const {return size;}
    void print() const;
    

  private:
    App** elements;
    int size;
   
};

#endif

