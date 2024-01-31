#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
#define INF 100000000
typedef pair<int , int> ii;
typedef pair<int , pair<int, int>> iii;


int dpf(vii& mp, int si, int sj, int ei, int ej){

    vii dir = {{1,0},{0,1},{-1,0},{0,-1}};


    vii dist(mp.size(), vi(mp[0].size(), INF)); dist[si][sj] = mp[si][sj]|mp[ei][ej]; // INF = 1B to avoid overflow
    priority_queue< iii, vector<iii>, greater<iii> > pq; pq.push(iii(mp[si][sj], {si,sj}));
    while (!pq.empty()) { // main loop
        iii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
        int d = front.first; ii u = front.second;
        int i=u.first, j=u.second;
        
        if (d > dist[i][j]) continue; // this is a very important check
        for (vi di : dir) {
            
            if(i+di[0]<0 || j+di[1]<0 || i+di[0]>=mp.size() || j+di[1]>=mp[i].size()) continue;
            if ((dist[i][j] | mp[i+di[0]][j+di[1]]) < dist[i+di[0]][j+di[1]]) {
                
                dist[i+di[0]][j+di[1]] = (dist[i][j] | mp[i+di[0]][j+di[1]]); // relax operation
                pq.push(iii(dist[i+di[0]][j+di[1]], {i+di[0], j+di[1]}));
            } 
        } 
    }

    return dist[ei][ej];

    // return dp[i][j]=mn;
}


int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vii mp(n , vi(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> mp[i][j];
            }
        }
        
        int si,sj,ei,ej; cin >> si >> sj >> ei >> ej;
        cout << dpf(mp, si-1, sj-1, ei-1, ej-1) << endl;
    }

}