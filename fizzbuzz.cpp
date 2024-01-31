#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;

    vector<int> v(n+m+1, 0);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            v[i+j]++;
        }
    }

    int c = 0;

    for (int i=0; i<n+m+1; i++)
        c = max(c, v[i]);

    for(int i=0; i<n+m+1; i++){
        if(c==v[i])
            cout << i << endl;
    }






    return 0;
}
