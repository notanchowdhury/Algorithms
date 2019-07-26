#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
#define mx 100000
#define inf 1000000000
vector <int > g[mx];
vector <int > cost[mx];
int d[mx]; int par[mx];
struct node {
   int city, dist;
   node (int a, int b) { city = a; dist = b;}
   bool operator < (const node& p) const {
      return p.dist < dist;
   } //its used for priority queue..
};
int dijkstra (int src, int des) {
   for (int i = 0; i < mx; i++) d[i] = inf; //setting distance with a large value..
   memset (par, -1, sizeof (par));
   priority_queue <node > q;
   d[src] = 0;
   q.push (node(src, 0));
   while (!q.empty()) {
      node top = q.top(); q.pop();
      int u = top.city;
      if (u == des) return d[u];
      for (int i = 0; i < g[u].size(); i++) {
         int v = g[u][i];
         if (d[u] + cost[u][i] < d[v]) {
            d[v] = d[u] + cost[u][i];
            par[v] = u;
            q.push (node (v, d[v]));
         }
      }
   }
   return -1;
}
int main ()
{
   int n, e;
   cin >> n >> e;
   for (int i = 0; i < e; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].push_back (v);
      g[v].push_back (u);
      cost[u].push_back (w);
      cost[v].push_back (w);
   }
   int ret = dijkstra (1, n);
   if (ret == -1) cout << "No path\n";
   else {
      //cout << ret << endl;
      int u = n;
      vector <int > out;
      while (u != -1) {
         out.push_back (u);
         u = par[u];
      }
      reverse (out.begin(), out.end());
      for (int i = 0; i < (int ) out.size(); i++) {
         cout << out[i] << " ";
      }
      cout << endl;
   }
   for (int i = 0; i < mx; i++) {g[i].clear(); cost[i].clear();}
   return 0;
}
