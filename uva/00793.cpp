#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
class UnionFind{
    public:
        vi p, rank;
        UnionFind(){}
        UnionFind(int N){
            p.assign(N, 0);
            rank.assign(N, 0);
            for(int i=0; i<N; i++) p[i]=i;
        }
        int findSet(int i){return (i==p[i])? i : findSet(p[i]);}
        bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
        void joinSet(int i, int j){
            int a=findSet(i), b = findSet(j);
            if(a!=b){
                if(rank[a]>rank[b]) swap(a, b);
                p[b]=a;
                rank[b]++;
            }
        }
};


int main(){
    int t; cin >> t;
    int n;
    string s;
    UnionFind uf = UnionFind();
    int suc=0 , fail=0;
    int tm=0;
    while(cin >> s){
        if(s[0]=='c' || s[0]=='q'){
            int a, b; cin >> a >> b;

            if(s[0]=='c'){uf.joinSet(a,b);}
            else {
                bool sc = uf.isSameSet(a,b);
                if(sc)suc++;else fail++;}


        } else {
            if(tm++>0) cout << suc << "," << fail <<endl << endl;
            suc=0;fail=0;
            n=stoi(s);
            uf = UnionFind(n+1);
        }
    }
    cout << suc << "," << fail <<endl;
    return 0;
}
