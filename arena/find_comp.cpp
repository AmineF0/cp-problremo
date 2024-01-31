#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);

vector<vector<int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(vector<string>& v, int i, int j, int n , int m, ii source, vector<vector<ii>>& comp, map<ii, int>& mp){
  if(comp[i][j].first!=-1) return;
  queue<ii> q;
  q.push({i, j});
  comp[i][j]=source;
  int cnt=0;
  while(!q.empty()){
    ii p = q.front(); q.pop();
    i = p.first; j = p.second;
    cnt++;
    for(auto dir : adj){
      if(i+dir[0]<0 || i+dir[0]>=n || j+dir[1]<0 || j+dir[1]>=m) continue;
      int x = i+dir[0], y = j+dir[1];
      if(comp[x][y].first!=-1) continue;
      if(v[x][y]=='.') q.push({x, y}), comp[x][y]=source;
    }
  }
  mp[source]=cnt;
}


void solve(){
    int n, m; cin >> n >> m;
    vector<string> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    vector<vector<ii>> comp(n, vector<ii>(m, {-1, -1}));
    map<ii, int> mp;

    vii vis(n, vi(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          if(v[i][j]=='.') 
            bfs(v, i, j, n, m, {i,j}, comp, mp);
        }
    }

    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(v[i][j]=='?'){
          set<ii> s;
          for(auto dir : adj){
            if(i+dir[0]<0 || i+dir[0]>=n || j+dir[1]<0 || j+dir[1]>=m) continue;
            int x = i+dir[0], y = j+dir[1];
            if(v[x][y]=='.') s.insert(comp[x][y]);
          }
          int cnt=0;
          for(auto i : s) cnt+=mp[i];
          cout << cnt+1 << endl;
        }
      }
    }



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