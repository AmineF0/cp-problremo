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

long long poids(vii &adj, vector<ll> &pd, ll i, vector<int> &vis)
{
  // cout << i << vis[i]<< endl;
  if (vis[i] == 1)
    return 0;
  vis[i] = 1;
  if (adj[i].size() == 1 && vis[adj[i][0]] == 1)
    return pd[i] = 1;
  else
  {
    for (ll j : adj[i])
    {
      // cout << i << " " << j << endl;
      // cout << pd[i] << endl;
      pd[i] += poids(adj, pd, j, vis);
    }
    return pd[i];
  }
}

void solve()
{
  ll n;
  cin >> n;
  vector<ll> w(n);
  for (ll i = 0; i < n; i++)
    cin >> w[i];

  vector<int> vis(n, 0);

  vii adj(n);
  for (ll i = 0; i < n - 1; i++)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<ll> pd(n, 0);
  poids(adj, pd, 0, vis);
  // for (int i = 0; i < n; i++)
  //   cout << pd[i] << " ";
  for (ll i = 0; i < n; i++)
    pd[i] *= (ll)w[i];

  // find min and turn it 0
  ll min = 0;
  for (ll i = 0; i < n; i++)
    if (pd[i] < pd[min])
      min = i;
  if (pd[min] < 0)
    pd[min] = 0;

  ll ans = 0;
  for (ll i = 0; i < n; i++)
    ans += pd[i];
  cout << ans << endl;

  // cout << endl;
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