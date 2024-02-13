#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);


void solve(){
    int n, k; cin >> n >> k;
    ll ans = 0;
    vi v = readvi(n);
    vi flag(n, 0);

    int last_can = -1;
    int dist = 0;
  
    int i=0;
    while(i<n){
      if(!flag[i]) dist++;

      if(v[i]==1){
        last_can = i;
      }
      if(dist>=k || (i==n-1 && flag[i]!=1)) { 
        if(last_can>=0){
          ans++;
          int p=0;
          int j=last_can+1;
          // cout << last_can << " " <<dist << i << endl;

          for(int x=max(0, last_can-k+1); x<min(n, last_can+k); x++){
            flag[x]=1;
          }
          // print(flag);

          i=j-1;
          last_can=-1;
          dist = 0;

        } else {
          // cout << dist << i << endl;
          ans = -1;
          break;
        }
      }

      
      i++;
    }

    bool b = true;
    for(auto i : flag) b &= i;

    // print(flag);

    if(!b) cout << -1 << endl;
    else cout << ans << endl;
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