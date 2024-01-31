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

vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);

int getPos(int x, int y, int a, int b){
    return x*a+b*y;
}

int main(){

    int a,b,q; cin >> a >> b >> q;

    string mat ="";
    for(int i=0; i<a; i++) {
        string s;
        cin >> s;
        mat+=s;
    }

    int f = 0;
    int tofill=0;
    for(char c: mat) if(c=='*') f++;
    for(int i=0; i<f; i++) if(mat[i]=='.') tofill++;
cout << tofill << endl;
    while(q--){
        int x,y; cin >> x >> y;
        int p = (x-1)*b+(y-1);
        cout << p << " <" << f << "   ";
        if(mat[p] == '.'){
            f++;
            tofill += (mat[f-1]=='.'?0:1);
            tofill += (f>p?-1:1);
            mat[p] = '*';
        } else {
            f--;
            tofill += (mat[f+1]=='*'?0:1);
            tofill += (f>p?1:-1);
            mat[p] = '.';
        }
        cout << tofill << endl;
        cout << mat << endl;
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