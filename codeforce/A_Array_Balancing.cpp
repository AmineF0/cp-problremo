#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<long long> vl;
typedef vector<vector<long long>> vll;

typedef long long ll;
typedef unsigned long long ull;


vi readvi(int n);
int maxvi(vi v){
    int mx = v[0];
    for(auto i : v) mx = max(mx, i);
    return mx;
}

ll mnsum(vll& dp, vi& a , vi& b, int i, int n, int swp){
    if(i==n-1) return 0;
    if(dp[i][swp]!=-1) return dp[i][swp];
    
    // swp = 0
    ll nnoswp = mnsum(dp, a, b, i+1, n, 0) + abs(a[i]-a[i+1]) + abs(b[i]-b[i+1]);
    ll nyeswp = mnsum(dp, a, b, i+1, n, 1) + abs(a[i]-b[i+1]) + abs(b[i]-a[i+1]);
    dp[i][0] = min(nnoswp, nyeswp);

    // swp = 1
    ll ynoswp = mnsum(dp, a, b, i+1, n, 0) + abs(b[i]-a[i+1]) + abs(a[i]-b[i+1]);
    ll yyeswp = mnsum(dp, a, b, i+1, n, 1) + abs(b[i]-b[i+1]) + abs(a[i]-a[i+1]);
    dp[i][1] = min(ynoswp, yyeswp);


    return dp[i][swp];
}

int main(){

    int times; cin >> times; 

    for(int i=0; i<times; i++){
        int n ; cin >> n;
        vi a = readvi(n);
        vi b =readvi(n);
        vll dp(n+1,vl(2,-1));

        cout << min(mnsum(dp, a , b, 0, n, 0), mnsum(dp, a , b, 0, n, 1))<< endl;
    }



    return 0;
}

vi readvi(int n){
    vi v(n);
    for(int i=0;i <n; i++) cin >> v[i];
    return v;
}
