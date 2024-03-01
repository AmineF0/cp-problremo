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

void topological_sort(vii& g, vi& vis, vi&a) {
    for (int i = 0; i < g.size(); ++i) {
        if (!vis[i]) {
            dfs(g, vis, a, i);
        }
    }
    reverse(a.begin(), a.end());
}

bool check_cycle(vii& g, vector<int>& tsort)
{
    unordered_map<int, int> pos;
 
    for(int i=0; i<tsort.size(); i++) 
        pos[tsort[i]] = i;

    for (int i = 0; i < g.size(); i++) {
        for (auto it : g[i]) {
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

    vector<set<int>> s(n);
    vii v = vii(n, vi());
    for(int i=0; i<k; i++){
        vi a = readvi(n);
        for(int j=2; j<n; j++) {
            s[a[j-1]-1].insert(a[j]-1);
        }
    }

    for(int i=0; i<n; i++){
        for(auto j : s[i]){
            v[i].push_back(j);
        }
    }

    vi vis(n, 0);
    vi a;
    topological_sort(v, vis, a);

    cout << (check_cycle(v, a)?"NO":"YES") << endl;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int times; cin >> times; 
    for(int oc=0; oc<times; oc++)
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