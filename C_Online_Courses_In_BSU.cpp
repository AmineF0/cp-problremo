#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);


void dfs(vii& g, vi& visited, vi&a, int v) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u])
            dfs(g, visited, a, u);
    }
    a.push_back(v);
}

void topological_sort(vii& g, vi& vis, vi&a, set<int>& m) {
    for(auto i : m) if(!vis[i]) dfs(g, vis, a, i);
    for (int i = 0; i < g.size(); ++i) {
        if (!vis[i]) {
            dfs(g, vis, a, i);
        }
    }
    reverse(a.begin(), a.end());
}

bool check_cycle(vii& g, vector<int>& tsort, set<int>& selected)
{
    unordered_map<int, int> pos;
 
    for(int i=0; i<tsort.size(); i++) 
        pos[tsort[i]] = i;

    for (int i = 0; i < g.size(); i++) {
        for (auto it : g[i]) {
            if(selected.find(it) == selected.end()) continue;
            if (pos[i] > pos[it]) {
                return true;
            }
        }
    }
    return false;
}

void solve(){
    int n, k; cin >> n >> k;
    ll ans = 0;

    set<int> main;
    for(int i=0; i<k; i++) {int j; cin>>j; main.insert(j-1);}

    vii g(n, vi());
    for(int i=0; i<n; i++){
        int h; cin >> h;
        while(h--){
            int a; cin >> a;
            g[i].push_back(a-1);
        }
    }

    vi tsort;
    vi vis(n, 0);
    topological_sort(g, vis, tsort, main);

    reverse(tsort.begin(), tsort.end());
    vi a ;
    set<int> sel;
    for(auto i : tsort){
      if(main.size()==0) break;
      a.push_back(i+1);
      sel.insert(i);
      if(main.find(i) != main.end()) main.erase(i);
    }
    
    reverse(tsort.begin(), tsort.end());
    if(check_cycle(g, tsort, sel)) {
        cout << -1 << endl;
        return;
    }

    cout << a.size() << endl;
    print(a);
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
    for(int i : v) cout << i <<" ";
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