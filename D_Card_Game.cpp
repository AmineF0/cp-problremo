#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);


void solve(){
    int n; cin >> n;
    string s ; cin >> s;
    ll ans = 0;

    map<char, int> m;
    map<char, vector<string>> occ;
    for(int i=0; i<2*n; i++){
      string c; cin >> c;
      m[c[1]]++;
      occ[c[1]].push_back(c);
    }

    ll trump = m[s[0]];
    ll permit = trump;
    bool dec = true;
    for(auto [k, v] : m){
      if(k==s[0]){
        continue;
      } else {
        if(v%2==0) continue;
        else permit--;
      }
    }
    dec = permit>=0 && permit%2==0;
    if(!dec) cout << "IMPOSSIBLE" << endl;
    else {
      queue<string> left_over;
      for(auto [k, v] : occ){
        if(k==s[0])continue;
        sort(v.begin(), v.end());
        for(int i=1; i<v.size(); i+=2){
          cout << v[i-1] <<" " << v[i] << endl;
        }
        if(v.size()%2==1) left_over.push(v[v.size()-1]);
      }
      priority_queue<string> q(occ[s[0]].begin(), occ[s[0]].end());
      while(!left_over.empty()){
        string a=left_over.front(), b=q.top();
        left_over.pop(); q.pop();
        cout << a << " " << b << endl; 
      }
      while(!q.empty()){
        string a=q.top(); q.pop();
        string b=q.top(); q.pop();
        cout << b << " " << a << endl; 
      }
    }

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