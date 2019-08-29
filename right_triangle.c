#include<iostream>
using namespace std;
int count(int p)
{    
    double l = p;
    int res = 0;
    for (int i = 1; i <=p/3; i++)
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
