#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>>& adj, vector<int>& dp ,vector<int>& w, int i, int sum=0){
  sum += w[i];
  dp[i] = max(dp[i], sum);
  for(int j = 0; j < adj[i].size(); j++){    
    backtrack(adj, dp, w, adj[i][j], sum);
  }
}

void solve(){
  int N, M; cin >> N >> M;

  vector<vector<int>> adj(M);
  vector<int> weight(M, 0);

  vector<bool> isRoot(M, true);

  for(int i = 0; i < N; i++){
    int a, b; cin >> a >> b;
    adj[b].push_back(a);
    isRoot[a] = false;
  }

  for(int i = 0; i < M; i++){
    int w; cin >> w;
    weight[i] = w;
  }

  vector<int> dp(M, 0);

  for(int i = 0; i < M; i++){
    if(isRoot[i]){
      backtrack(adj, dp, weight, i);
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << endl;

}

int main(){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}