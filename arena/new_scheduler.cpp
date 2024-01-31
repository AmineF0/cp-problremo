#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);



void solve(){
    int n,cores; cin >> n >> cores;
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    for(int i=0; i<n; i++){
      int a, b; cin >> a >> b;
      pq.push({b, a}); // end , start  
    }

    int cur = cores;
    int t=0;
    while(!pq.empty()){
      pair<int, int> p = pq.top(); pq.pop();
      
      if(p.second>t) cur = cores, t = p.second; // change mmt of process
      // cout << p.first << " " << p.second << "\t" << t << cur << endl;
      if(cur>0)
        cur--; // process
      else {
        if(p.first<=p.second) { // impossible to delay => stop
          cout << "No" << endl;
          return;
        } else { // delay
          pq.push({p.first, p.second+1});
        }

      }
    }

    cout << "Yes" << endl;
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