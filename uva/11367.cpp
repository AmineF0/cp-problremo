#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef pair<int , ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main(){
    int n, m;
    cin >> n >> m;
    vi prices(m,0);
    for(int i=0; i<n; i++) cin >> prices[i];
    vvii roads(n, vii());
    for(int i=0; i<m ; i++){
        int u, v, w; cin >> u >> v >> w;
        roads[u].push_back({v, w});
    }

    int q; cin >> q;
    for (int i = 0; i <q ; i++){
        int c, s, e; cin >> c >> s >> e;
        priority_queue<ii> pq;
        vi dist(n, INT_MAX);

        pq.push(ii(s, 0));

        while(!pq.empty()){
            
            ii f = pq.top(); pq.pop();
            int d= f.first, u=f.second;

            if(d>dist[u]) continue;

            for(ii edge : roads[u]){
                if(edge.second + dist[u] < dist[edge.first]){
                    dist[edge.first] = edge.second + dist[u] ;
                    pq.push(ii(dist[edge.first], edge.first));
                }
            }


        }

        cout << (dist[e]==INT_MAX ?  "impossible" : ""+dist[e]) << endl;
    }
    


    return 0;
}
