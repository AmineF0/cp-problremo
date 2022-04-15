#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

typedef long long ll;
typedef unsigned long long ull;

vi readvi(int n);



int main(){

    int n; cin >> n; 

    for(int i=0; i<n; i++){
        int c ; cin >> c;
        int mx=0;
        map<int, int> m;
        for(int j=0; j<c; j++) {
            int x; cin >> x;
            m[x]++;
        }
        for(auto it : m){
            mx =max(mx, it.second);
        }

        int cnt=0;
        while(mx<c){
            cnt += 1 + min(mx, c-mx);
            mx*=2;
        }

        cout << cnt << endl;
    }



    return 0;
}

vi readvi(int n){
    vi v(n);
    for(int i=0;i <n; i++) cin >> v[i];
    return v;
}