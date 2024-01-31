#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ld> vi;
typedef vector<vi> vii;

// vectorial product vector vector
vi vectorialProduct(vi& a, vi& b){
  vi ans(3);
  ans[0] = a[1]*b[2] - a[2]*b[1];
  ans[1] = a[2]*b[0] - a[0]*b[2];
  ans[2] = a[0]*b[1] - a[1]*b[0];
  return ans;
}

// plan equation
vi planEquation(vi& a, vi& b, vi& c){
  vi ans(4);
  vi ab(3), ac(3);
  for(int i=0; i<3; i++){
    ab[i] = b[i] - a[i];
    ac[i] = c[i] - a[i];
  }
  vi n = vectorialProduct(ab, ac);
  ans[0] = n[0];
  ans[1] = n[1];
  ans[2] = n[2];
  ans[3] = -(n[0]*a[0] + n[1]*a[1] + n[2]*a[2]);
  return ans;
}

// pts belong to plan
bool ptsBelongToPlan(vi& plan, vi& pt){
  return plan[0]*pt[0] + plan[1]*pt[1] + plan[2]*pt[2] + plan[3] == 0;
}

// pts coliinear
bool ptsColiinear(vi& a, vi& b, vi& c){
  vi ab(3), ac(3);
  for(int i=0; i<3; i++){
    ab[i] = b[i] - a[i];
    ac[i] = c[i] - a[i];
  }
  vi n = vectorialProduct(ab, ac);
  return n[0] == 0 && n[1] == 0 && n[2] == 0;
}

int main(){
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vii pts(n, vi(3));
    for(int i=0; i<n; i++){
      for(int j=0; j<3; j++){
        cin >> pts[i][j];
      }
    }
    bool found = false;
    vi plan;

    for(int i=0; i<n && !found; i++){
      for(int j=i+1; j<n && !found; j++){
        for(int k=j+1; k<n && !found; k++){
          if(ptsColiinear(pts[i], pts[j], pts[k])) continue;
          plan = planEquation(pts[i], pts[j], pts[k]);
          found = true;
          break;
        }
      }
    }

    if(!found){
      cout << "Yes" << endl;
      continue;
    }

    bool ans = true;
    for(int i=0; i<n && ans; i++){
      if(!ptsBelongToPlan(plan, pts[i])) ans = false;
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}