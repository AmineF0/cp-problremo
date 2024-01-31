#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

typedef struct tests{
    vector<short> v;
    int count=0;
    tests(){}
    tests(int n){
        v = vector<short>(n);
        count = 0;
    }

}tests;
    inline tests max(tests t1, tests t2){
        return (t1.count > t2.count) ? t1 : t2;
    }

void print(vector<short> v){
    for(short i : v) cout << i <<"";
    cout << endl;
}
inline tests dpf(vector<map<int,tests>>& dp, vi& v, int i, int q){
    if(i>=v.size()) return tests(v.size());

    if(dp[i].find(q)!=dp[i].end()) return dp[i][q];

    if(q>=v[i]){
        tests t =  dpf(dp, v, i+1, q);
        t.count++;
        t.v[i]=1;
        return dp[i][q] = t;
    } else if(q<=0){
        tests t =  dpf(dp, v, i+1,  q);
        t.v[i]=0;
        return dp[i][q] = t;
    } else {
        tests t1 = dpf(dp, v, i+1, q-1);
        t1.count++;
        t1.v[i]=1;
        tests t2 =  dpf(dp, v, i+1, q);
        t2.v[i]=0;
        return dp[i][q] = max(t1, t2);
    }

}

void solve(){

    int n, q; cin >> n >>q;

    vi v = readvi(n);

    vector<map<int,tests>> dp(n+1,map<int,tests>());

     print(dpf(dp, v, 0, q).v);


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

template <typename T> bool exist(T& s, int a){
    return s.find(a) != s.end();
}