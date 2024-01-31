#include <bits/stdc++.h>
typedef long long ll;
using namespace std;




int main(){
  int n; cin >> n;
  vector<ll> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];

  vector<ll> divisor_right(n);

  for(int i=0; i<n ; i++){
    for(int j=i+1; j<n; j++){
      if(v[j]%v[i]==0) divisor_right[i]++;
    }
  }

  int comb = 0;

  for(int i=0; i<n ; i++){
    for(int j=i+1; j<n; j++){
      if(v[j]%v[i]==0) comb+=divisor_right[j];
    }
  }

  cout << comb <<endl;
  return 0;
}