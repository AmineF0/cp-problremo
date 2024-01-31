#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

vii graph;
vi dfs_low, dfs_num, st, visited;
int dfs_count;

int solve(int u){
    
    dfs_low[u] = dfs_num[u] = dfs_count++;
    st.push_back(u);
    visited[u]=1;

    for(int edge : graph[u]){
        if(dfs_num[edge]==-1)
            solve(edge);
        
        if(visited[edge]==1)
            dfs_low[u] = min(dfs_low[u], dfs_low[edge]);
    }

    if(dfs_low[u] == dfs_num[u]){
        while(st.size()){
            int v = st.back(); st.pop_back();
            visited[v]=0;
            if(u==v) break;
        }
    }
}


int main(){
    int nm=0; cin >> nm;
    while(nm--){

        int n,m; cin >> n >> m;

        graph.assign(n,vi());
        dfs_low.assign(n,0);
        dfs_num.assign(n,-1);
        visited.assign(n,0);
        st.clear();

        dfs_count=0;

        while(m--){
            int a, b;
            cin >> a >> b;

            graph[a-1].push_back(b-1);

        }

        for(int i=0; i<n; i++)
            if(dfs_num[i]==-1)
                solve(i);
        
        set<int> sett;

        for(auto i : dfs_low)
            sett.insert(i);

        cout << sett.size() << endl;

    }
}