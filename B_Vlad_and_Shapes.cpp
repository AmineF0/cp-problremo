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
  int n;
  cin >> n;
  ll ans = 0;

  vector<string> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  int x = 0;
  vector<int> a(n, 0);
  int cnt = 0;
  bool f = true;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
      if (v[i][j] == '1')
        a[i]++, sum++;
    }
    if (cnt != a[i] && a[i] != 0 && cnt != 0)
      f = false;
    cnt = max(cnt, a[i]);
  }

  cout << (f ? "SQUARE" : "TRIANGLE") << endl;
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
