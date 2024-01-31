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

    int n; cin >> n;
    vi v = readvi(n);

    vi v2 = v;
    sort(v2.begin(), v2.end());
    
    int mnv = v2[0], mnb=v[1];

    for(int i=0; i<v.size(); i++){
        if(v[i]==mnv){
            if(i>0){
                mnb = min( mnb, v[i-1] - (int)ceil(v[i]/2.));
            }
            if(i<v.size()-1){
                mnb = min( mnb, v[i+1] - (int)ceil(v[i]/2.));
            }
        }
    }
    
    int ans = ceil(mnv/2) + ceil(mnb/2);
    cout << ans;

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