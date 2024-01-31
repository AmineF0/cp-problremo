#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int size; cin >> size;

    while(size--){
        int n,m;
        cin >> n>> m;
        int ans=0;


        int k = (m-1)/(n-1);

        
        ans = k + m;
        cout << ans << endl;
    }
    return 0;
}
