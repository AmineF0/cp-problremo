#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef string S;
typedef vector<int> vi;
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

pair<int, int> diameter(vii &g, int v, int p, set<int>& visited)
{
  if(exist(visited, v)) return {0, 0};
  int dimm = 0;
  int maxHeight[3] = {-1, -1, -1};

  for (int u : g[v])
  {
    if (u == p)
      continue;
    pair<int, int> m = diameter(g, u, v, visited);
    int d = m.first;
    int h = m.second;
    dimm = max(dimm, d);
    maxHeight[0] = h+1;
    sort(maxHeight, maxHeight + 3);
  }

  for(int i=0; i<3; i++){
    if(maxHeight[i]<0) maxHeight[i]=0;
  }

  dimm = max(dimm, maxHeight[1] + maxHeight[2]);

  return {dimm, maxHeight[2]};
}

vector<int> diameter(vii &g)
{
  int start = 0;
  int last = start;

  queue<int> q, qq;
  vector<bool> visited(g.size(), false);
  q.push(start);
  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    last = v;
    for (int u : g[v])
    {
      if (visited[u])
        continue;
      visited[u] = true;
      qq.push(u);
    }
    if (q.empty())
    {
      swap(q, qq);
    }
  }

  visited.assign(g.size(), false);
  queue<vector<int>> q2, qq2;
  vector<int> lastPath = {};
  q2.push({last});
  visited[last] = true;
  while (!q2.empty())
  {
    vector<int> v = q2.front();
    q2.pop();
    last = v.back();
    for (int u : g[last])
    {
      if (visited[u])
        continue;
      visited[u] = true;
      vector<int> vv = v;
      vv.push_back(u);
      qq2.push(vv);
      lastPath = vv;
    }
    if (q2.empty())
    {
      swap(q2, qq2);
    }
  }

  return lastPath;
}

int maxDepth(vii &g, int i, set<int>& visited)
{
  if (exist(visited, i))
    return 0;
  visited.insert(i);
  int maxDepthi = 0;
  for (int u : g[i])
  {
    maxDepthi = max(maxDepthi, maxDepth(g, u, visited));
  }
  return maxDepthi + 1;
}

vector<int> maxDepth(vii &g, set<int> visited)
{
  vector<int> maxDepthVector(g.size(), 0);
  for (int v : visited)
  {
    for (int u : g[v])
    {
      if (exist(visited, u))
        continue;
      maxDepthVector[v] = max(maxDepth(g, u, visited), maxDepthVector[v]);
    }
  }

  return maxDepthVector;
}

void solve()
{
  int n, q;
  cin >> n >> q;

  vii g(n, vi());

  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> d = diameter(g);
  set<int> s(d.begin(), d.end());
  vector<int> maxDepthVector = maxDepth(g, s);



  int maxHorsDiam = 0;
  for(int i : s){
    for(int u : g[i]){
      if(exist(s, u)) continue;
      maxHorsDiam = max(maxHorsDiam, diameter(g, u, -1, s).first);
    }
  }

  vector<int> pre(d.size()-1, 1), suf(d.size()-1, 0);
  pre[0] = 1 + maxDepthVector[d[0]];
  for (int i = 1; i < pre.size(); i++){
    pre[i] = max(pre[i - 1], i + 1 + maxDepthVector[d[i]]);
  }

  suf[d.size()-2] = 1 + maxDepthVector[d[d.size()-1]];
  for (int i = d.size() - 3; i >= 0; i--){
    suf[i] = max(suf[i + 1], (int)d.size()- i-1 + maxDepthVector[d[i+1]]);
  }

  vector<int> ld(n+1, 0);

  for(int i=0; i<n+1; i++){
    if(i<=maxHorsDiam) {
      ld[i] = d.size();
      continue;
    } else {
      for(int j=0;j<pre.size(); j++){
        if(i<=pre[j]) ld[i] = max(ld[i], suf[j]);
        if(i<=suf[j]) ld[i] = max(ld[i], pre[j]);
      }
    }
  }
  
  for(int t = 0 ; t<q; t++){
    int a,b; cin>> a >> b;
    // cout << a << b << " ";
    if(a<b) swap(a,b);
    if(a>d.size() || b>d.size()){
      cout << "NO\n";
    }
    else {
      if(b<=maxHorsDiam || b<=ld[a]){
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } 
  }

  
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}

vi readvi(int n)
{
  vi v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  return v;
}

int maxvi(vi v)
{
  int mx = v[0];
  for (auto i : v)
    mx = max(mx, i);
  return mx;
}

int minvi(vi v)
{
  int mx = v[0];
  for (auto i : v)
    mx = min(mx, i);
  return mx;
}

void print(vii v)
{
  for (vi vv : v)
    print(vv);
}

void print(vi v)
{
  for (int i : v)
    cout << i << " ";
  cout << endl;
}

ull binpow(ull a, ull b)
{
  ull res = 1;
  while (b > 0)
  {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

ll fact(int n)
{
  int prod = 1;
  for (int i = 1; i <= n; i++)
    prod *= i;
  return prod;
}

template <typename T>
bool exist(T &s, int a)
{
  return s.find(a) != s.end();
}