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

vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);

typedef struct structNode {
    int val;
    vector<structNode*> edge;
    structNode(int v){val=v;}
} structNode;

vii dfs(structNode *root){
    queue<structNode*> q;
    vii v;
    q.push(root);

    while(!q.empty()){
        structNode* t = q.front(); q.pop();
        v.push_back(vi());
        while(t) {
            v[v.size()-1].push_back(t->val);
            for(int i=1; i<t->edge.size(); i++) q.push(t->edge[i]);
            if(t->edge.size())t=t->edge[0];
            else break;
        }

    }


    return v;
}

int main(){

    int times; cin >> times; 

    for(int i=0; i<times; i++){
        int n ; cin >> n;
        vi v = readvi(n);

        vector<structNode*> graph(n , NULL);
        
        for(int i=0; i<n; i++)
            graph[i] = new structNode(i+1);

        
        structNode* root = NULL;

        for(int i=0; i<n; i++){
            structNode* parent = graph[v[i]-1];
            if(i+1==v[i]) {
                root=parent;
                continue;
            }
            parent->edge.push_back(graph[i]);
        }

        vii vv = dfs(root);

        cout << vv.size() << "\n";
        for(vi d : vv){
            cout << d.size() << "\n";
            print(d);
        }
        cout << "\n";

        for(int i=0; i<n; i++)
            delete graph[i];

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
    cout << "\n";
}