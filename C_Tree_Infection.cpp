#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

typedef long long ll;
typedef unsigned long long ull;


vi readvi(int n);
int maxvi(vi v);

int main(){

    int times; cin >> times; 

    for(int i=0; i<times; i++){
        int ans=0;
        int p; cin >> p;
        vi pi = readvi(p-1);
        map<int,ll> m;
        multiset<ll> s;

        m[0]=1;
        for(int j : pi)m[j]++;
        
        for(auto g : m)
            s.insert(g.second);

        
        //for(auto g : s) cout << g <<" ;";

        multiset<ll> df;int fd=0;
        ll prev = s.size();

        for(auto it=s.begin(); it!=s.end(); it++){
            fd++;
            df.insert(*it-fd);
        } 
        s=df;

        //for(auto g : s) cout << g <<" ";

        ll mxit = *s.rbegin();
        
        while(mxit-ans>0){
            ans++;
            s.erase(mxit);
            s.insert(mxit-1);
            mxit = *s.rbegin();
        }


        cout << ans+prev << endl;

    }



    return 0;
}

int maxvi(vi v){
    int mx=v[0];
    for(int i : v) mx=max(mx,i);
    return mx;
}

vi readvi(int n){
    vi v(n);
    for(int i=0;i <n; i++) cin >> v[i];
    return v;
}