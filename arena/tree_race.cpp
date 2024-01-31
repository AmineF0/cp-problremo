#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);

inline pair<int, int> bfs(vii& adj, int start, vi& fv){
  // return end point and distance
  queue<ii> q;
  q.push({start, 0});
  vi visited(adj.size(), 0);
  visited[start] = 1;
  fv[start] = 1;
  pair<int , int> ans = {start, 0};

  while(!q.empty()){
    ii cur = q.front(); q.pop();
    for(int i : adj[cur.first]){
      if(!visited[i]){
        visited[i] = 1;
        fv[i] = 1;
        q.push({i, cur.second + 1});
        if(cur.second + 1 > ans.second) ans = {i, cur.second + 1};
      }
    }
  }
  return ans;
}

void solve(){
    int n; cin >> n;
    vi a = readvi(n-1);
    vi b = readvi(n-1);

    vii adj(n, vi());

    for(int i=0; i<n-1; i++){
      if(a[i] == b[i]) {
        adj[i+1].push_back(a[i]-1);
        adj[a[i]-1].push_back(i+1);
      }
      else {
        int pnt = a[i]-1;
        int ind = pnt - 1;
        if(b[ind] - 1== i + 1){
          adj[i+1].push_back(pnt);
          adj[pnt].push_back(i+1);
        }
      }
    }

    int mx = 0;
    vector<int> fv(n, 0);
    for(int i=0; i<n; i++){
      if(fv[i]) continue;
      pair<int, int> ans = bfs(adj, i, fv);
      pair<int, int> diam = bfs(adj, ans.first, fv);

      // cout << " " << diam.second << endl;
      mx = max(mx, diam.second);
    }

    cout << mx << endl;
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