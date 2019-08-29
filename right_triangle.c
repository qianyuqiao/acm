/*
i是直角三角形的最短的那条边，不超过l/3;
已知 i+k+j=l i^2+j^2 = k^2
求得 j = l - l^2 / (2*l-2*i);
i需要比j小（因为不可能出现等腰直角三角形）并且j是整数

*/
#include<iostream>
using namespace std;
int count(int p)
{    
    double l = p;
    int res = 0;
    for (int i = 1; i <= p/3; i++)
    {
        double j = l - (double)l * l / (2*l - 2*i);
        if (i < j && j - (int)j < 1e-6) res++;
    }
    return res;
}
int main()
{
    int p;
    while (cin >> p)
    {
        cout << count(p) << endl;
    }
    return 0;
}
