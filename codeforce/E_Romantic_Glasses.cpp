#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> nums(n);
        for(int i=0;i<n;i++)
            cin >> nums[i];
        ll prefix = 0;
        set<ll> s;

        bool found = false;
        for(int i=0;i<n;i++){
            if(i%2==0)
                prefix+=nums[i];
            else
                prefix-=nums[i];
            if(prefix==0 || s.find(prefix)!=s.end()){
                cout << "YES\n";
                found = true;
                break;
            }
            s.insert(prefix);
        }
        if(!found)
            cout << "NO\n";

    }
}
