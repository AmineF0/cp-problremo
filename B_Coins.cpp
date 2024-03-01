#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);

bool dfs(vii& g, vi& vis, vi&a, int v) {
    vis[v] = 1;
    for (int u : g[v]) {
        if(vis[u] == 1) return true;
        if (!vis[u]){
            bool cycle = dfs(g, vis, a, u);
            if(cycle) return true;    
        }
    }
    vis[v] = 2; // [v]isited
    a.push_back(v);
    return false;
}

bool topological_sort(vii& g, vi& vis, vi&a) {
    for (int i = 0; i < g.size(); ++i) {
        if (!vis[i]) {
            bool f = dfs(g, vis, a, i);
            if(f) return false;
        }
    }
    return true;
    // reverse(a.begin(), a.end());
}

void solve(){
    string s1;

    vii g(3, vi());

    for(int i=0; i<3; i++){
      cin >> s1;
        if(s1[1] == '>') 
          g[s1[0]-'A'].push_back(s1[2]-'A');
        else 
          g[s1[2]-'A'].push_back(s1[0]-'A');
    }

    // for(int i=0; i<3; i++){
    //   cout << i << " : ";
    //   for(auto j : g[i]) cout << j << " ";
    //   cout << endl;
    // }

    vi vis(3, 0);
    vi a;
    bool d = topological_sort(g, vis, a);
    if(!d) {
      cout << "Impossible" << endl;
      return;
    }
    else for(auto i : a) cout << (char)(i+'A');
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