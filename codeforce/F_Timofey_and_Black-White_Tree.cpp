#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);




template <typename T> bool exist(T& s, int a){
    return s.find(a) != s.end();
}

double diff(double t, double d){
    double a = t;
    double b = d-t;
    return (a+b) - a*b;
}

vi findMinDis(vii& graph, int i){
    int mn = INT_MAX;
    vector<int> dist(graph.size(), INT_MAX);
    vi vis(graph.size(), 0);
    vis[i]=1;
    queue<int> t,tmp;
    t.push(i);
    int cnt = 0;
    while(!t.empty() && cnt <= mn){

        while(!t.empty()){
            int nx = t.front(); t.pop();
            dist[nx] = min(dist[nx], cnt);
            for(int ng : graph[nx]){
                if(vis[ng]) continue;
                tmp.push(ng);
                vis[ng]=1;
            }
        }
        cnt++;
        swap(tmp, t);
    }
    return dist;
}

void mark(vii& mindist, vi& dist, int c){
    for(int i=0; i<dist.size(); i++){
        dist[i] = min(dist[i], mindist[i][c]);
    }
}

void solve(){
    int n; cin >> n;
    vii graph(n, vi());
    vii mindist(n, vi(n, INT_MAX));
    vi req(n-1);
    vi dist(n, INT_MAX);

    int c0; cin >> c0;

    for(int i=0; i<n-1; i++){
        cin >> req[i];
        req[i]--;
    }

    for(int i=0; i<n-1; i++){
        int u,v; cin >> u>> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }

    for(int i=0; i<n; i++)
        mindist[i] = findMinDis(graph , i);
    
    int mn = INT_MAX;
    mark(mindist, dist, c0-1);

    

    for(int i: req){
        mn = min(dist[i], mn);
        cout << mn <<" ";

        mark(mindist, dist, i);
        
        
    }

    
    

    cout << endl;
}





int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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