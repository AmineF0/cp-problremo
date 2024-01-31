#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);


unsigned long long mod = 998244353;

ull sto(string& s){
  ull p=1;
  ull ans=0;
  for(int i=s.size()-1; i>=0;i--){
    ans = (ans%mod + ((s[i]-'0')*p)%mod)%mod;
    p*=10;
    p%mod;
  }
  return ans;
}

unsigned long long findans(string a, string b){

  unsigned long long n1=sto(a)%mod, n2=sto(b)%mod;
  return (n1*n2)%mod;
}

unsigned long long prod(string a, int f, int i, vector<ull>& mult){
  unsigned long long n1=sto(a)%mod, n2=(f*mult[i])%mod;
  return (n1*n2)%mod;
}

void solve(){
    int n; cin >> n;


    string a,b; cin >> a >> b;
    vector<ull> v(n, 0);

    unsigned long long p=1;

    for(int i=n-1; i>=0; i--) {
      v[i]=p;
      p*=10;
      p%=mod;
    }
    
    vector<pair<char, int>> qp; 
    vector<pair<char, int>> qd;

    for(int i=0; i<n; i++){
      qp.push_back({a[i], i});
      qd.push_back({b[i], i});
    } 

    sort(qp.begin(), qp.end());
    sort(qd.begin(), qd.end());

    for(int i=0; i<n; i++){
      int s=qp[i].second, f=qd[i].second;
      if(s>f || a[s]>a[f]) {
          char tmp = a[s];
          a[s]=b[f];
          b[f]=tmp;
      }
    }

    cout << findans(a, b) << endl;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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