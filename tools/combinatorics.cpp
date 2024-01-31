#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;

#define MOD 1000000007

long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long modInv(long long a, long long m) {
    return binpow(a, m - 2);
}

double fastMOD(double a){
    while(a>MOD) a-=MOD;
    return a;
}

int C(int n, int k) {
    long long res = 1;
    for (int i = 1; i <= k; ++i){
        res = ((res * (n - k + i))%MOD * modInv(i, MOD)) % MOD;
    }
    return res;
}

int C(int n, int k, vi& precomputeModInverse) {
    long long res = 1;
    for (int i = 1; i <= k; ++i){
        res = ((res * (n - k + i))%MOD * precomputeModInverse[i]) % MOD;
    }
    return res;
}

vi precomputeModInverse(int n){
  vi inv(n+1);
  for(int i = 0; i <= n; i++)
    inv[i] = modInv(i, MOD);

  return inv;
}

//permutation
int P(int n, int k) {
    long long res = 1;
    for (int i = 1; i <= k; ++i){
        res = ((res * (n - k + i))%MOD);
    }
    return res;
}

int main(){

  vi precomputedModInverse = precomputeModInverse(1e5);

  cout << C(1e5, 1e5, precomputedModInverse) << endl;
  cout << C(1e4, 1e2, precomputedModInverse) << endl;
  cout << C(7, 3, precomputedModInverse) << endl;

  cout << P(1e5, 1e5) << endl;
  cout << P(1e4, 1e2) << endl;
  cout << P(7, 3) << endl;


}