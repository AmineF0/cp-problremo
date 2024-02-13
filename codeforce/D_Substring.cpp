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

ll dfs(vii &g, vi &vis, string &s, int u, bool &loop, vi &forget, vi &dp, char ltr)
{
  forget[u] = 1;
  if (loop)
    return -1;
  if (dp[u] != -1)
    return dp[u];
  ll ans = 0;
  if (g[u].size() == 0)
  {
    return dp[u] = (ltr==s[u]);
  }
  for (auto v : g[u])
  {
    if (vis[v])
    {
      loop = true;
      return -1;
    }
    vis[v] = 1;
    ans = max(ans, dfs(g, vis, s, v, loop, forget, dp, ltr) + (ll)(s[u] == ltr));
    vis[v] = 0;
  }
  return dp[u] = ans;
}

void solve()
{
  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  vii g(n);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
  }
  bool loop = false;

  ll ans = 0;
  
    for(char ltr = 'a'; ltr <='z'; ltr++){
 
        vi vis(n, 0);
    vi forget(n, 0);
    vi dp(n, -1);
       for (int i = 0; i < n; i++)
  {
    if (forget[i])
      continue;
    forget[i] = 1;
    
    ans = max(ans, dfs(g, vis, s, i, loop, forget, dp, ltr));
  }}

  cout << (loop ? -1 : ans) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // int times; cin >> times;
  // for(int oc=0; oc<times; oc++)
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
  cout << " ";
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