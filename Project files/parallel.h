#ifndef PARALLEL_H
#define PARALLEL_H

#include <iostream>
#include <vector>
using namespace std;

class Parallel
{
private:
    vector<vector<float>> v;

public:
    int n, m;
    clock_t time;
    Parallel(int a, int b);
    void calc();
};

#endif // PARALLEL_H
