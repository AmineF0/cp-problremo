#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);

ll merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    ll inv_count = 0;
    int i = left;
    int j = mid;
    int k = left;

    while (i < mid && j < right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
            inv_count += mid - i;  // Count the inversions between the two sub-arrays
        }
        k++;
    }

    while (i < mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j < right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int idx = left; idx < right; idx++) {
        arr[idx] = temp[idx];
    }

    return inv_count;
}

ll merge_sort(vector<int>& arr, vector<int>& temp, int left, int right) {
    ll inv_count = 0;
    if (left < right - 1) {
        int mid = (left + right) / 2;
        inv_count += merge_sort(arr, temp, left, mid);
        inv_count += merge_sort(arr, temp, mid, right);
        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

void solve(){
    int n; cin >> n;
    vi v = readvi(n);
    vi tmp(n,0);
    ll ans =merge_sort(v, tmp, 0, n);

    
    cout << ans << endl;
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