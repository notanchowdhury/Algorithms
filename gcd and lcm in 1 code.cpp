
// C program to find LCM of two numbers
#include <stdio.h>

// Recursive function to return gcd of a and b
#define ll long long
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

// Function to return LCM of two numbers
ll int lcm(ll int a,ll int b)
{
    return (a*b)/gcd(a, b);
}

// Driver program to test above function
int main()
{
   ll int a = 37336952340, b = 216;
    printf("LCM of %lld and %lld is %lld ", a, b, lcm(a, b));
    return 0;
}
