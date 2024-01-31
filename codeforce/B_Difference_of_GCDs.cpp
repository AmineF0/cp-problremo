#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

template <typename T> bool exist(T& s, int a){
    return s.find(a) != s.end();
}

int gcdf(int a, int b)
{
    return b == 0 ? a : gcdf(b, a % b);   
}

void solve(){

    int n,l,r; cin >> n >> l >> r;

    if(r-l+1<n) cout <<"NO";
    else {
        cout << "YES\n";
        for(int i=l; i<l+n; i++) cout << i << " ";
    }

    // set<int> gcd;
    // vi v(n);
    // int cur=0;

    // for(int i=l; i<r && cur<n;i++){
    //     if(!exist<set<int>>(gcd, gcdf(i,cur+1))){
    //         v[cur] = i;
    //         gcd.insert(gcdf(i,cur+1));
    //         cur++;
            
    //     }
    // }

    // if (cur==n){
    //     cout << "YES\n";
    //     print(v);
    // } else cout << "NO";



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
    for(int i : v) cout << i <<" ";
    cout << endl;
}

ll fact(int n){
    int prod=1;
    for(int i=1; i<=n; i++) prod*=i;
    return prod;
}

