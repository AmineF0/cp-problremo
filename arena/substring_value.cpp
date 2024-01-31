#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<ll> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);

inline ll dp(S& s, vector<vi>& v, vector<int>& m, int i, int state, int c){
    if(i==v.size()) return 0;
    if(v[i][c*30+state] != -1) return v[i][c*30+state];

    ll ans = 0;
    
    if(state == 2 ){
      ans = max(ans, dp(s, v, m, i+1, 2, c));
      ans = max(ans, dp(s, v, m, i+1, 1, c));
    }
    else if(state == 1){
      ll cost = m[s[i]-'a'] * (c==s[i]-'a' ? 1 : -1);
      ans = max(ans, dp(s, v, m, i+1, 1, c) + cost);
    }
    return v[i][c*30+state] = ans;
}

void solve(){

    S s; cin >> s;
    
    int n = s.size();
    vector<int> m(26,0);
    vector<vi> v(n+1, vi(26*2+2, 0));

    for(int i=0; i<26; i++){
      int x; cin >> x;
      m[i] = x;
    }

    ll ans = 0;
    for(int j=0; j<26; j++){
      for(int i=0; i<n; i++){
        ll cost = m[s[i]-'a'] * (j==s[i]-'a' ? 1 : -1);
        v[i+1][j*2+1] = max(v[i][j*2+1] + cost, cost);
        v[i+1][j*2+0] = max(v[i][j*2], v[i][j*2+1]);
        ans = max(ans, max(v[i+1][j*2+1], v[i+1][j*2]));
      }
    }

    cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}