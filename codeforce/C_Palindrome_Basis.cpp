#include<bits/stdc++.h>
using namespace std;

#define MOD 1e9+7
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

int dpf(vi& dp, int num){
    if(dp[num]!=-1) return dp[num];
    if(num==1) return 1;
    return dp[num] = num+ dpf(dp, num-1)%(1e9+7);
}

int main(){

    int times; cin >> times; 
    vi dp(1e5, -1);
    for(int i=0; i<times; i++){
        int b ; cin >> b;
        cout << dpf(dp, b-1) << endl;
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