
#include<iostream>
#include<cstdio>

#define M 5000000

using namespace std;

int phi[M+2];



void calculatePhi()
{
    for(int i=2; i<=M; i++)
        phi[i] = i;

    for(int i =2; i<=M; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<=M; j+=i)
                phi[j]-=phi[j]/i;
        }
    }
}

int main()
{
calculatePhi();
   printf("%d",phi[10]);

    return 0;
}
