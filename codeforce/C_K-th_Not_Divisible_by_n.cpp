#include<bits/stdc++.h>
using namespace std;

int is_valid(long long n , long long k , long long num){
    if((num%n)==0) return 2;
    long long f = (num%n) + (num/n)*(n-1);
    if(f==k) return 0;
    else if(f>k) return 1;
    else return -1;

}

bool bin_ser(int n, int k, long long i=0, long long j=LONG_LONG_MAX){

        while( i<=j ){

            long long tmp = i + (j-i)/2;
            int valid = is_valid(n,k,tmp);
            //cout << tmp << ":" <<valid << endl;

            if(valid==2) {
                return bin_ser(n,k,i,j-1) || bin_ser(n, k, i+1,j);
            }

            if(valid==0) {
                cout << tmp <<endl;
                return 1;
            } else if(valid == -1){
                i = tmp + 1;
            } else {
                j = tmp - 1;
            }
        }
        return 0;

}

int main(){
    int b; cin >> b;
    while(b--){

        int n , k ;
        cin >> n >> k;
        //cout << n << " " << k << " " <<is_valid(n, k, 113) << ":\n";

        bin_ser(n,k);

    }

    return 0;
}