#include <bits/stdc++.h>
using namespace std;

void traverse(vector<vector<int>>& g, vector<int>& clusters, int u, int c){
  clusters[u] = c;
  for(int i=0; i<g[u].size(); i++){
    int v = g[u][i];
    if(clusters[v]==-1){
      traverse(g, clusters, v, c);
    }
  }

}

int main(){
  int n, m; cin >> n >> m;

  vector<int> v(n);

  for(int i=0; i<n; i++){
    cin >> v[i];
  }

  vector<vector<int>> g(n, vector<int>());
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> clusters(n, -1);
  int c = 0;
  for(int i=0; i<n; i++){
    if(clusters[i]==-1){
      traverse(g, clusters, i, c);
      c++;
    }
  }

  vector<vector<int>> clusters_v(c, vector<int>());
  for(int i=0; i<n; i++){
    clusters_v[clusters[i]].push_back(v[i]);
  }

  for(int i=0; i<c; i++){
    sort(clusters_v[i].begin(), clusters_v[i].end());
  }

  long long t = 0;
  for(int i=0; i<c; i++){
    for(int j=0; j<clusters_v[i].size()-1; j+=2){
      if(clusters_v[i][j] > 0) break;
      if(clusters_v[i][j+1] > -clusters_v[i][j]) break;
      clusters_v[i][j] = -1*clusters_v[i][j];
      clusters_v[i][j+1] = -1*clusters_v[i][j+1];
    }
    for(int j=0; j<clusters_v[i].size(); j++){
      t += clusters_v[i][j];
    }
  }
  cout << t << endl;


  return 0;
}