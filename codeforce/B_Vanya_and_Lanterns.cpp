#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int npoto, fin; cin >> npoto >> fin;
    vector<int> potowat(npoto); 
    for(int i=0; i<npoto; i++) cin >> potowat[i];
    sort(potowat.begin(), potowat.end());

    double maxdiff = max(potowat[0], fin - potowat[npoto-1]);
    for(int i=0; i<npoto-1; i++){
        maxdiff = max(maxdiff, (potowat[i+1]-potowat[i])/2.);
    }
    cout.precision(10);
    cout << fixed  <<maxdiff;

}