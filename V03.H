#ifndef V03_H_INCLUDED
#define V03_H_INCLUDED


/*
 * Aufruf der Demos
 *
 */
void demoV03_fibDemoComp();
void demoV03_exp();
void demoV03_TurmVonHanoi();


namespace V03{

long fibIter(long n);
long fibRecu(long n);


int exp00(int a,int b);
int exp01(int a,int b);
int exp02(int a,int b);

void towerOfHanoi(int n, char start, char tmp, char goal);

} // end namespace V03

#endif // V03_H_INCLUDED
