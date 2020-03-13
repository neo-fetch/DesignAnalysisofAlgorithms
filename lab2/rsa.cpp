#include <iostream>
#include <cstdio>
#include <time.h>
using namespace std;
int primes[10];

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
    srand(time(NULL));
    unsigned long long n, pf,school_strength;
    printf("%s", "primes until\n");
    scanf("%lld", &school_strength);
    printf("Identifying primes: \n");
    int p = 0;
    for (n = 97; n < school_strength; n++)
    {  

        pf = n;

        for (unsigned long long i = 2; i*i <= pf ; i++)
        {
            if (pf % i == 0)
            {
                pf /= i;
            }
        }

        if (pf == n)
        {
            //printf("\n%lld is the prime number.\n", n);
            primes[p] = n; ++p;
        }
    }
    cout<< "primes: "<<endl;
    for (int i = 0; i < p; i++)
    {
        cout<< primes[i]<<"  ";
    }
    cout<<endl;
    int P = primes[ rand() % p ], Q = primes[ rand() % p ];

    cout<< P<<", "<<Q<<endl;

    int N = P*Q;
    int Phi_N = (P-1)*(Q-1);
    int gcd = 0;
    int i = 2;
    while (gcd != 1)
    {
        gcd = euclid(&Phi_N,&i);
        ++i;
    }
    
    cout<< "public key = "<< i <<endl;

}