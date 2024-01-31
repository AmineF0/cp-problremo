#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef long double ld;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int t; cin >> t;
  while(t--){

    int n, x, y; cin >> n >> x >> y;
    ld dist = x*1./(2*n);
    // cout << dist << endl;
    ld ans = sqrt(dist*dist + y*y)*2*n;
        // cout << setprecision(15)<< ans << endl;

    cout << setprecision(15) << ceil(ans) << endl;
  }
}