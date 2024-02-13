#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);



void solve(){
    int n; cin >> n;

    int s = 1 << 3;
    vector<ll> dp(s , INT_MAX);

    dp[0]=0;

    vector<ll> price(n);
    vector<int> type(n);
    for(int i=0; i<n; i++){
        cin >> price[i];
        string s; cin >> s;
        int t=0;
        for(char c : s) t |= 1 << (c-'A');
        type[i] = t;
        // dp[t] = min(dp[t], price[i]);
    }

    

    

    for(int i=0; i<n; i++){
      for(int j=0; j<s; j++){
        ll a = type[i] | j;
        dp[a] = min(dp[a], dp[j]+price[i]);
        // cout << a << " " <<dp[a] << endl;
      }
    }

    if(dp[(1<<3) -1]==INT_MAX) cout << -1 << endl;
    else cout << dp[(1<<3) -1];

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