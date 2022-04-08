#include<iostream>
using namespace std;
int main(){
    int n,m,a,b; cin >> n >> m >> a >> b;
    int minsum= n*a;
    
    minsum = min(minsum, (n/m)*b + min((n%m)*a , b));
    cout << minsum;
    return 0;
}