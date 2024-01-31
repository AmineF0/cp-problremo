#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

template <typename T> bool exist(T& s, int a){
    return s.find(a) != s.end();
}

bool dpf(string& s, int i, int diff, bool& ans){
    if(i>=s.size()) return diff==0;
    if(!ans) return ans;

    if(s[i]=='('){
        return dpf(s, i+1, diff+1, ans);
    } else if(s[i]==')'){
        return dpf(s, i+1, diff-1, ans);
    } else {
        int c ;
        if(diff==0)  c = dpf(s, i+1, diff+1, ans);
        else c = dpf(s, i+1, diff+1, ans) + dpf(s, i+1, diff-1, ans);

        if(c==1) return true;
        if(c==2) ans = false; 
        return false;
    }

}


void solve(){

    string s ; cin >> s;

    int solde=0;

    int open=0;

    bool v = true;

    v = dpf (s, 0, 0, v) & v;

    cout << ((v)?"YES":"NO") << endl;;

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