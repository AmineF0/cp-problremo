#include<bits/stdc++.h>
using namespace std;

bool dawi(vector<int>& dyour ,int n, double r){
    int poto = 0;
    long double lastDawi = -1;

    for(int dar : dyour){
        if(dar > lastDawi) {
            poto++;
            lastDawi = dar+2*r;
        }
    }
    
    return poto <= n;
}

int main(){

    int n; cin >> n;
    cout.precision(3);
    while(n--){
        int nd, np; cin >> nd >> np;
        vector<int> dyour(nd, 0);
        for(int i=0; i<nd; i++) cin >> dyour[i];
        
        long double mn = 0 , mx = 1e9+1;

        while(mx-mn >= 0.0001){
            long double tmp = mn + (mx-mn)/2;
            bool isdawi = dawi(dyour, np, tmp);
            if(isdawi) mx = tmp;
            else mn = tmp;
        }        
        cout << fixed << mx << endl;
    }


    return 0;
}