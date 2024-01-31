#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int s(ll n){
    int i=0;

    do{
        i+= n%10;
        n=n/10;
    } while(n!=0);

    return i;
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main(){
    ll a ,c, b, count = 0;
    cin >> a >> b >> c;
    for(int i=1; i<=81; i++){
        ll x = a*binpow(i, b) + c;
        if( i==s(x) && x<1e9 && x>=1){
             count++;
        }
    }
    cout << count ;
    return 0;
}