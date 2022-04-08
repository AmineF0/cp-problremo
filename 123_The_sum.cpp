#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n; cin >> n;
    if(n==1) {
        cout << 1;
        return 0;
    }
    if(n==2) {
        cout << 2;
        return 0;
    }

    int sum=2;
    int u0=1, u1=1;
    for(int i=2; i<n; i++){
        int u3=u0+u1;
        sum+=u3;
        u0=u1;
        u1=u3;
    }
    cout << sum;
    return 0;
}