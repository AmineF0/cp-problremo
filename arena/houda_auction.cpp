#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while(t--){

    ll ans = 0;
    ll k; cin >> k;
    multiset<int> s;

    while(k--){
      int m; cin >> m;
      
      while(m--) {
        int d; cin >> d;
        s.insert(d);
      }

      auto mx = --s.end();
      auto mn = s.begin();

      ans += *mx - *mn;
      s.erase(mx);
      s.erase(mn);
    }

    cout << ans << endl;
  }
  return 0;
}