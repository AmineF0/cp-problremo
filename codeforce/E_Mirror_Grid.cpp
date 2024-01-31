#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

void solve(){

    int n; cin >> n;

    vector<string> mat(n, "");

    for(int i=0; i<n; i++){
        cin >> mat[i];
    }

    int cnt=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            int shift=0;
            
            shift += ((mat[i][j]=='0'));     // 0 2
            shift += ((mat[n-1-j][i]=='0')); // 0 0
            shift += ((mat[n-1-i][n-1-j]=='0')); // 2 2
            shift += ((mat[j][n-1-i]=='0')); // 2 2

            // if(min(4-abs(shift), abs(shift)) !=0) 
            //     cout << i << j<< " " << min(4-abs(shift), abs(shift))<<endl;
            
            cnt += min(4-abs(shift), abs(shift));

            if(shift > 0){
                mat[i][j]=
                mat[n-1-j][i]=
                mat[n-1-i][n-1-j]=
                mat[j][n-1-i]='1';
            } else {
                mat[i][j]=
                mat[n-1-j][i]=
                mat[n-1-i][n-1-j]=
                mat[j][n-1-i]='0';
            }

        }
    }



    cout << cnt << endl;
}





int main(){
    int times; cin >> times; 
    for(int oc=0; oc<times; oc++)
        solve();
    return 0;
}

vi readvi(int n){
    vi v(n);
    for(int i=0;i <n; i++) cin >> v[i];
    return v;
}

int maxvi(vi v){
    int mx = v[0];
    for(auto i : v) mx = max(mx, i);
    return mx;
}

int minvi(vi v){
    int mx = v[0];
    for(auto i : v) mx = min(mx, i);
    return mx;
}

void print(vii v){
    for(vi vv : v) print(vv);
}

void print(vi v){
    for(int i : v) cout << i <<"";
    cout << endl;
}

ll fact(int n){
    int prod=1;
    for(int i=1; i<=n; i++) prod*=i;
    return prod;
}