#include <iostream>

#include "V05.H"

using namespace std;
using namespace V05;

void demoV05_komplexeZahlen(){

    std::cout << "demo V05 komplexe Zahlen" << std::endl;

    ComplNmb c;

    c.out();
    c.set(1.1, 2.2);
    c.out();
    c.con();
    c.out();

    std::cout << std::endl;
}


void demoV05_Klassenzeiger(){
    using namespace Klassenzeiger;

    A *ptrA;
    A a;
    B b;
    ptrA = &b;
    ptrA->out();


    AA *ptrAA;
    AA aa;
    BB bb;
    ptrAA = &bb;
    ptrAA->out();


}



ComplNmb::ComplNmb(){
    re_ = 0.0;
    im_ = 0.0;
}

void ComplNmb::out(){
    if(im_ >= 0){
        cout << "(" << re_ << " + " << im_ << "i)";
    }else{
        cout << "(" << re_ << " - " << -im_ << "i)";
    }
}

void ComplNmb::add(ComplNmb a){
    re_ += a.re_;
    im_ += a.im_;
}

void ComplNmb::con(){
    im_ = -im_;
}
