#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

int dfs(vii& graph , vi& vis, int i){
    if(vis[i]==0) return 0;
    vis[i]=0;
    int cnt=0;
    for(int edge : graph[i]){
        cnt += dfs(graph, vis, edge);
    }

    return cnt;
}

int main(){
    int n,l;cin>>n>>l;
    vii graph(n, vi());

    while(l--){
        int a, b; cin>>a>>b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }


    int cc = 0;
    vi vis(n, 1);
    for(int i=0; i<n; i++)
        if(vis[i]){
            cc++;
            dfs(graph, vis, i);
        }
    cout << cc-1 << endl;



}
