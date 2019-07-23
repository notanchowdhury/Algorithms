#include<iostream>
#include<math.h>
#define mx 100001
using namespace std;
int arr[mx];
int tree[mx * 3];
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = min(tree[Left],tree[Right]);
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
            if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return min(p1,p2);
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return ;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = min(tree[Left] , tree[Right]);
}
int main()
{

    int n,q,t,kk,jj;
    cin>>t;
    for(int f=1;f<=t;f++){
    cin >> n>>q;

   for(int i=1;i<=n;i++)
            cin>> arr[i];
    init(1, 1, n);
    for(int j=1;j<=q;j++)
    {
        cin>>jj>>kk;
        cout << query(1, 1, n, jj, kk) << endl;
    }


    }
    return 0;
}
