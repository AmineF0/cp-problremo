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


ll solve(int n , int k){
    vii matrix = vii(k, vi(k, 0));
    for(int i=1; i<k; i++) matrix[i][i-1] = 1;
    for(int i=0; i<k; i++) matrix[0][i] = 1;

    vii matrixPow = matrixFastPow(matrix, n);
    return matrixPow[0][0];
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    cout << solve(n, k) << endl;

    return 0;
}