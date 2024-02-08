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

void invalid(bool &isValid, string &str, vector<int> comb, int k, int n, string ans, int cnt = 0)
{
  if (!isValid)
    return;
  if (k == n)
    return;
  if (cnt == n)
    return;

  for (int j = 0; j < comb.size(); j++)
  {
    if (comb[j] == n)
      continue;
    int i = k;
    string ansc = ans;
    while (i < str.size() && 'a' + j != str[i])
    {
      i++;
    }
    if (i == str.size())
    {
      isValid = false;
      while(ansc.size() < n)
        ansc += ('a' + j);
      cout << "NO" << endl
           << ansc;
      return;
    }
    else
    {
      comb[j]++;
      ansc += ('a' + j);
      invalid(isValid, str, comb, i + 1, n, ansc, cnt + 1);
      if (!isValid)
        return;
    }
  }
}

void solve()
{
  int n, k, m;
  cin >> n >> k >> m;
  string str;
  cin >> str;
  bool isValid = true;
  vector<int> comb(k);

  invalid(isValid, str, comb, 0, n, "");

  if (isValid)
    cout << "YES";

  cout << endl;
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