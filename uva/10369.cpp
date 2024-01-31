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
        int numberOfSets(){
            set<int> s;
            for(int i=0; i<v.size(); i++) s.insert(findSet(i));
            return s.size();
        }
};

double dis(ii a, ii b){
    return sqrt(pow(a.first-b.first, 2) + pow(a.second-b.second,2));
}

int main(){
    int N; cin >> N ;

    while(N--){

        int s, n; cin >> s >> n;

        UnionFind UF(n);

        vector<ii> pos;
        for(int i=0; i<n; i++){
            int x,y; cin >> x >> y;
            pos.push_back({x,y});
        }


        vector<pair<double, ii>> Edges;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                Edges.push_back({dis(pos[i], pos[j]), ii(i, j)});
            }
        }

        sort(Edges.begin(), Edges.end());

        double mx=0;
        
        for(int i=0; i<Edges.size(); i++){
            pair<double, ii> p = Edges[i];

            if(UF.numberOfSets()==s) break;

            if(!UF.isSameSet(p.second.first, p.second.second)){
                mx = max(mx, p.first);
                UF.joinSet(p.second.first, p.second.second);
            }

        }
        cout << fixed << setprecision(2) << mx << endl;
        
        
    }


}

class fiboDp{
    vi fib;
    fiboDp(){
        fib.assign(2, 1);
    }
    int getFib(vi& fib , int n){
        int n=n+1;
        if(fib.size()<2) fib.assign(2, 1);
        for(int i=fib.size(); i<n+1; i++){
            fib.push_back(fib[i-1]+ fib[i-2]);
        }
        return fib[n];
    }
};