#include<bits/stdc++.h>
using namespace std;

pair<int, int> moveToObs(vector<string>& v, int x, int y, int dir){
  if(dir==0)
    while(y>0 && v[x][y-1]!='#')
      y--;
  
  if(dir==1)
    while(x<v.size()-1 && v[x+1][y]!='#')
      x++;
  
  if(dir==2)
    while(y<v[0].size()-1 && v[x][y+1]!='#')
      y++;  
  
  if(dir==3)
    while(x>0 && v[x-1][y]!='#')
      x--;
  
  return {x,y};
}

void solve(){
  int n,m; cin >> n >> m;
  vector<string> v(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  if(n==1 && m==1){
    cout << 0 << endl;
    return;
  }

  queue<pair<pair<int, int>, int>> q;
  /*
    0 - up
    1 - right
    2 - down
    3 - left
  */
  q.push({{n-1,0}, 1});

  vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(4, 0)));

  // visited[n-1][0][1] = 1;

  queue<pair<pair<int, int>, int>> q2;
  int cnt = 0;
  while(!q.empty()){
    while(!q.empty()){
      pair<pair<int, int>, int> u = q.front(); q.pop();
      int x = u.first.first;
      int y = u.first.second;
      int dir = u.second;
      // cout << x << " " << y << " " << dir << endl;
      
      vector<int> dirs = {1,-1};

      for(int i=0; i<dirs.size(); i++){
        int new_dir = (dir+dirs[i]+4)%4;
        pair<int, int> new_pos = moveToObs(v, x, y, new_dir);
        int new_x = new_pos.first;
        int new_y = new_pos.second;
        // cout << " " << new_x << " " << new_y << " " << new_dir << endl;
        
        if(!visited[new_x][new_y][new_dir]){
          visited[new_x][new_y][new_dir] = 1;
          q2.push({{new_x, new_y}, new_dir});
        }
        if(new_x==0 && new_y==m-1){
          cout << cnt+1 << endl;
          return;
        }
      }
      
    }
    cnt++;
    swap(q, q2);
  }
  cout << -1 << endl;

}

int main(){
  int t; cin >> t;

  while (t--)
  {
    solve();
  }
  

  return 0;
}