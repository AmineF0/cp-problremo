#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull dp[100002];

ull dpf(map<ull,ull>& dt, ull dp[] , int i, int mx){
    if(i>mx) return 0;
    if(dp[i]!=0) return dp[i];
    
    ull take = dpf(dt,dp,i+2, mx) + dt[i]*i;
    ull leave = dpf(dt, dp, i+1, mx);

    return dp[i] = max(take, leave);

}

void(){
    int n[];

    Element* head= null, tmp = null;

    for(int i=0; i<n ; i++){

        tmp->val = t[i];


    }
    

}


int main(){
    int n ; cin >> n;
    map<ull, ull> freq;
    memset(dp, 0, sizeof(dp));
    int mx=INT_MIN;
    for(int i=0; i<n; i++){
        int r ; cin >> r; freq[r]++;
        mx = max(mx, r);
    }

    cout << dpf(freq, dp, 0, mx);

    return 0;
}