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

    for(int ii=0; ii<times; ii++){
        int n; cin >> n;
        vi v = readvi(n);

        int ans=0;

        for(int i=n-2; i>=0 && ans!=-1; i--){
            while(v[i+1]<=v[i] && ans!=-1){
                
                v[i]/=2;
                
                ans++;
                if(v[i]==0 && v[i+1]==0) ans=-1;
            }
        }

        cout << ans << endl;

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