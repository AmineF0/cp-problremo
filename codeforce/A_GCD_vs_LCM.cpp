#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

typedef long long ll;
typedef unsigned long long ull;


vi readvi(int n);

long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int main(){

    int time; cin >> time; 

    for(int i=0; i<time; i++){
        int n; cin >> n;

        cout << 1<< " " <<n-3 <<" " << 1 << " "<<1 << endl;
    }



    return 0;
}

vi readvi(int n){
    vi v(n);
    for(int i=0;i <n; i++) cin >> v[i];
    return v;
}