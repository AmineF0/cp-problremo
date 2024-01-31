#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

typedef struct dom{ 
    int a,b;
    dom(){};
    dom(int aa, int ba){a=aa,b=ba;}
 } dom;

void solve(){

    int n; cin >> n;

    vector<dom> vd(n);
    map<int,int> to;

    set<int> s1,s2;

    bool f= true;

    for(int i=0; i<n; i++) {

        int a,b; cin >> a >> b;
        if(!f) continue;

        bool ains1=s1.find(a) == s1.end(),
            bins1=s1.find(b) == s1.end(),
            ains2=s2.find(a) == s2.end(),
            bins2=s2.find(b) == s2.end();;

        if(a==b || (ains1 && bins2) || (ains2 && bins1) ) {f = false;continue;}

        if(ains1) {
            s1.insert(a); s1.insert(b);
        }else {
            s2.insert(a); s2.insert(b);
        
        }

    }
    
    if(!f || s1.size() != s2.size()) cout << "NO\n";
    else cout << "YES\n";

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