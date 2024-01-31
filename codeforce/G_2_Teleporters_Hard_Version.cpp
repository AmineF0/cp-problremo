#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);



inline void solve(){
    int n, c; cin >> n>> c;
    vi v = readvi(n);
    
    vector<pair<ull,int>> vcost(n, {0,0});

    for(int i=0; i<n; i++){
        vcost[i] = {min(i+1+v[i], n-i+v[i]), i};
    }

    sort(vcost.begin(), vcost.end());
    
    int tel = 0;
    int cuc = 0;
    int i=0;

    for(; i<n && cuc+vcost[i].first<=c; i++){
        cuc += vcost[i].first;
        tel++;
    }

    int mx = 0;

    for(int k=0; k<n ; k++){
        int l= tel+1;
        int cl = cuc + k+1+v[k];
        if(k<=i) cl -= vcost[k].first;

        int f=i;
        for(; f>=0 && cl+vcost[f].first>c; f--){
            cl -= vcost[f].first;
            l--;
        }

        mx = max(l, mx);
    }

    cout << mx << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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