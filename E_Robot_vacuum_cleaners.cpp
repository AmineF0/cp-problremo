#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> ii;
typedef unsigned int ll;
typedef unsigned long long ull;
typedef string S;
typedef vector<long long> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef map<int, int> mii;
typedef map<int, S> mis;
typedef map<S, int> msi;
typedef set<int> si;
typedef set<S> ss;
vi readvi(int n);
int maxvi(vi v);
int minvi(vi v);
void print(vi v);
void print(vii v);
ll fact(int n);
ull binpow(ull a, ull b);
template <typename T>
bool exist(T &s, int a);
 
#define INF 1e8

typedef struct bs
{
  ll a=0,b=0;
  bool operator<(const bs &other) const
  {
    if(a==other.a) return b<other.b;
    return a<other.a;
  }
  bs operator=(const bs &other)
  {
    a = other.a;
    b = other.b;
    return *this;
  }
  bool operator==(const bs &other) const
  {
    return a == other.a && b == other.b;
  }
} bs;
 
bs visit(bs vis, int i)
{
  if(i>=50){
    vis.a = vis.a | (1<<(i-50));
  } else {
    vis.b = vis.b | (1<<i);
  }
  return vis;
}
 
bool visited_all(bs vis, int n)
{
  bool found = true;
  for (int i = 0; i < min(n, 50); i++)
    found = found & (vis.b>>i);
  for (int i = 50; i < n; i++)
    found = found & (vis.a>>(i-50));
  // cout << found ;
  return found;
}
 
void solve()
{
  ll n, m;
  cin >> n >> m;
 
  vector<vector<pair<int, int>>> adj(n);
  map<ii, int> edge;
 
  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({w, b});
    adj[b].push_back({w, a});
    edge[{a, b}] = i;
    edge[{b, a}] = i;
  }
 
  bs default_str;
 
  ll ans = INF;
 
  for (int s = 0; s < 1; s++)
  {
    vector<map<bs, int>> dist(n, map<bs, int>{}); // first node, second visited => distance
    ll csol = INF;
    dist[s][default_str] = 0; // INF = 1B to avoid overflow
    priority_queue<pair<ii, bs>, vector<pair<ii, bs>>, greater<pair<ii, bs>>> pq;
    pq.push({ii(0, s), default_str});
 
    int c = 0;
    set<pair<ii, bs>> seta;
    while (!pq.empty())
    {
      // if(c++>15)break;
      ii front = pq.top().first;
      bs visited = pq.top().second;
      pq.pop(); // greedy: get shortest unvisited vertex
      ll d = front.first, u = front.second;
      if(d>dist[u][visited]) continue;
      // cout << "u" << u << "d" << d << "visited" << visited.b << "s" << s << endl;
      if (visited_all(visited, m) && u == s)
      {
        cout << d << endl;
        csol = min(csol, d);
        break;
      }
 
      for (int j = 0; j < (int)adj[u].size(); j++)
      {
        ii v = adj[u][j]; // all outgoing edges from u
        bs after_visit = visit(visited, edge[{u, v.second}]);
 
        if (dist[v.second].find(after_visit) == dist[v.second].end())
          dist[v.second][after_visit] = dist[u][visited] + v.first; // relax operation
        else
          dist[v.second][after_visit] = min(dist[v.second][after_visit], dist[u][visited] + v.first); // relax operation
        // cout << after_visit << endl;
        // cout << v.first << v.second <<" "<< dist[v.second][after_visit] << endl;
 
        if (seta.find({ii(dist[v.second][after_visit], v.second), after_visit}) != seta.end())
          continue;

        seta.insert({ii(dist[v.second][after_visit], v.second), after_visit});
 
        pq.push({ii(dist[v.second][after_visit], v.second), after_visit});
      }
    }
    ans = min(ans, csol);
  }
 
  // cout << ans << endl;
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  int times;
  cin >> times;
  for (int oc = 0; oc < times; oc++)
    solve();
  return 0;
}
 