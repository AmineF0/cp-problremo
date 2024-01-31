#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
typedef vector<int> vi;
typedef long long ll;


// combinatorics
#define MOD 1000000007

#define N 100005
ll factorial[N];

void precomputeFactorial(){
    factorial[0] = 1;
    for(int i=1; i<N; i++){
        factorial[i] = (factorial[i-1]*i)%MOD;
    }
}

inline long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

inline long long modInv(long long a, long long m) {
    return binpow(a, m - 2);
}

inline long long C(int n, int k) {
    return factorial[n] * modInv(factorial[k] * factorial[n - k] % MOD, MOD) % MOD;
}


// Mo's algorithm

const int MAXN = 100005;
typedef pair<int,int> ii;
unordered_map<int, int> m;

const int block_size = 300;
struct Query {
	int l, r, idx;
	
	inline pair<int, int> toPair() const {
		return make_pair(l / block_size, ((l / block_size) & 1) ? -r : +r);
	}
};

inline bool operator<(const Query &a, const Query &b) {
	return a.toPair() < b.toPair();
}

Query qs[MAXN];
int v[MAXN];
int answers[MAXN];


void mo_s_algorithm(int n, int qn) {
    // block_size = sqrt(v.size()) + 1;
    sort(qs, qs+qn);

    m.clear();

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (int i=0; i<qn; i++) {
        Query q = qs[i];
        int mx = 0;
        while (cur_l > q.l) {
            cur_l--;
            m[v[cur_l]]++;;
        }
        while (cur_r < q.r) {
            cur_r++;
            m[v[cur_r]]++;
        }
        while (cur_l < q.l) {
            m[v[cur_l]]--;
            if(m[v[cur_l]] == 0) m.erase(v[cur_l]);
            cur_l++;
        }
        while (cur_r > q.r) {
            m[v[cur_r]]--;
            if(m[v[cur_r]] == 0) m.erase(v[cur_r]);
            cur_r--;
        }

        ll ans = 1;
        int space = cur_r-cur_l+1;
        ans = factorial[space];
        for(auto i : m){
            ans *= modInv(factorial[i.second], MOD);
            ans %= MOD;
        }

        answers[q.idx] =ans; // max value
    }

    for(int i=0; i<qn ; i++) cout << answers[i]  << "\n";
}

int main() {
  precomputeFactorial();
      ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t; while(t--){
    
    
    int n, q; cin >> n >> q;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        v[i]=a;
    }

    for(int i=0; i<q; i++){
        int a, b; cin >> a >> b;
        qs[i] = {a-1, b-1, i};
    }

    mo_s_algorithm(n, q);
    // for(int i : ans) cout << i << endl;


    }
    return 0;
}