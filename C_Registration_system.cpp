#include<bits/stdc++.h>
using namespace std;
int main(){
    int b; cin >> b;
    map<string, int> s;
    while(b--){
        string str ; cin >> str;
        int cnt = s[str]++;
        if(cnt==0){
            cout << "OK\n" ;
        } else {
            cout << str << cnt << "\n";
        }
 
    }
 
    return 0;
}