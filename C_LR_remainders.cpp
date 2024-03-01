#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);

int m = 1;

struct SegTree{
    vector<ll> st;
    SegTree(int n) {
        st.assign(4*n, 0);   
    }

    SegTree(vi& a) {
        st.assign(4*a.size(), 0);
        build(a, 1, 0, a.size()-1);
    }

    void build(vi& a, int v, int tl, int tr) {
        if (tl == tr) {
            st[v] = a[tl]%m;
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            st[v] = (st[v*2] * st[v*2+1])%m;
        }
    }

    ll sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 1;
        if (l == tl && r == tr) {
            return st[v];
        }
        int tm = (tl + tr) / 2;
        return (sum(v*2, tl, tm, l, min(r, tm))
            * sum(v*2+1, tm+1, tr, max(l, tm+1), r))%m;
    }
};


void solve(){
    int n; cin >> n>>m;
    ll ans = 0;

    vi v = readvi(n);
    string s; cin >> s;

    
    SegTree seg = SegTree(v);

    int i=0, j=n-1;

    for(auto c : s){
      cout << seg.sum(1,0,n-1,i, j)%m << " ";
      if(c=='L'){
        i++;
      } else {
        j--;
      }
    }



    cout << endl;
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