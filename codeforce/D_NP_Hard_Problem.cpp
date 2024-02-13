#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);



void solve(){
    int n, m; cin >> n >> m;

    vi color(n, -1);
    vii g(n);

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool f = true;
    for(int i=0; i<n && f; i++){
        if(color[i]!=-1) continue;
        queue<int> q, qq;
        q.push(i);
        color[i]=0;
        int c = 0;
        while(!q.empty() && f){
            while(!q.empty() && f){
                int t = q.front(); q.pop();
                for(auto n : g[t]){
                    // cout << n << t << c << endl;
                    if(color[n] == c) {
                        // cout << n << t << c << endl;
                        f = false;
                    }
                    else if(color[n]==-1) {
                        color[n] = !c;
                        qq.push(n);
                }}
            }
            swap(q, qq);
            c=!c;
        }

    }

    vi fv, sv;
    for(int i=0; i<n; i++){
        if(color[i]) fv.push_back(i);
        else sv.push_back(i);
    }



    if(!f) cout << -1;
    else {
        cout << fv.size() << endl;
        for(auto i : fv) cout << i+1 << " ";
        cout << endl << sv.size() << endl;
        for(auto i : sv) cout << i+1 << " ";
    }

    cout << endl;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // int times; cin >> times; 
    // for(int oc=0; oc<times; oc++)
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