#include <iostream>

using namespace std;

int main(){

    int n; // read the number of people

    char i = 'G';
    unsigned long long l=0, r=999999998988989LL;
    unsigned long long tmp = l + (r-l)/2;
    int cnt=0;
    
    while(i!='0'){
        if(i=='G'){
            l = tmp+1;
        } else if(i=='S') r = tmp-1;
        cnt++;
    }

    cout << cnt << endl;


    return 0;
}