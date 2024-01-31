#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <stdio.h>
#include <queue>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

//tle
void solve(){
    int n; cin >> n;
    vii con(n, {0,0});
    vi vis(n, 0);
    
    for(int i=0; i<n; i++)
        {int a,b; cin >> a>>b; con[i]={a-1,b-1};}

    queue<int> q, tmp;

    q.push(0);

    int cnt=0;
    while(!q.empty()){
                
        cnt++;
        while(!q.empty()){
            int t = q.front(); q.pop();
            ii g = con[t];
            for(int i=g.first; i<=g.second; i++){
                if(i==n-1){
                    goto STOP;
                }
                if(!vis[i]){
                    tmp.push(i);
                    vis[i]=1;
                }
            }

        }

        swap(tmp, q);
    }

    STOP:
    cout << cnt << '\n';

}


int main(){
    
    int t; cin >> t;
    while(t--) solve();
    

}