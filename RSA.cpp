/****
 * #Problem: Implement the RSA Algorithm
 * 
 * @Author: MuhammadYousufAli
 * @Since: 23th March 2021
 */
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

long long multiply(int base, int power, int moduler)
{
    long long result = 1;
    for(int i = 1; i<= power; i++)
    {
        result = result * base;
        result = result % moduler;
    }
    return result;
}
 
bool isPrime(long long n)
{
    bool flag = false;
    for(int i = 2; i<n ;i++){
        if(n % i == 0){
            flag = true;
        }
    }
    if(flag == false){
        return true;
    }
    else{
        return false;
    }
}
 
int main()
{
    long long p,q, c,d, e,m, n ,fi_n;
    cout<<"Enter First Prime Number Here, P: ";
    cin>>p;

    cout<<"Enter Second Prime Number, Q: ";
    cin>>q;

    // p = 3;
    // q = 11;

    if(isPrime(p) == true && isPrime(q) == true){
        cout<<"Enter Value of, e: ";
        cin>>e;
        // e = 3;
        n = (p * q);
        fi_n = (p - 1) *(q - 1);
        cout<<"Enter Value of, M: ";
        cin>>m;
        if(m < n && 1<e && e<fi_n && __gcd(e, fi_n) == 1 ){
            
            // c = (long long) pow(m, e) % n;
            c = multiply(m, e, n);
            cout<<"Encrypted Value: "<<c<<endl;
            cout<<"Public Key: ["<<e<<", "<<n<<"]\n";

            int i = 0;
            while (true)
            {
                i++;
                if(e*i % fi_n == 1){
                    d = i;
                    break;
                }
            }

            // m = (long long) pow(c, d) % n;
            m = multiply(c, d, n);
            cout<<"\nPrivate Key: ["<<d<<", "<<n<<"]\n";
            cout<<"Decrypted Value: "<<m<<endl;
        }
        else{
            cout<<"RSA Operation Not Possible..!"<<endl;
        }
    }
    else{
        cout<<"The Number Have to be Prime Number...!"<<endl;
    }

    return 0;
}