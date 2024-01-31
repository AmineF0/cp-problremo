#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);

long long calcZeros(vector<int> v){
    vector<int> q(v.size(), 0);
    q[v.size()-1] = (v[v.size()-1]==0);
    for(int j=v.size()-2; j>=0; j--)
      q[j] = q[j+1] + (v[j]==0);

    long long ans = 0;
    //print(q);
    for(int j=0; j<v.size(); j++){
      if(v[j]==1) ans += q[j];
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    long long mx = 0;

    long long ans= calcZeros(v);
    mx = max(mx, ans);

    vector<int> v2 = v;
    for(int i=0; i<n ; i++){
      if(v2[i]==0) {v2[i]=1;break;}
    }

    ans = calcZeros(v2);
    mx = max(mx, ans);

    v2 = v;
    for(int i=n-1; i>=0 ; i--){
      if(v2[i]==1) {v2[i]=0;break;}
    }

    ans = calcZeros(v2);
    mx = max(mx, ans);

    cout << mx <<endl;
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