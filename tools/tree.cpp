#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

pair<int, int> diameter(vvi &g, int v, int p)
{
  int dimm = 0;
  int maxHeight[3] = {-1, -1, -1};

  for (int u : g[v])
  {
    if (u == p)
      continue;
    pair<int, int> m = diameter(g, u, v);
    int d = m.first;
    int h = m.second;
    dimm = max(dimm, d);
    maxHeight[0] = h+1;
    sort(maxHeight, maxHeight + 3);
  }

  for(int i=0; i<3; i++){
    if(maxHeight[i]<0) maxHeight[i]=0;
  }

  dimm = max(dimm, maxHeight[1] + maxHeight[2]);

  return {dimm, maxHeight[2]};
}