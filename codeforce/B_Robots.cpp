#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef string S;

typedef vector<int> vi;
typedef vector<vi> vii;

typedef vector<ll> vl;
typedef vector<vl> vll;

typedef map<int,int> mii;
typedef map<int,S> mis;
typedef map<S,int> msi;

typedef set<int> si;
typedef set<S> ss;

vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);ll fact(int n);
typedef struct rob{int x; int y; rob(int a,int b){x=a; y=b;}} rob;
int main(){

    int times; cin >> times; 

    for(int oc=0; oc<times; oc++){
        int l,L; cin >> l >> L;
        rob r1 = rob(10,10);
        rob r2 = rob(10,10);
        for(int i=0; i<l; i++){
            for (int j=0; j<L; j++){
                char c; cin >> c;
                if(c=='R') {
                    if(r1.x>i) r1 = rob(i,j);
                    if(r2.y>j) r2 = rob(i,j);
                }
            }
        }

        bool y = (r1.x==r2.x ||r1.y==r2.y);

        cout << (y? "YES\n" : "NO\n");


    }



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

void print(vi v){
    for(int i : v) cout << i <<"";
    cout << endl;
}

ll fact(int n){
    int prod=1;
    for(int i=1; i<=n; i++) prod*=i;
    return prod;
}