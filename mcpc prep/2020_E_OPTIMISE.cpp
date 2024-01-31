#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007

long long power(int a, int n){
    long long prod = 1;
    for(int i=0; i<n; i++){
        prod = (prod*a)%MOD;
    }
    return prod;
}

vector<double> prod_scalaire(vector<vector<double>> A, vector<int> etape_0){
    vector<double> ans(3,0);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ans[i] += etape_0[j] * A[i][j];
            ans[i] = ans[i];
        }
    }
    return ans;
}

double sumArr(vector<double> arr){
    double ans = 0;

    for(int i=0; i<3; i++){
            ans += arr[i];
    }

    return ans;
}
typedef long long ll;
vector<ll> prod_scalaire(vector<vector<ll>> A, vector<int> etape_0){
    vector<ll> ans(3,0);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ans[i] += etape_0[j] * A[i][j];
            ans[i] = ans[i]%MOD;
        }
    }
    return ans;
}

ll sumArr(vector<ll> arr){
    ll ans = 0;

    for(int i=0; i<3; i++){
            ans += arr[i];
            ans = ans%MOD;
    }

    return ans;
}

int main(){
    int a0,b0,c0,n;
    cin >> a0 >> b0 >> c0 >> n;

    int x=power(-1,n), y=power(2,n);

    vector<vector<double>> A = {
        { 0.666666666666667*x + 0.333333333333333*y, -0.333333333333333*x + 0.333333333333333*y,  -0.333333333333333*x + 0.333333333333333*y},
        {-0.333333333333333*x + 0.333333333333333*y,  0.666666666666667*x + 0.333333333333333*y,  -0.333333333333333*x + 0.333333333333333*y},
        {-0.333333333333333*x + 0.333333333333333*y, -0.333333333333333*x + 0.333333333333333*y,   0.666666666666667*x + 0.333333333333333*y}
    };

    vector<vector<ll>> Ap = {
        { 2*x + 1*y, -1*x + 1*y,  -1*x + 1*y},
        {-1*x + 1*y,  2*x + 1*y,  -1*x + 1*y},
        {-1*x + 1*y, -1*x + 1*y,   2*x + 1*y}
    };

    cout << sumArr(prod_scalaire(Ap, {a0,b0,c0}))/3;

}