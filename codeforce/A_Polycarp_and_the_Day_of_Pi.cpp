#include<bits/stdc++.h>
using namespace std;

void solve(){

    string n; cin >> n;
    string pi ="314159265358979323846264338327";

    int ans =0;
    for (int i=0; i<n.size(); i++){
        if(pi[i]==n[i]) {
            ans++;
        } else break;
    }

    cout << ans <<endl;
}





int main(){
    int times; cin >> times; 
    for(int oc=0; oc<times; oc++)
        solve();
    return 0;
}