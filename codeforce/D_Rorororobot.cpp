#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

template <typename T> bool exist(T& s, int a){
    return s.find(a) != s.end();
}


void solve(){

    ull n,m; cin >> n >> m;

    vector<ull> v (m);
    for(int i=0; i<m; i++) cin >> v[i];

    int c; cin >> c;

    while(c--){
        bool f= true;
        int ai,aj,bi,bj,k; cin >> ai >> aj >> bi >> bj >> k;

        if((bj-aj) % k != 0 || (bi-ai) % k != 0){
            f = false;
        } else {
            ull mx=0;
            for(int i=aj-1; i<bj; i++){
                mx = max(mx, v[i]);
            }


            ull nit = (n-ai)/k;

            ull obj = ai+k*nit;
            f = obj>mx;

        }



        cout << ((f)?"YES":"NO")<< endl;
    }


    cout << endl;
}





int main(){
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