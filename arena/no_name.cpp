#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);

class RMQ { // Range Minimum Query
private:
vector<int> _A;
vector<vector<int>> SpT;
public:
RMQ(int n, vector<int>& A) { // constructor as well as pre-processing routine
int MAX_N = n;
int LOG_TWO_N = (int)floor(log((double)n) / log(2.0)) + 1;
_A.assign(MAX_N, 0);
SpT.assign(MAX_N, vector<int>(LOG_TWO_N, 0));
for (int i = 0; i < n; i++) {
_A[i] = A[i];
SpT[i][0] = i; // RMQ of sub array starting at index i + length 2^0=1
}
// the two nested loops below have overall time complexity = O(n log n)
for (int j = 1; (1<<j) <= n; j++) // for each j s.t. 2^j <= n, O(log n)
for (int i = 0; i + (1<<j) - 1 < n; i++) // for each valid i, O(n)
  if (_A[SpT[i][j-1]] < _A[SpT[i+(1<<(j-1))][j-1]]) // RMQ
SpT[i][j] = SpT[i][j-1]; // start at index i of length 2^(j-1)
else // start at index i+2^(j-1) of length 2^(j-1)
SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
}
int query(int i, int j) { // this query is O(1)
int k = (int)floor(log((double)j-i+1) / log(2.0)); // 2^k <= (j-i+1)
return min(_A[SpT[i][k]], _A[SpT[j-(1<<k)+1][k]]);
} };

class RMQmax { // Range Max Query
private:
vector<int> _A;
vector<vector<int>> SpT;
public:
RMQmax(int n, vector<int>& A) { // constructor as well as pre-processing routine
int MAX_N = n;
int LOG_TWO_N = (int)floor(log((double)n) / log(2.0)) + 1;
_A.assign(MAX_N, 0);
SpT.assign(MAX_N, vector<int>(LOG_TWO_N, 0));
for (int i = 0; i < n; i++) {
_A[i] = A[i];
SpT[i][0] = i; // RMQ of sub array starting at index i + length 2^0=1
}
// the two nested loops below have overall time complexity = O(n log n)
for (int j = 1; (1<<j) <= n; j++) // for each j s.t. 2^j <= n, O(log n)
for (int i = 0; i + (1<<j) - 1 < n; i++)
  if (_A[SpT[i][j-1]] > _A[SpT[i+(1<<(j-1))][j-1]]) // RMQ
    SpT[i][j] = SpT[i][j-1]; // start at index i of length 2^(j-1)
  else // start at index i+2^(j-1) of length 2^(j-1)
    SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
}
int query(int i, int j) { // this query is O(1)
int k = (int)floor(log((double)j-i+1) / log(2.0)); // 2^k <= (j-i+1)
return max(_A[SpT[i][k]], _A[SpT[j-(1<<k)+1][k]]);
} };


void solve(){
    int n, k; cin >> n >> k;
    vi v = readvi(n);
    RMQ rmq(n, v);
    RMQmax rmqmax(n, v);
    

    // for(int len = n-1; len>=0; len--){
    //     for(int i=0; i+len<n; i++){
    //         int j = i+len;
    //         int minn = rmq.query(i, j);
    //         int maxx = rmqmax.query(i, j);
    //         // cout << i << " " << j << "   " << minn << " " << maxx << endl;
    //         if(maxx-minn<=k){
    //             cout << len+1 << endl;
    //             return;
    //         }
    //     }
    // }

    // binary search over n
    int l=0, r=n;
    int mid = (l+r)/2;
    int ans = 0;
    while(l<=r){
        mid = (l+r)/2;
        bool found = false;
        for(int i=0; i+mid<n; i++){
            int j = i+mid;
            int minn = rmq.query(i, j);
            int maxx = rmqmax.query(i, j);
            // cout << i << " " << j << "   " << minn << " " << maxx << endl;
            if(maxx-minn<=k){
                found = true;
                ans = mid+1;
                break;
            }
        }
        if(found) l=mid+1;
        else r=mid-1;
    }

    cout << ans << endl;
}

void solve2(){
    int n, k; cin >> n >> k;
    vi v = readvi(n);
    multiset<int> s;
    int ans = 0;
    int i=0, j=0;
    while(j<n){
        s.insert(v[j]);
        while(*s.rbegin()-*s.begin()>k){
            s.erase(s.find(v[i]));
            i++;
        }
        ans = max(ans, j-i+1);
        j++;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    
        solve2();
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