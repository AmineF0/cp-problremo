#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int INF = 1000000000;

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(){
  int tasks, cpu, time_slots=101 ; cin >> tasks >> cpu;
  n = 1 + cpu + time_slots + tasks + 1;

  // graph : source -> cpu -> time -> tasks -> sink
  capacity.assign(n, vector<int>(n, 0));
  adj.assign(n, vector<int>());

  for(int i = 1; i <= cpu; i++){
    capacity[0][i] = INF;
    adj[0].push_back(i);
    adj[i].push_back(0);
  } // connect source to cpu

  for(int i = 1; i <= time_slots; i++){
    for(int j = 1; j <= cpu; j++){
      capacity[j][cpu+i] = 1;
      adj[j].push_back(cpu+i);
      adj[cpu+i].push_back(j);
    } // connect time to cpu
  } 

  for(int i = 1; i <= tasks; i++){
    int s, e; cin >> s >> e;
    for(int j = s; j <= e; j++){
      capacity[cpu+j+1][cpu+time_slots+i] = 1;
      adj[cpu+j+1].push_back(cpu+time_slots+i);
      adj[cpu+time_slots+i].push_back(cpu+j+1);
    }
  }

  for(int i = 1; i <= tasks; i++){
    capacity[cpu+time_slots+i][n-1] = 1;
    adj[cpu+time_slots+i].push_back(n-1);
    adj[n-1].push_back(cpu+time_slots+i);
  } // connect tasks to sink

  // for(int i = 0; i < n; i++){
  //   cout << i << " : ";
  //   for(int j = 0; j < adj[i].size(); j++){
  //     cout << adj[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // for(int i = 0; i < n; i++){
  //   cout << i << " : ";
  //   for(int j = 0; j < adj[i].size(); j++){
  //     cout << capacity[i][adj[i][j]] << " ";
  //   }
  //   cout << endl;
  // }

  cout << (maxflow(0, n-1)==tasks?"Yes":"No") << endl;
}