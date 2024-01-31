#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll q; cin >> q;
    while(q--){
        ll a, b; cin >>a >> b;
        ll cnt=0;
        while(a!=0){
            if(a%b==0) {
                a/=b;
                cnt++;
            }
            else {
                cnt+= a%b;
                a-=a%b;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}