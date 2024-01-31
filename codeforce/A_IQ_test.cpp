#include<iostream>
using namespace std;
int main(){
    int n; cin >> n;
    int even=0;
    int lasteven,lastodd;
    for(int i=0; i<n; i++)
    {
        int b; cin >> b;
        if(b&1) lastodd = i+1;
        else{
            even++;
            lasteven = i+1;
        }
    }
    cout << ((even==1)?lasteven:lastodd);
    return 0;
}