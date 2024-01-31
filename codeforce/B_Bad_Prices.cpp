#include <bits/stdc++.h>
using namespace std;
int main(){

    int n; cin >> n;

    while(n--){
        int s; cin >> s;
        int cnt=0;

        vector<int> v(s);
        
        for(int i=0; i<s; i++)
            cin >> v[i];

        int mn=v[s-1];

        for(int i=s-2; i>=0; i--)
            if(v[i] <= mn) mn=v[i];
            else cnt++;

        cout << cnt << endl;


    }

    return 0;
}