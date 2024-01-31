#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

typedef struct st{
    int mn, mx;
    st(){}
    st(int a){mn=a;mx=a;}
} st;

void solve(){

    int n, k; cin >> n >> k;
    vi v= readvi(n);
    map<int,st> m;

    for(int i=0; i<v.size(); i++){
        if(m.find(v[i]) == m.end()){
            m[v[i]] = st(i);
        } else {
            m[v[i]].mx = i;
        }
    }

    while(k--){
        int a, b; cin >> a >> b;
        
        if(m.find(a) == m.end() || m.find(b) == m.end()) {
            cout << "NO\n"; continue;
        }

        int ai = m[a].mn;
        int bi = m[b].mx;



        if(ai<=bi) cout << "YES\n"; else cout << "NO\n";
    }







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