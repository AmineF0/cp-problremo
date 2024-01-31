#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

template <typename T> bool exist(T& s, int a){
    return s.find(a) != s.end();
}


void solve(){

    

    int n , m ; cin >> n >> m;

    vi v = readvi(n);
    vector<ull> vs (n,0);
    vector<ull> ve (n,0);

    for(int i=1; i<n; i++){
        vs[i] = vs[i-1] + max(0, v[i-1]-v[i] );
    }
    for(int i=n-2; i>=0; i--){
        ve[i] = ve[i+1] + max(0, v[i+1]-v[i] );
    }

    for(int c=0; c<m; c++){
        
        int i,j; cin >> i >> j;
        i=i-1;j=j-1;
        int cost=0;
        if(i>j){        
            cout << (ve[j]-ve[i]);
        }
        else {
            cout << (vs[j]-vs[i]);
        }
        


        cout << endl;





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
    for(int i : v) cout << i <<" ";
    cout << endl;
}

ll fact(int n){
    int prod=1;
    for(int i=1; i<=n; i++) prod*=i;
    return prod;
}