#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

inline int getval(char c){
    return c-'a'+1;
}

void solve(){
    string s ; cin >> s;
    int p; cin >> p;

    set<int> removed;

    int val=0;
    vector<stack<int>> v(30, stack<int>());
    
    for(int i=0; i<s.size(); i++){
        v[getval(s[i])].push(i);
        val += getval(s[i]);
    }

    int i = 26;
    while(val > p){
        while(v[i].empty()) i--;
        if(i==-1)break;

        val -= i;

        int f = v[i].top(); v[i].pop();
        removed.insert(f);
    }
;
    for(int i=0; i<s.size(); i++) 
        if(removed.find(i)==removed.end()) 
            cout << s[i];

    cout <<endl;

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