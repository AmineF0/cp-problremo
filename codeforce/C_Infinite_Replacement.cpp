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
ll fact(int n){
     return (n==0) || (n==1) ? 1 : n* fact(n-1);
}

vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);

int main(){

    int times; cin >> times; 

    for(int i=0; i<times; i++){
        string s,t; cin >> s >> t;
        bool fd= false;
        for(char c : t) if(c=='a') fd=true;
        if(fd) {
            cout << ((t.size()>1)?-1:1) << endl;
        }
        else{
            int cnt=s.size();
            ll ans=0;
            for(int i=0; i<cnt+1; i++){
                ans+=fact(cnt)/(fact(i)*fact(cnt-i));
            }
            cout << ans << endl;
        }


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