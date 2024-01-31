#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vii;
typedef vector<int> vi;

void find_bridges(vii& v, vi& dfs_low, vi& dfs_num, vi& dfs_parents, int u, int& dfs_counter, int& root_counter, int root, vi& articulations){
    dfs_low[u]=dfs_num[u]=dfs_counter++;

    for(int edge : v[u]){
        if(dfs_num[edge]==-1){
            dfs_parents[edge] = u;

            if(u == root) root_counter++;

            find_bridges(v, dfs_low, dfs_num, dfs_parents, edge, dfs_counter, root_counter, root, articulations);

            if(dfs_low[edge]>=dfs_num[u]){
                articulations[u]=1;
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[edge]);

        } else if(edge != dfs_parents[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[edge]);
        }
    }

}

int solve(vii& v){
    int bridges = 0;
    vi dfs_low(v.size(),0), dfs_num(v.size(),-1),dfs_parents(v.size(),-1),articulations(v.size(),0);
    
    int dfs_counter=0, root_counter=0, root=0, articulation=0;

    for(int i=0; i<v.size(); i++) if(v[i].size()){root=i; break;}

    find_bridges(v, dfs_low, dfs_num, dfs_parents, root, dfs_counter, root_counter, root, articulations);

    articulations[root] = (root_counter>1);
    
    for(int a : articulations) articulation+=a;
    
    return articulation;
}

// int solve(vii& v){
//     int bounds=0;

    
//     for(int i=0; i<v.size(); i++){
//         if(v[i].size()>1) bounds++;
//     }

//     return bounds;

// }

int main(){
    int n; cin >> n;
    while(n!=0){
        vii v(n, vi());
        int u; cin >> u;
        string line;
        getline( cin, line );
        while(u!=0){
            istringstream iss( line );
            int w;
            while( iss >> w){
                v[u-1].push_back(w-1);
                v[w-1].push_back(u-1);
            }
            cin >> u;
            getline( cin, line );
        }
        cout << solve(v) << endl;
        cin >> n;
    }
    return 0;
}