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

int solve(vi& v, int i, int j, int si=0, int sj=0){
        int ans=0;
        int ii=i, j=v.size()-1;
        
        while(ii!=j){
            if(si>sj) sj+=v[j--];
            else if(si<sj) si+=v[ii++];
            if(si==sj) ans=max( 
                max(
                    (int)v.size()+ii-j-1,
                    solve(v, ii, j-1,si, sj+v[j])
                ),
                solve(v, ii+1, j, si+v[ii], sj)
            );
        }
        return ans;
}

int main(){

    int times; cin >> times; 

    for(int i=0; i<times; i++){
        int n ; cin >> n;
        vi v = readvi(n);

        cout << solve(v, 0, n-1) << endl;
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