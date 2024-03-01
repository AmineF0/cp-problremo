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

ll dpf(vector<ii> &v, map<ii, int> &dp, int i, int last)
{
  if (i == v.size())
    return 0;
  if (dp.find({i, last}) != dp.end())
    return dp[{i, last}];
  int ans = 0;

  int take = 0;
  int leave = dpf(v, dp, i + 1, last);
  if (v[i].first > last)
    take = 1 + dpf(v, dp, i + 1, v[i].second);

  return dp[{i, last}] = max(take, leave);
}

void solve()
{
  int n, m;
  cin >> n >> m;
  ll ans = 0;

  vector<pair<int, int>> v(m);
  for (int i = 0; i < m; i++)
  {
    cin >> v[i].first;
    cin >> v[i].second;
  }
  sort(v.begin(), v.end());

  map<ii, int> dp;

  cout << dpf(v, dp, 0, -1) << endl;
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