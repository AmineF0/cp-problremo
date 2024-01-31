#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

class UnionFind{
    public:
        vi v, rank;
        UnionFind(){
        }
        UnionFind(int N){
            v.assign(N, 0);
            rank.assign(N, 0);
            for(int i=0; i<N; i++) v[i]=i;
        }
        int findSet(int i){ return (i==v[i])? i : findSet(v[i]);}
        bool isSameSet(int i, int j){ return findSet(i) == findSet(j);}
        void joinSet(int i, int j){
            if(isSameSet(i,j)) return;
            int x=findSet(i), y=findSet(j);
            if (rank[x] > rank[y]) v[y] = x; // rank keeps the tree short
            else {
                v[x] = y;
                if (rank[x] == rank[y]) rank[y]++; 
            }
        }
};



int main(){
    int N , E; cin >> N >> E;

    while(N!=0){

        vector<pair<long long, ii>> Edges;
        UnionFind UF(N);

        while(E--){
            int u, v, w; cin >> u >> v >> w;
            Edges.push_back(make_pair(w, ii(u,v)));
        }

        sort(Edges.begin(), Edges.end());
        
        bool f=true;
        for(int i=0; i<Edges.size(); i++){
            pair<long long, ii> p = Edges[i];


            if(UF.isSameSet(p.second.first, p.second.second)){ cout<< (f?"":" ") << p.first ;f=false;}
            else UF.joinSet(p.second.first, p.second.second);

        }

        cout << (f?"forest":"") << endl;

        cin >> N >> E;
    }


}