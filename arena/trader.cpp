#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> vi;
typedef vector<vi> vii;
typedef long long ll;

#define M 1000000007


// product matrix vector
vi productMatrixVector(vii& matrix, vi& v){
    vi ans(matrix.size(), 0);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<v.size(); j++){
            ans[i] += (matrix[i][j] * v[j]) % M;
            ans[i] %= M;
        }
    }
    return ans;
}

// product matrix matrix
vii productMatrixMatrix(vii& matrix1, vii& matrix2){
    vii ans(matrix1.size(), vi(matrix2[0].size(), 0));
    for(int i=0; i<matrix1.size(); i++){
        for(int j=0; j<matrix2[0].size(); j++){
            for(int k=0; k<matrix2.size(); k++){
                ans[i][j] += (matrix1[i][k] * matrix2[k][j]) % M;
                ans[i][j] %= M;
            }
        }
    }
    return ans;
}

// matrix fast pow O(log n)
vii matrixFastPow(vii& matrix, ll n){
    if(n==1) return matrix;
    if(n%2==0){
        vii matrixPow = matrixFastPow(matrix, n/2);
        return productMatrixMatrix(matrixPow, matrixPow);
    }
    else{
        vii matrixPow = matrixFastPow(matrix, n-1);
        return productMatrixMatrix(matrixPow, matrix);
    }
}


ll solve(ll n, int a, int b, int c){
    vii matrix = {
        {28,-175,300},
        {1,0,0},
        {0,1,0}
    };

    vii matrixPow = matrixFastPow(matrix, n);
    
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            matrixPow[i][j] = (matrixPow[i][j] + M) % M;

    vi v = {a, b, c};
    vi ans = productMatrixVector(matrixPow, v);
    return ans[0];
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t=0; cin >> t;
    while(t--){
        ll n, a, b, c; cin >> a >> b >> c >> n;
        cout << solve(n-3, a, b, c) << endl;
    }
    return 0;
}