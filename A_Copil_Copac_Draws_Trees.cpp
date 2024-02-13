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
struct fast_dsu
{
  const int dsu_MAXN = 100005;
  vector<ll> dsu_par, dsu_sz;

  void init(int n)
  {
    dsu_par.resize(n);
    dsu_sz.resize(n, -1);
    for (int i = 0; i < n; i++)
    {
      dsu_par[i] = i;
    }
  }

  int find(int v)
  {
    // while (v != dsu_par[v]) v = dsu_par[v];
    while ((v = dsu_par[v]) != dsu_par[v])
      ;
    return v;
  }

  bool connected(int v, int u)
  {
    return find(v) == find(u);
  }

  void merge(int v, int u)
  {
    v = find(v);
    u = find(u);

    if (u == v)
      return;

    if (dsu_sz[v] > dsu_sz[u])
    {
      int t = v;
      v = u;
      u = t;
    }

    dsu_par[u] = v;
    dsu_sz[v] += dsu_sz[u];
  }

  ll cluster_size(int v)
  {
    v = find(v);
    return -dsu_sz[v];
  }

  ll count()
  {
    set<int> s;
    for (auto i : dsu_par)
      s.insert(find(i));
    return s.size();
  }
};
void solve()
{
  int n;
  cin >> n;
  ll ans = 0;

  vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
  vi vis(n, 0);
  queue<pair<int, int>> q, qq;

  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back({b, i});
    g[b].push_back({a, i});
    if (a == 0)
      swap(a, b);
    if (b == 0 && q.empty())
    {
      q.push({b, i});
    }
  }

  vis[0] = 1;
  while (!q.empty())
  {
    while (!q.empty())
    {
      pair<int, int> d = q.front();
      int a = d.first;
      int ord = d.second;

      q.pop();
      for (pair<int, int> e : g[a])
      {

        if (vis[e.first])
          continue;
        else
        {
          if (ord <= e.second)
            q.push(e);
          else
            qq.push(e);
          vis[e.first] = 1;
        }
      }
    }
    ans++;
    swap(q, qq);
  }

  cout << ans << endl;
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
    cout << i << "";
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