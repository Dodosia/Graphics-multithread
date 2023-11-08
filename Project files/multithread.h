#ifndef MULTITHREAD_H
#define MULTITHREAD_H

#include <iostream>
#include <vector>
using namespace std;

class Multithread
{
private:
    vector<vector<float>> v;
public:
    int n, m;
    clock_t time2;
    clock_t time4;
    clock_t time8;
    Multithread(int a, int b);
    void calc();
    void calc2();
    void calc3();
};

#endif // MULTITHREAD_H
