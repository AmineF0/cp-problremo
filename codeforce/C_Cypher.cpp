#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);


void solve(){

    int n; cin >> n;
    
    vector<int> def(n);

    for(int i=0; i<n; i++) cin >> def[i];

    for(int i=0; i<n; i++){
        int a; cin >> a;
        string s; cin >> s;
        for(char c : s){
            if(c=='U') def[i] -= 1;
            else       def[i] += 1;
        }
        cout << ((def[i] % 10)+10)%10 << " ";
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