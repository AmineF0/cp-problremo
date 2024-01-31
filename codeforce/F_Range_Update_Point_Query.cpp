#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);

int sumDig(int a){
    int sum=0;

    while(a!=0) {
        sum += a%10;
        a/=10;
    }
    return sum;
}

void solve(){
    int n,q; cin >> n>>q;

    vi v = readvi(n);

    set<int> s;
    for(int i=0; i<v.size(); i++) if(v[i]>9) s.insert(i);

    for(int i=0; i<q; i++){
        int op; cin >> op;
        if(op==1){
            int l , r; cin >> l >> r;
            l--, r--;
            for(int index=l; index<=r; index++){
                auto it = s.lower_bound(index);
                if(it==s.end() || *it>r) break;
                index = *it;
                int sum = sumDig(v[index]);
                if(sum == v[index]) s.erase(index);
                else v[index] = sum;
            
            }

        } else {
            int a; cin >> a;
            cout << v[a-1] << endl;
        }
    }

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

ull binpow(ull a, ull b) {
    ull res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll fact(int n){
    int prod=1;
    for(int i=1; i<=n; i++) prod*=i;
    return prod;
}

template <typename T> bool exist(T& s, int a){
    return s.find(a) != s.end();
}