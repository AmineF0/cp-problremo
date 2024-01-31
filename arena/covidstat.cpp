#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;

typedef struct country{
  int x, y, r, eff;
  long double density;
  string name;
} country;


int main(){
  int t; cin >> t;
  while(t--){
    int n, m; cin >> n >> m;
    vector<country> contries(n);

    for(int i=0; i<n; i++){
      string s; cin >> s;
      int x,y,r; cin >> x >> y >> r;
      contries[i] = {x, y, r, 0, 0, s};
    }

    for(int i=0; i<m; i++){
      int x, y, eff; cin >> x >> y >> eff;
      for(int j=0; j<n; j++){
        int dist = 
          (x-contries[j].x)*(x-contries[j].x)+
          (y-contries[j].y)*(y-contries[j].y)
        ;
        if(dist <= contries[j].r * contries[j].r){
          contries[j].eff += eff;
        }
      }
    }

    for(int i=0; i<n; i++){
      contries[i].density = (long double)contries[i].eff / (long double)(contries[i].r*contries[i].r);
    }

    country mx = contries[0];

    for(int i=1; i<n; i++){
      if(contries[i].eff > mx.eff){
        mx = contries[i];
      }
      else if(contries[i].eff == mx.eff){
        if(contries[i].density > mx.density){
          mx = contries[i];
        }
      }
    }

    cout << mx.name << endl;
  }
}