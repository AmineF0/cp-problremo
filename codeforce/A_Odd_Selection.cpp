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

    for(int i=0; i<times; i++){
        int n, d; cin >> n >> d;

        int is_odd = 0, is_even=0;
        
        for(int i=0; i<n; i++){
            int a; cin >> a;
            if(a&1) is_odd++;
            else is_even++;
        }
       // print({is_odd, is_even});

        if(is_odd==0) cout << "No\n";
        else {
            d--;
            is_odd--;
            d -= is_even;
            if(d>0 && d&1 && is_even) d++;
            if( d>0 && (d&1 || d>is_odd) ) cout << "No\n";
            else cout << "Yes\n";
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
    for(int i : v) cout << i <<" ";
    cout << endl;
}