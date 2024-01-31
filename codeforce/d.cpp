#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

template <typename T> bool exist(T& s, int a){
    return s.find(a) != s.end();
}

ll dpf(vector<vector<ll>>& dp, vector<int>& a, vector<int>&b , int i, int consecutive){
    if(i>=a.size()) return 0;
    if(dp[i][consecutive] != -1) return dp[i][consecutive];

    if(consecutive==3) {
        return dp[i][consecutive] = dpf(dp, a, b, i+1, 0);
    }
    ll take =  a[i]*b[i] + dpf(dp, a, b, i+1, consecutive+1);
    ll leave = dpf(dp, a, b, i+1, 0);

    return dp[i][consecutive] = max(take, leave);
}


void solve(){

    int n; cin >> n;

    vi a = readvi(n);
    vi b = readvi(n);

    vector<vector<ll>> dp(n , vector<ll>(4,-1));


    cout << dpf(dp, a, b, 0, 0);
    cout << endl;
}





int main(){
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

ll fact(int n){
    int prod=1;
    for(int i=1; i<=n; i++) prod*=i;
    return prod;
}