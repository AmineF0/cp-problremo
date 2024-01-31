#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef string S;

typedef vector<int> vi;
typedef vector<vi> vii;

typedef vector<ll> vl;
typedef vector<vl> vll;

typedef map<int,int> mii;
typedef map<int,S> mis;
typedef map<S,int> msi;

typedef set<int> si;
typedef set<S> ss;

vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);ll fact(int n);

void print(vii v){
    for(vi vv : v) print(vv);
}


bool valid(int a, int b, int x, int y){
    return ! (x<0 || y<0 || x>=a || y>=b);
}

bool fill(vii& v, int x, int y, int a, int b){
    vii dir {{0,1},{1,0},{-1,0},{0,-1}};



    vii empty_neighbors;
    int empty_neighbors_count = 0;
    int inv_neighbors = 0;

    int val = v[x][y];

    for(vi d : dir){
        if(valid(a,b,x+d[0], y+d[1])){
            if(v[x+d[0]][y+d[1]]==-1) {
                empty_neighbors_count++;
                empty_neighbors.push_back( { x+d[0],y+d[1] });
            }
            else if(v[x+d[0]][y+d[1]]^1==val) inv_neighbors++; 
        }
    }

    if(inv_neighbors+empty_neighbors_count<2) return false;
    if(inv_neighbors>2) return false;


    int to_fill=2-inv_neighbors;

    if(to_fill==0) return true;
    
    for(vi neigh : empty_neighbors){
        v[neigh[0]][neigh[1]] = val;
    }

    if(to_fill==1) {
        
        for(vi neigh : empty_neighbors){
            v[neigh[0]][neigh[1]] = val^1;

            bool fillable = fill(v,x+1,y,a,b) && fill(v,x,y+1,a,b);
            if(fillable) return true;
            else v[neigh[0]][neigh[1]] = val;
        }
        for(vi neigh : empty_neighbors){
            v[neigh[0]][neigh[1]] = -1;
        }

        
    } 
    if(to_fill==2){

        for(int i=0; i<empty_neighbors_count; i++){
            for(int j=0; j<empty_neighbors_count; j++){
                if(i==j) continue;

                v[empty_neighbors[i][0]][empty_neighbors[i][1]] = val^1;
                v[empty_neighbors[j][0]][empty_neighbors[j][1]] = val^1;

                bool fillable = fill(v,x+1,y,a,b) && fill(v,x,y+1,a,b);
                cout << fillable<< x << y<<endl;
                if(fillable) return true;

                else {
                    v[empty_neighbors[i][0]][empty_neighbors[i][1]] = val;
                    v[empty_neighbors[j][0]][empty_neighbors[j][1]] = val;
                }
            }
        }
        for(vi neigh : empty_neighbors){
            v[neigh[0]][neigh[1]] = -1;
        }
        
    }
    return false;

}

int main(){

    int times; cin >> times; 

    for(int oc=0; oc<times; oc++){

        int a , b; cin >> a >> b;
        vii v(a, vi(b,-1));

        v[0][0]=1;
        fill(v, 0, 0, a , b);
        print(v);
        break;

    }



    return 0;
}

vi readvi(int n){
    vi v(n);
    for(int i=0;i <n; i++) cin >> v[i];
    return v;
}

int maxvi(vi v){
    int mx = v[0];
    for(auto i : v) mx = max(mx, i);
    return mx;
}

int minvi(vi v){
    int mx = v[0];
    for(auto i : v) mx = min(mx, i);
    return mx;
}

void print(vi v){
    for(int i : v) cout << i <<" ";
    cout << endl;
}

ll fact(int n){
    int prod=1;
    for(int i=1; i<=n; i++) prod*=i;
    return prod;
}