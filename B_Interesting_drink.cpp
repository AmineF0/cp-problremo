#include<bits/stdc++.h>
using namespace std;
int main(){

    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n ; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int b; cin >> b;

    while(b--){

        int a; cin >> a;
        cout << upper_bound(v.begin(), v.end(), a)-v.begin() << endl;



    }


    return 0;
}