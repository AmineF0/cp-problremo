#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
typedef vector<int> vi;


// struct SegTree{
//     vector<unordered_map<int,int>> st;
//     SegTree(int n) {
//         st.assign(4*n, {});   
//     }

//     SegTree(vi& a) {
//         st.assign(4*a.size(), {});
//         build(a, 1, 0, a.size()-1);
//     }

//     void build(vi& a, int v, int tl, int tr) {
//         if (tl == tr) {
//             st[v][a[tl]]++;
//         } else {
//             int tm = (tl + tr) / 2;
//             build(a, v*2, tl, tm);
//             build(a, v*2+1, tm+1, tr);

//             for(auto i : st[v*2]){
//                 st[v][i.first] += i.second;
//             }

//             for(auto i : st[v*2+1]){
//                 st[v][i.first] += i.second;
//             }
//         }
//     }

//     unordered_map<int, int> freq(int v, int tl, int tr, int l, int r) {
//         if (l > r) 
//             return {};
//         if (l == tl && r == tr) {
//             return st[v];
//         }
//         // cout << tl << " " << tr << " " << l << " " << r << endl;
//         int tm = (tl + tr) / 2;

//         unordered_map<int, int> m1 = freq(v*2, tl, tm, l, min(r, tm));
//         unordered_map<int, int> m2 = freq(v*2+1, tm+1, tr, max(l, tm+1), r);

//         for(auto i : m1){
//             m2[i.first] += i.second;
//         }

//         return m2;
//     }
// };


// Mo's algorithm

typedef pair<int,int> ii;
unordered_map<int, int> m;
set<ii> s;
vector<int> v;

void remove(int idx){
    s.erase({m[v[idx]]*v[idx], m[v[idx]]});
    m[v[idx]]--;
    if(m[v[idx]] == 0) m.erase(v[idx]);
    else s.insert({m[v[idx]]*v[idx], m[v[idx]]});
} 
void add(int idx){
    s.erase({m[v[idx]]*v[idx], m[v[idx]]});
    m[v[idx]]++;
    s.insert({m[v[idx]]*v[idx], m[v[idx]]});
}     // TODO: add value at idx from data structure
// give it a const value
int block_size = 320;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    block_size = sqrt(v.size()) + 1;
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure
    


    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
       int mx = 0;
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }

        answers[q.idx] = s.rbegin()->first; // max value
    }
    for(int i : answers) cout << i << "\n";
    return answers;
}

int main() {
      ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    
    
    int n, q; cin >> n >> q;
    v.assign(n, 0);
     for(int i=0; i<n; i++){
        int a; cin >> a;
        v[i]=a;
    }
    // for(int i=0; i<q; i++){
    //     int a, b; cin >> a >> b;
    //     queries.push_back({a,b});
    // }

    // SegTree segmentTree(v);

    // for (const auto& query : queries) {
    //     int L = query.first;
    //     int R = query.second;
    //     unordered_map<int, int> result = segmentTree.freq(1, 0, n-1, L, R);
    //     int mx = 0;
    //     for(auto i : result){
    //         mx = max(mx, i.second*i.first);
    //     }
    //     cout << mx << endl;
    // }


    vector<Query> qs(q);
    for(int i=0; i<q; i++){
        int a, b; cin >> a >> b;
        qs[i] = {a, b, i};
    }

    mo_s_algorithm(qs);
    // for(int i : ans) cout << i << endl;

    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;

// typedef pair<int,int> ii;typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
// vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n); ull binpow(ull a, ull b);template <typename T> bool exist(T& s, int a);



// void solve(){
//     int n, q; cin >> n >> q;

//     vi v = readvi(n);
//     map<ii, int> dp;

//       for(int i=0; i<n ; i++){
//             map<int, int> m;
//             int mx = 0;
//             for(int j=i; j<n; j++){
//                 m[v[j]]++;
//                 mx = max(mx, m[v[j]]*v[j]);
//                 dp[{i, j}] = mx;
//             }
//         }

//     for(int i=0; i<q; i++){
//         int a, b; cin >> a >> b;
//         cout << dp[{a,b}] << endl;
//     }

// }


// int main(){
//     ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//     // int times; cin >> times; 
//     // for(int oc=0; oc<times; oc++)
//         solve();
//     return 0;
// }












// vi readvi(int n){
//     vi v(n);
//     for(int i=0;i <n; i++) cin >> v[i];
//     return v;
// }

// int maxvi(vi v){
//     int mx = v[0];
//     for(auto i : v) mx = max(mx, i);
//     return mx;
// }

// int minvi(vi v){
//     int mx = v[0];
//     for(auto i : v) mx = min(mx, i);
//     return mx;
// }

// void print(vii v){
//     for(vi vv : v) print(vv);
// }

// void print(vi v){
//     for(int i : v) cout << i <<"";
//     cout << endl;
// }

// ull binpow(ull a, ull b) {
//     ull res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a;
//         a = a * a;
//         b >>= 1;
//     }
//     return res;
// }

// ll fact(int n){
//     int prod=1;
//     for(int i=1; i<=n; i++) prod*=i;
//     return prod;
// }

// template <typename T> bool exist(T& s, int a){
//     return s.find(a) != s.end();
// }