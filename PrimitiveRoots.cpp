/****
 * @Problem: Primitive Roots Calculation
 * @Author: MuhammadYousufAli
 * @Since: 20th March 2021
 */
#include <iostream>
#include <math.h>
using namespace std;

long long multiply(int base, int power, int moduler)
{
    long long result = 1;
    for (int i = 1; i <= power; i++)
    {
        result = result * base;
        result = result % moduler;
    }
    return result;
}

bool isPrime(long long n)
{
    bool flag = false;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            flag = true;
        }
    }
    if(flag == false)
        return true;
    else
        return false;
}

int main()
{
    int p, a;
    cout << "Enter A Prime Number Here: ";
    cin >> p;
    if (isPrime(p))
    {
        a = 1;
        while (a != p)
        {
            printf("For %d Roots: ", a);
            for (int i = 1; i < p; i++)
            {
                // long long int q = (long long int)pow(a, i) % p;
                long long q = multiply(a, i, p);
                if (q == 1)
                {
                    cout << q << " ";
                    break;
                }
                else
                {
                    cout << q << " ";
                }
                q = 0;
            }
            a++;

            cout << endl;
        }
    }
    else
    {
        cout<<"Your Number Must Be Prime Numner...!"<<endl;
    }

    return 0;
}
