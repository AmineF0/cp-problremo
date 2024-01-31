#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

bool exist(set<ull>& s, ull a){
    return s.find(a) != s.end();
}

ull hashstr(string s){
    ull hash = 0;
    ull p=1;
    for(int i=0; i<s.size(); i++){
        hash = (s[i]-'a'+1) + hash<<6;
    }
    return hash;
}

void solve(){

    int n; cin >> n;

    vector<ull> v(n, 0);

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        v[i] = hashstr(s);
    }

    set<ull> sv(v.begin(), v.end());

    for(int i=0; i<n; i++){
        bool f = false;
        for(int i=1; 1<<(i*6)<v[i]; i++){
            ull a = v[i]>>(i*6);
            ull b = (a<<(i*6)) - v[i];
            cout << a << " " << b;
            if(exist(sv, a) && exist(sv, b)) {f=true;break;}
        }
        cout << (f?1:0);
    }



    cout << endl;
}





int main(){
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

ll fact(int n){
    int prod=1;
    for(int i=1; i<=n; i++) prod*=i;
    return prod;
}