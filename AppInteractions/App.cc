#include "App.h"

// constructor
App::App(const string& t, const string& d,const string& i){
    title = t;
    description = d;
    icon = i;
}

App::App(){
    title = "Mario";
    description = "Awesome game, with awesome activities. Can do racing or running challenges!!";
    icon = ":)";
}

// copy constructor
// *DONT include in assignment
// App::App(App& a){
//     title = a.title;
//     description = a.description;
//     icon = "RCMP copyright infringement";
// }

// getter
string App::getTitle() const{ return title;}

// other
bool App::equals(const string& t) const{
    return (t == title);
}
void App::print() const{              
    cout<<"Title:        "<<title<<endl;
    cout<<"Description:  "<<description<<endl;
}
void App::printWithIcon() const{
    print();
    cout<<"Icon:         "<<icon<<endl;
}