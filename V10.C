#include <cstdlib>
#include "V10.H"



void demoV10(){
    //using namespace V10; // fixed ring buffer size
    using namespace V10; // increasing ring buffer size;

    int i;
    int n = 50;

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
