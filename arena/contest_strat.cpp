#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	for(int i=0; i<t; i++){
		int n; cin >> n;
		vector<long long> c(n);
		for(int i=0; i<n; i++) cin >> c[i];
		for(int i=0; i<n ;i++){
			long long f; cin >> f; c[i]*=f;
		}
		
		
		vector<vector<long long>> v(n, vector<long long>(4, 0));
		
		v[0][0]=0;
		v[0][1]=c[0];
		
		for(int i=0; i<n-1; i++){
			for(int j=0; j<4; j++){
				if(j==3) v[i+1][0] = max(v[i][j], v[i+1][0]);
				else {
					v[i+1][j+1] = max(v[i][j]+c[i+1], v[i+1][j+1]);
					v[i+1][0] = max(v[i][j], v[i+1][0]);
				}
			}
		}
		
		cout << max(max(v[n-1][0], v[n-1][1]), max(v[n-1][2], v[n-1][3])) << endl;
		
	}
	return 0;
}