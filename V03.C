#include <iostream>

#include "V03.H"

using namespace V03;

void demoV03_fibDemoComp(){
    long n = 50;
    long e;

    //e = fibIter(n);
    e = fibRecu(n);

    std::cout << "Fib(" << n << ") = " << e << std::endl;
}


void demoV03_exp(){
    int a = 2;
    int b = 9;

    std::cout << "Iteration:            " << 2 << "^" << b << " = " << exp00(a,b) << std::endl;
    std::cout << "einfache Rekursion:   " << 2 << "^" << b << " = " << exp01(a,b) << std::endl;
    std::cout << "erweiterte Rekursion: " << 2 << "^" << b << " = " << exp02(a,b) << std::endl;


}

void demoV03_TurmVonHanoi(){
    towerOfHanoi(3, 'A', 'B', 'C');
}


namespace V03{

long fibIter(long n){
	if((n==0) || (n==1)){
		return n;
	}
	long i=2;
	long n2=0;
	long n1=1;
	long result;
	while(i<=n){
		result = n2 + n1;
		n2     = n1;
		n1     = result;
		i++;
	}
	return result;
}


long fibRecu(long n){
	if((n==0) || (n==1)){
		return n;
	}
	return ( fibRecu(n-2) +
			   fibRecu(n-1)  );
}



int exp00(int a,int b){
    int res = 1;
    while(b>0){
        res = res*a;
        b--;
    }
    return res;
}

int exp01(int a,int b){
    if(b==1)return a;
    return (a*exp01(a,b-1));
}


int exp02(int a,int b){
    if(b==1) return a;
    if( ((b/2)*2) == b){
        return (exp02(a*a,b/2));
    }else{
        return (a*exp02(a,b-1));
    }
}


void towerOfHanoi(int n, char start, char tmp, char goal){
	if(n==1){
		std::cout << "move disk from " << start << " to " << goal << std::endl;
	}else{
		towerOfHanoi(n-1, start,  goal, tmp);
		towerOfHanoi(  1, start,   tmp, goal);
		towerOfHanoi(n-1,   tmp, start, goal);
	}
	return;
}


} // end namespace V0
