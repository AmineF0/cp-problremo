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

struct group
{
  int L, R, S;
};
struct reservation
{
  int R, nbr;
  bool operator<(const reservation &rhs) const
  {
    return R < rhs.R;
  }
};

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<group> v(n);
  for (int i = 0; i < n; i++)
  {
    int l, r, s;
    cin >> l >> r >> s;
    v[i] = {l, r, s};
  }
  sort(v.begin(), v.end(), [](group a, group b)
       { return a.L < b.L; });

  multiset<int> empty;
  priority_queue<reservation> pq;

  for (int i = 0; i < m; i++)
  {
    int r;
    cin >> r;
    empty.insert(r);
  }

  int ans = 0;


  for (auto g : v)
  {
    while (!pq.empty() && pq.top().R < g.L)
    {
      empty.insert(pq.top().nbr);
      pq.pop();
    }
    auto it = empty.lower_bound(g.S);
    if (it == empty.end())
      continue;

    ans++;
    empty.erase(it);
    pq.push({g.R, *it});
  }

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