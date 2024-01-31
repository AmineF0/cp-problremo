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
        while(1){
            int v = st.back(); st.pop_back();
            visited[v]=0;
            dfs_low[v] = dfs_num[u];
            if(u==v) break;
        }
    }
}


int main(){
    int n,m; cin >> n >> m;
    while(n!=0 && m!=0){
        st.clear();
        dfs_low.assign(n,0);
        dfs_num.assign(n,-1);
        visited.assign(n,0);
        graph.assign(n, vi());
        dfs_count=0;

        for(int l=0; l<m; l++){
            int v, w, p;
            cin >> v >> w >> p;
            if(p==1){
                graph[v-1].push_back(w-1);
            } else if(p==2){
                graph[v-1].push_back(w-1);
                graph[w-1].push_back(v-1);
            }
        }

        for(int i=0; i<n; i++)
            if(dfs_num[i]==-1)
                solve(i);

        bool connected = 1;

        for(int l : dfs_low) {
            if(l!=0) connected=0;}

        cout << connected << endl;

        cin>> n >> m;
    }
    return 0;
}