#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct fast_dsu {
	const int dsu_MAXN = 100005;
	vector<ll> dsu_par, dsu_sz;
 
	void init(int n) {
    dsu_par.resize(n);
    dsu_sz.resize(n, -1);
		for (int i = 0; i < n; i++) {
			dsu_par[i] = i;
		}
	}
 
	int find(int v) {
		// while (v != dsu_par[v]) v = dsu_par[v];
		while ((v = dsu_par[v]) != dsu_par[v]);
		return v;
	}
 
	bool connected(int v, int u) {
		return find(v) == find(u);
	}
 
	void merge(int v, int u) {
		v = find(v);
		u = find(u);

        if(u==v) return;
		
		if (dsu_sz[v] > dsu_sz[u]) {
			int t = v;
			v = u;
			u = t;
		}
		
		dsu_par[u] = v;
		dsu_sz[v] += dsu_sz[u];
	}

    ll cluster_size(int v){
        v = find(v);
        return -dsu_sz[v];
    }

    ll count(){
        set<int> s;
        for(auto i : dsu_par)
            s.insert(find(i));
        return s.size();
    }
};