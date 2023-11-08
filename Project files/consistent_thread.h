#ifndef CONSISTENT_THREAD_H
#define CONSISTENT_THREAD_H

#include <iostream>
#include <vector>
using namespace std;

class Consistent_Thread
{
private:
    vector<vector<float>> v;
public:
    int n, m;
    clock_t time;
    Consistent_Thread(int a, int b);
    void calc();
};

#endif // CONSISTENT_THREAD_H
