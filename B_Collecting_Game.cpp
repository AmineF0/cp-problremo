#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);


void solve(){
    int n; cin >> n;
    // ll ans = 0;
    vi v= readvi(n);
    vi ans(n, -1);

    vector<pair<int, int>> arr(n);

    for(int i=0; i<n ; i++){
      arr[i] = {v[i],i};
    }

    sort(arr.begin(), arr.end());

    vl prefix_sum(n, 0);
    map<ll, ll> cont;
    prefix_sum[0] = arr[0].first;
    cont[arr[0].second] = arr[0].second;

    for(int i=1; i<n ; i++){
      prefix_sum[i] = prefix_sum[i-1] + arr[i].first;
      cont[arr[i].first] = prefix_sum[i];
    }

    vl ar(n, 0);
    for(int i=0; i<n ;i++) ar[i]= arr[i].first;

    for(int i=0; i<n; i++){
      int ind = arr[i].second, val = arr[i].first;
      ll ps = prefix_sum[i];
      int prev = ind;
      cout << ind <<" - " << val<< endl;
      int nxt = (lower_bound(ar.begin(), ar.end(), ps)-ar.begin());
      if(nxt == ar.size()) nxt--;
      while(nxt+1 < ar.size() && ar[nxt] == ar[nxt+1]) nxt++;
      while(nxt != prev){
        ps = prefix_sum[nxt];
        prev = nxt;
        cout << nxt << " "<< ps << endl;
        nxt = (lower_bound(ar.begin(), ar.end(), ps)-ar.begin());
        if(nxt == ar.size()) nxt--;
      }

      ans[ind] = nxt;
      cout << endl;
    }

    print(ans);
    // cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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
    for(int i : v) cout << i <<" ";
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