#include "parallel.h"
#include <omp.h>

Parallel::Parallel(int a, int b) : n(a), m(b)
{
    for (int i = 1; i <= n; i++)
    {
        vector<float> row;
        for (int j = 1; j <= m; j++)
        {
            row.push_back(18 * (float)i / 100);
        }
        v.push_back(row);
    }

    calc();
}

void Parallel::calc()
{
    long c = 1.0;
    long s = 0;

    time = clock();
    {
        omp_set_num_threads(4);
#pragma omp parallel for num_threads(4)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                c *= 1.0 / v[i][j];
            }
            s += c;
            c = 1.0;
        }
    }
    time = clock() - time;

    cout << endl << "The sum is: " << s;
    cout << endl << "Seconds: " << static_cast<float>(time) / CLOCKS_PER_SEC;
}
