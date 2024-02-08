#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int t, n ; cin >> n >> t;
  vector<ll> nums(n);
  for(int i=0;i<n-1;i++){
    cin >> nums[i];
  }
  ll cur = 0;
  t--;

  while(cur < t){
    cur += nums[cur];
  }

  if(cur == t){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }

}