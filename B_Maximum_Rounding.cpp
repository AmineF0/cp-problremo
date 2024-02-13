#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);



void solve(){
    string s; cin >> s;
    vi v(s.size()+1, 0);


    int to_analyse = v.size();
    bool r=true;
    for(int i=0; i<s.size(); i++){
      v[i+1] = s[i]-'0';
      if(s[i]>='5') {to_analyse=i+2;r=false;
      break;}
    }

    vi ans = v;

    int c = 0;
    int a = to_analyse;
    if(!r)
{      for(int i=to_analyse-1; i>=0; i--){
        if(v[i]+c>=5){
          v[i]=0;
          c=1;
          a=i;
        } else {
          v[i]+=c;
          ans = v;
          c=0;
        }
      }

    if(v[0]) cout << v[0];
    for(int i=1; i<v.size(); i++){
      if(a<i) cout << 0;
      else 
      cout << v[i];
    }
    cout << endl;} 
    else cout << s << endl;
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