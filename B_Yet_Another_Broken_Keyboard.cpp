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

void solve()
{
  int n, l;
  cin >> n >> l;
  string s;
  cin >> s;
  vector<bool> v(26, false);
  for (int i = 0; i < l; i++)
  {
    char f;
    cin >> f;
    v[f - 'a'] = true;
  }
  ll ans = 0;

  vector<ll> dp(n, 0);
  dp[0] = 1;
  for (int i = 1; i < n; i++)
    dp[i] = dp[i - 1] + (i+1);

  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    // cout << i << ans << endl;
    if (v[s[i] - 'a'])
      cnt++;
    else
    {
      if(cnt > 0) ans += dp[cnt-1];
      cnt = 0;
    }
  }
  if(cnt > 0) ans += dp[cnt-1];

  cout << ans << endl;
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