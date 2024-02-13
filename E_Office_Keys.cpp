#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);

ll n,k,p; 
vector<ll> pos, keys;

ll dpf(vector<vector<ll>>& dp, int i, int j){
    if(i==n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll ans = 0;

    ll put = 
        max(abs(p-keys[j])+abs(keys[j]-pos[i])
        , dpf(dp, i+1, j+1));
    ll skip = LONG_MAX;
    

    if(n-i <= k-j-1)
      skip = dpf(dp, i, j+1);

    // cout << i << j << put << skip << endl;
    

    return dp[i][j] = min(put, skip);
}

void solve(){
    cin >> n >> k >> p;
    pos= vector<ll>(n);
    keys= vector<ll>(k);

    for(int i=0; i<n; i++) cin >> pos[i];
    for(int i=0; i<k; i++) cin >> keys[i];
    
    sort(pos.begin(), pos.end());
    sort(keys.begin(), keys.end());

    vector<vector<ll>> dp(n, vector<ll>(k, -1));
    cout << dpf(dp, 0, 0);
     


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