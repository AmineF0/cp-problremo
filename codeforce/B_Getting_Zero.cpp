#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

typedef long long ll;
typedef unsigned long long ull;


vi readvi(int n);
int maxvi(vi v){
    int mx = v[0];
    for(auto i : v) mx = max(mx, i);
    return mx;
}

int dpf(vi& dp, int i){
    i = i%32768;

    if(dp[i]!=-1) return dp[i];

    dp[i]= 1e6;
    int take = 1+ min(dpf(dp, (2*i)), dpf(dp, (i+1)));
    
    return dp[i] = take;
}

int main(){

    int times; cin >> times; 
    vi dp(32769, 0);

    dp[0]=0;
    for(int i=32768; i>0; i--){
        int j=0, jj=i%32768; while(jj!=0) jj=(jj*2)%32768, j++, 
        dp[i] = min(dp[i+1]+1, j);
    }
    dp[32768]=1;

    
    for(int i=0; i<times; i++){
        int n; cin >> n;
        cout << dp[n] << " ";
    }



    return 0;
}

vi readvi(int n){
    vi v(n);
    for(int i=0;i <n; i++) cin >> v[i];
    return v;
}
