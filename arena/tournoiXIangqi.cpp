#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;

  while(t--){
    ll n, k; cin >> n >> k;
    n = (n*n)%M;

    ll ans = 0;

    if(k==1){
      ans = ((n)*(n+1)/2)%M;
    }
    else {
      ll prod = k;
      for(ll i=1; i<=n; i++){
        ans = ((i*prod)%M + ans)%M;
        prod = (prod*k)%M;
      }
    }

    cout << ans << endl;
  }
}