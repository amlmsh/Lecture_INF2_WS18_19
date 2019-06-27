
#include <cstdlib>
#include "V09.H"


void demoV09(){

    using namespace V09;

    int i;
    int n = 7;

    List<int> l;

    for(i=0;i<n;i++){
        l.append(rand() % n);
        l.print();
        cout << endl;
        l.prepend(rand() % n);
        l.print();
        cout << endl;
    }



    for(i=0;i<n+5;i++){
            l.removeLast();
            l.print();
            cout << endl;
            l.removeFirst();
            l.print();
            cout << endl;
    }
}
