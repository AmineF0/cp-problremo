#include <bits/stdc++.h>
using namespace std;

int can_jump(pair<int,int>& a, pair<int,int>& b, int N){
  int x = abs(a.first - b.first);
  int y = abs(a.second - b.second);

  if(x*x+y*y <= N*N) return 1;
  return 0;
}

void solve(){
  int L, N, M; cin >> L >> N >> M;
  vector<pair<int,int>> v(M);

  for(int i=0; i<M; i++){
    int a, b; cin >> a >> b;
    v[i] = {a,b};
  }

  for(int i=0; i<L; i++){
    v.push_back({i, 0});
    v.push_back({i, L});
  }

  vector<vector<int>> g(v.size(), vector<int>());

  for(int i=0; i<v.size(); i++){
    for(int j=0; j<v.size(); j++){
      if(i!=j){
        if(can_jump(v[i], v[j], N)){
          // cout << v[i].first << " " << v[i].second << " " << v[j].first << " " << v[j].second << endl;
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
    }
  }

  vector<int> visited(v.size(), 0);
  queue<int> q;
  for(int i=0; i<v.size(); i++){
    if(v[i].second == 0){
      q.push(i);
      visited[i] = 1;
    }
  }
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(int i=0; i<g[u].size(); i++){
      int v = g[u][i];
      if(!visited[v]){
        visited[v] = 1;
        q.push(v);
      }
    }
  }



  for(int i=0; i<v.size(); i++){
    if(v[i].second == L && visited[i]){
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;

}

int main (){
  int t ; cin >> t;

  while(t--) solve();

  return 0;
}