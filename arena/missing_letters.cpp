#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);

inline bool isFreqEqualx(vector<int>& freq, int x, int a){
    for(int i=0; i<26; i++) {
      if(freq[i] > x) return false;
      a -= (x-freq[i]);
      if(a<0) return false;
    }
    return true;
}

void solve(){
    int x; cin >> x;
    S s; cin >> s;

    vector<int> freq(26, 0);

    int i=0, j=0;
    bool f = false;
    int a=0;

    while(j<s.size()){
      if(s[j]=='?'){
        a++;
        j++;
      }
      else if(freq[s[j]-'a'] < x){
        freq[s[j]-'a']++;
        j++;
      }
      else if(s[i]=='?'){
        a--;
        i++;
      } 
      else if(freq[s[i]-'a'] >= x || freq[s[j]-'a'] >= x){
        freq[s[i]-'a']--;
        i++;
      }
      if(isFreqEqualx(freq, x, a)){
        f = true;
      }
    }


    if(f) cout << "YES";
    else cout << "NO";
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