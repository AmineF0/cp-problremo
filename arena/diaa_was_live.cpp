#include <bits/stdc++.h>
using namespace std;
typedef double ld;
typedef long long ll;
int main(){
  int t; cin >> t;
  while (t--)
  {
    int a; cin >> a;
    ld r=0;
    for (int i=0; i<a; i++)
    {
      ll x; cin >> x;
      r+=log10(x);
    } 
    cout << ll(r)+1 << endl;
  }
    
}