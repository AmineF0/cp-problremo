#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

int main(){

    int times; cin >> times; 

    for(int oc=0; oc<times; oc++){
        int n; cin >> n;
        vi a = readvi(n), b=readvi(n);

        vi c(n);

        for(int i=0; i<n; i++) c[i] = a[i] - b[i];

        int op= maxvi(c);
        bool valid = true;

        for(int i=0; i<n && valid; i++){
            if(c[i]<0) valid = false;

            if(c[i] < op) {
                if(b[i]!=0) valid = false;
            } 

        }


        cout << (valid?"YES":"NO")<< endl;
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