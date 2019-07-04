#ifndef V05_H_INCLUDED
#define V05_H_INCLUDED

using namespace std;

void demoV05_komplexeZahlen();
void demoV05_Klassenzeiger();
void demoV05_NmbSet();



namespace V05{


class ComplNmb{


    // members
    float re_;
    float im_;

    // methods
    public:

    ComplNmb();
    void set(float r, float i){re_ = r; im_ = i;};
    void out();
    void add(ComplNmb a);
    void con();

};


}


namespace Klassenzeiger{

class A {
public:
    void out() { cout << "class A\n"; };
};


class B : public A{
public:
    void out() { cout << "class B\n";}

};


class AA {
public:
    virtual void out() { cout << "class AA\n"; };
};


class BB : public AA{
public:
    virtual void out() { cout << "class BB\n";}

};



}



namespace Numberset{

class NumberSet{

    int *dataField_;
    int size_;
    int next_;

public:

    NumberSet(int size = 10){};
    ~NumberSet(){};
    void out(){return;};
    void insert(int nmb){return;}

    virtual void sort() = 0;
};


}

#endif // V05_H_INCLUDED
