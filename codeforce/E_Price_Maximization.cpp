#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

void solve(){

    int n,k; cin >> n >> k;

    vi v=readvi(n);
    vector<queue<int>> data (k+1, queue<int>());
    int sum=0;

    for(int val : v){
        if(data[val%k].size()==0) {
            data[(k-(val%k))].push(val);
        }
        else {
            int bf = data[val%k].front(); 
            data[val%k].pop();
            sum+=(val + bf)/k;
        }
    }

    int kk=-1;
    for(queue<int> q : data){
        while(!q.empty()){
            int val =q.front(); q.pop();
            if(kk==-1) kk=val;
            else sum += (kk+val)/k, kk=-1;
        }
    }


    cout << sum << endl;

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