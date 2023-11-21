#include "multithread.h"
#include <thread>
#include <mutex>

Multithread::Multithread(int a, int b) : n(a), m(b)
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
    calc2();
    calc3();
}

void Multithread::calc()
{
    long c, s;
    s = 0;
    mutex mut;

    time2 = clock();

    thread th1([&]()
               {
                   mut.lock();

                   c = 1.0;

                   for (int i = 0; i < n/2; i++)
                   {
                       for (int j = 0; j < m; j++)
                       {
                           c *= 1.0 / v[i][j];
                       }
                       s += c;
                       c = 1.0;
                   }

                   mut.unlock();
               });

    thread th2([&]()
               {
                   mut.lock();

                   c = 1.0;

                   for (int i = n/2; i < n; i++)
                   {
                       for (int j = 0; j < m; j++)
                       {
                           c *= 1.0 / v[i][j];
                       }
                       s += c;
                       c = 1.0;
                   }
                   mut.unlock();
               });

    th1.join();
    th2.join();

    time2 = clock() - time2;

    cout << endl << "The sum is: " << s;
    cout << endl << "Seconds: " << static_cast<float>(time2) / CLOCKS_PER_SEC;
}

void Multithread::calc2()
{
    long c, s;
    s = 0;
    mutex mut;

    time4 = clock();

    thread th1([&]()
               {
                   mut.lock();

                   c = 1.0;

                   for (int i = 0; i < n/4; i++)
                   {
                       for (int j = 0; j < m; j++)
                       {
                           c *= 1.0 / v[i][j];
                       }
                       s += c;
                       c = 1.0;
                   }

                   mut.unlock();
               });
    thread th2([&]()
               {
                   mut.lock();

                   c = 1.0;

                   for (int i = n/4; i < n/2; i++)
                   {
                       for (int j = 0; j < m; j++)
                       {
                           c *= 1.0 / v[i][j];
                       }
                       s += c;
                       c = 1.0;
                   }
                   mut.unlock();
               });
    thread th3([&]()
               {
                   mut.lock();

                   c = 1.0;

                   for (int i = n/2; i < 3*n/4; i++)
                   {
                       for (int j = 0; j < m; j++)
                       {
                           c *= 1.0 / v[i][j];
                       }
                       s += c;
                       c = 1.0;
                   }
                   mut.unlock();
               });
    thread th4([&]()
               {
                   mut.lock();

                   c = 1.0;

                   for (int i = n/4; i < n; i++)
                   {
                       for (int j = 0; j < m; j++)
                       {
                           c *= 1.0 / v[i][j];
                       }
                       s += c;
                       c = 1.0;
                   }
                   mut.unlock();
               });
    th1.join();
    th2.join();
    th3.join();
    th4.join();

    time4 = clock() - time4;

    cout << endl << "The sum is: " << s;
    cout << endl << "Seconds: " << static_cast<float>(time4) / CLOCKS_PER_SEC;
}

void Multithread::calc3()
{
    long c, s;
    s = 0;
    mutex mut;

    time8 = clock();

    thread th1([&]()
               {
                   mut.lock();

                   c = 1.0;

                   for (int i = 0; i < n/8; i++)
                   {
                       for (int j = 0; j < m/8; j++)
                       {
                           c *= 1.0 / v[i][j];
                       }
                       s += c;
                       c = 1.0;
                   }

                   mut.unlock();
               });

    thread th2([&]()
               {
                   mut.lock();

                   c = 1.0;

                   for (int i = n/8; i < n/4; i++)
                   {
                       for (int j = 0; j < m; j++)
                       {
                           c *= 1.0 / v[i][j];
                       }
                       s += c;
                       c = 1.0;
                   }
                   mut.unlock();
               });
    thread th3([&]()
               {
                   mut.lock();

                   c = 1.0;

                   for (int i = n/4; i < 3*n/8; i++)
                   {
                       for (int j = 0; j < m; j++)
                       {
                           c *= 1.0 / v[i][j];
                       }
                       s += c;
                       c = 1.0;
                   }
                   mut.unlock();
               });
    thread th4([&]()
               {
                   mut.lock();

                   c = 1.0;

                   for (int i = 3*n/8; i < n/2; i++)
                   {
                       for (int j = 0; j < m; j++)
                       {
                           c *= 1.0 / v[i][j];
                       }
                       s += c;
                       c = 1.0;
                   }
                   mut.unlock();
               });
    thread th5([&]()
               {
                   mut.lock();

                   c = 1.0;

                   for (int i = n/2; i < 5*n/8; i++)
                   {
                       for (int j = 0; j < m; j++)
                       {
                           c *= 1.0 / v[i][j];
                       }
                       s += c;
                       c = 1.0;
                   }
                   mut.unlock();
               });
    thread th6([&]()
               {
                   mut.lock();

                   c = 1.0;

                   for (int i = 5*n/8; i < 6*n/8; i++)
                   {
                       for (int j = 0; j < m; j++)
                       {
                           c *= 1.0 / v[i][j];
                       }
                       s += c;
                       c = 1.0;
                   }
                   mut.unlock();
               });
    thread th7([&]()
               {
                   mut.lock();

                   c = 1.0;

                   for (int i = 6*n/8; i < 7*n/8; i++)
                   {
                       for (int j = 0; j < m; j++)
                       {
                           c *= 1.0 / v[i][j];
                       }
                       s += c;
                       c = 1.0;
                   }
                   mut.unlock();
               });
    thread th8([&]()
               {
                   mut.lock();

                   c = 1.0;

                   for (int i = 7*n/8; i < n; i++)
                   {
                       for (int j = 0; j < m; j++)
                       {
                           c *= 1.0 / v[i][j];
                       }
                       s += c;
                       c = 1.0;
                   }
                   mut.unlock();
               });
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();

    time8 = clock() - time8;

    cout << endl << "The sum is: " << s;
    cout << endl << "Seconds: " << static_cast<float>(time8) / CLOCKS_PER_SEC;
}
