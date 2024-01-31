#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> vi;
typedef vector<vi> vii;
typedef long long ll;

#define M 1000000007

vii matrixMult(vii a, vii b){
    int n = a.size();
    vii ans(n, vi(n, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++){
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= M;
            }
    return ans;
}

vii matrixFastPow(vii a, int n){
    if(n==1) return a;
    if(n%2==0){
        vii aux = matrixFastPow(a, n/2);
        return matrixMult(aux, aux);
    }
    else{
        vii aux = matrixFastPow(a, n-1);
        return matrixMult(aux, a);
    }
}
