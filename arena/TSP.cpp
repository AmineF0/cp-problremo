#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);

#define INF 100000000

int dpf(vii& dp, vii& adj, int i, int vis, int n){
  if(dp[vis][i] != INF) return dp[vis][i];
  
  int ans = INF;
  for(int j=0; j<n; j++){
    if(vis & (1<<j) && ) continue;
    ans = min(ans,
      dpf(dp, adj, j, vis ^ (1<<j), n) + adj[i][j]
    );
  }
  cout << i << " " << vis << " " << ans << endl;
  return dp[vis][i] = ans;
}

void solve(){
    int n, m; cin >> n >> m;

    vii adj(n, vi(n, 0));
    for(int i=0; i<m; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a-1][b-1] = w;
        adj[b-1][a-1] = w;
    }

    vii dp(1<<(n+1), vi(n, INF));

    for(int i=0; i<n; i++) dp[1<<i][i] = 0;

    
    int ans = INF;
    for(int i=0; i<n; i++){
      ans = min(ans, dpf(dp, adj, i, 1<<i, n)) + adj[1][i];
    }

    for(int i=0; i<(1<<n); i++){
      for(int j=0; j<n; j++){
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }

    cout << dp[1<<2-1][0];


    cout << endl;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // int times; cin >> times; 
    // for(int oc=0; oc<times; oc++)
        solve();
    return 0;
}












vi readvi(int n){
    vi v(n);
    for(int i=0;i <n; i++) cin >> v[i];
    return v;
}

int maxvi(vi v){
    int mx = v[0];
    for(auto i : v) mx = max(mx, i);
    return mx;
}

int minvi(vi v){
    int mx = v[0];
    for(auto i : v) mx = min(mx, i);
    return mx;
}

void print(vii v){
    for(vi vv : v) print(vv);
}

void print(vi v){
    for(int i : v) cout << i <<"";
    cout << endl;
}

ull binpow(ull a, ull b) {
    ull res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll fact(int n){
    int prod=1;
    for(int i=1; i<=n; i++) prod*=i;
    return prod;
}

template <typename T> bool exist(T& s, int a){
    return s.find(a) != s.end();
}