#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vector<int>> vii;

typedef long long ll;
typedef unsigned long long ull;


vi readvi(int n);
vl readvl(int n);
int maxvi(vi v){
    int mx = v[0];
    for(auto i : v) mx = max(mx, i);
    return mx;
}

int main(){

    int n, k; cin >> n >> k;
    vl b = readvl(n);
    ll ans=0;
    vl sumac(k+1,0) ;
    for(int i=n-1; i>=0; i--){
        
        

        ll to_add = b[i];
        ll ad=min((i+1),k);

        for(int f=1; f<k+1; f++){
            b[i] -= f*sumac[f];
            sumac[f-1] += sumac[f];
            sumac[f]=0;
        }

        if(b[i]<=0) continue;
        
        ll time = ceil(b[i]*1./ad);

        //cout << b[i] << " " << ad <<" "<< time <<" " << i << endl;
        
        b[i] -= time*ad;
        sumac[ad-1]+=time;


        ans+=time;

        // while(b[i]>0){
        //     for(int j=i, cb=ad; j>=0 && cb>0; j--, cb--){
        //         b[j] -= cb;
        //     }
        //     ans++;
        // }
        

    }
    cout << sumac[0];
    return 0;
}

vl readvl(int n){
    vl v(n);
    for(int i=0;i <n; i++) cin >> v[i];
    return v;
}

vi readvi(int n){
    vi v(n);
    for(int i=0;i <n; i++) cin >> v[i];
    return v;
}
