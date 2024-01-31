#include<math.h>
#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,a; cin >> n >> m >> a;
    double div = 1./a;
    ll left = ceil(n*div);
    ll r = ceil(m*div);

    cout << r*left;
    return 0;
}