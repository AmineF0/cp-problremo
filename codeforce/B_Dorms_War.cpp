#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef string S;

typedef vector<int> vi;
typedef vector<vi> vii;

typedef vector<ll> vl;
typedef vector<vl> vll;

typedef map<int,int> mii;
typedef map<int,S> mis;
typedef map<S,int> msi;

typedef set<int> si;
typedef set<S> ss;

vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);

int main(){

    int times; cin >> times; 

    for(int i=0; i<times; i++){
        int n, f, mx=0; string s; cin >> n >> s >> f;
        set<int> st;

        for(int i=0; i<f; i++) {
            char j; cin >> j;
            st.insert(j);
        }
        f=0;
        
        for(int i=0; i<n-1; i++){
            if(st.find(s[i+1]) != st.end()){
                mx=max(f+1, mx);
                f=0;
            }
            else f++;
        }
        
        cout << mx << endl;

    }



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

void print(vi v){
    for(int i : v) cout << i <<"";
    cout << endl;
}