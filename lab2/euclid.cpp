#include <iostream>

using namespace std;
int euclid(int* a, int* b)
{
    if (*b != 0)
    {
        int c = (*a)%(*b);
        euclid(b, &c);
    }
    else
    return (*a);
}
int main(int argc, char const *argv[])
{
    int a = 16, b = 12;

    int d = euclid(&a, &b);
    cout<< d << " is the gcd"<<endl;
}
