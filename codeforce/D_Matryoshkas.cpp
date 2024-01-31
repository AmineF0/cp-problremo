#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

template <typename T> bool exist(T& s, int a){
    return s.find(a) != s.end();
}

double diff(double t, double d){
    double a = t;
    double b = d-t;
    return (a+b) - a*b;
}

void solve(){
    int ans=0;
    int n; cin >> n;
    map<int,int> occ;

    for(int i=0; i<n; i++){
        int g; cin >> g;
        occ[g]++;
    }

    ii prev = {-1,0};
    for(auto i : occ){
        //cout << i.first<<" " << i.second << endl;
        if(prev.first+1== i.first) {
            ans += max(0, i.second-prev.second);
        } else {
            ans += i.second;
        }
        prev=i;
    }

    cout << ans << endl;
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