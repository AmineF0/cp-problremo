void dfs(vii& g, vi& visited, vi&a, int v) {
    
    
    visited[v] = true;
    
    for (int u : g[v]) {
        if (!visited[u])
            dfs(g, visited, a, u);
    }
    a.push_back(v);
}

void topological_sort(vii& g, vi& vis, vi&a) {
    for (int i = 0; i < g.size(); ++i) {
        if (!vis[i]) {
            dfs(g, vis, a, i);
        }
    }
    reverse(a.begin(), a.end());
}

bool check_cycle(vii& g, vector<int>& tsort)
{
    unordered_map<int, int> pos;
 
    for(int i=0; i<tsort.size(); i++) 
        pos[tsort[i]] = i;

    for (int i = 0; i < g.size(); i++) {
        for (auto it : g[i]) {
            if (pos[i] > pos[it]) {
                return true;
            }
        }
    }
    return false;
}