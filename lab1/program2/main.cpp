#include <iostream>
#include <windows.h>
using namespace std;

#define ull unsigned long long int

const int n = 2048;
int a[n];
int LOOP = 100;

void init()
{
    for (int i = 0; i < n; i++)
        a[i] = i;
}
void recursion(int m)
{
    if (m == 1)
        return;
    else
    {
        for (int i = 0; i < m / 2; i++)
            a[ i ] += a[m -i -1];
        m = m / 2;
        recursion(m);
    }
}
void ordinary()
{
    long long int begin, end, freq;
    QueryPerformanceFrequency((LARGE_INTEGER *) &freq);
    QueryPerformanceCounter((LARGE_INTEGER*) &begin);
    for(int l=0;l<LOOP;l++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
    }
    QueryPerformanceCounter((LARGE_INTEGER*) &end);
    cout<<"ordinary:"<<(end-begin)*1000.0/freq/LOOP<<"ms"<<endl;
}

void optimize_1()
{
    long long int begin, end, freq;
    QueryPerformanceFrequency((LARGE_INTEGER *) &freq);
    QueryPerformanceCounter((LARGE_INTEGER*) &begin);
    for(int l=0;l<LOOP;l++)
    {
        int sum1 = 0, sum2 = 0;
        for(int i=0;i<n; i+=2)
            sum1+=a[i],sum2+= a[i+1];
        int sum = sum1 + sum2;
    }
    QueryPerformanceCounter((LARGE_INTEGER*) &end);
    cout<<"optimize_1:"<<(end-begin)*1000.0/freq/LOOP<<"ms"<<endl;
}
void optimize_2()
{
    long long int begin, end, freq;
    QueryPerformanceFrequency((LARGE_INTEGER *) &freq);
    QueryPerformanceCounter((LARGE_INTEGER*) &begin);
    for(int l=0;l<LOOP;l++)
    {
        recursion(n);
    }
    QueryPerformanceCounter((LARGE_INTEGER*) &end);
    cout<<"optimize_2:"<<(end-begin)*1000.0/freq/LOOP<<"ms"<<endl;
}
void optimize_3(){
    long long int begin, end, freq;
    QueryPerformanceFrequency((LARGE_INTEGER *) &freq);
    QueryPerformanceCounter((LARGE_INTEGER*) &begin);
    for(int l=0;l<LOOP;l++)
    {
        for (int m = n; m > 1; m /= 2)
            for (int i = 0; i < m / 2; i++)
                a[ i ] = a[i * 2] + a[i * 2 + 1];

    }
    QueryPerformanceCounter((LARGE_INTEGER*) &end);
    cout<<"optimize_3:"<<(end-begin)*1000.0/freq/LOOP<<"ms"<<endl;
}

int main()
{
    init();
    ordinary();
    optimize_1();
    optimize_2();
    optimize_3();
}
