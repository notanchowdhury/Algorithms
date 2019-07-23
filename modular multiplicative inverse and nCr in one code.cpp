/**

We know, nCr = n! / (r!*(n-r)! )

In this problem , we should output nCr % mod ... ( mod = 1e6+3 )
So, we should pre calculate factorial of i in fact[i], i<=1e6

But the problem is when we need to evaluate this expression (a/b)% mod
Because it is not similar to ( (a%mod)/(b%mod) ) % mod
Thus , to do this we may take help of modular multiplicative inverse.
I we know the  modular multiplicative inverse of b is x then the expression can be
evaluated as (a*x)%mod

**/




#include<bits/stdc++.h>
#define ll long long
#define mx 1000000
const long long  m = 1e6+3;
using namespace std;

//ll gcd(ll a, ll b);

ll power(ll x, unsigned ll y, unsigned ll m);

ll modInverse(ll a, ll m)
{

    return power(a, m-2, m);
}

ll power(ll x, unsigned ll y, unsigned ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}


ll  fact[mx+1];

int main()
{
    fact[0]=1;

    for(ll i=1; i<=mx; i++)
    {
        fact[i]=((fact[i-1]%m)*(i%m))%m;
    }

    ll t,n,r,ans;

    scanf("%lld",&t);
    for(ll ca=1; ca<=t; ca++)
    {
        scanf("%lld%lld",&n,&r);/// find nCr

        ans= ((fact[r]%m)*(fact[n-r]%m))%m;
        ans=modInverse(ans,m);
        ans=((fact[n]%m)*(ans%m))%m;
        printf("Case %lld: %lld\n",ca,ans);
    }
}

