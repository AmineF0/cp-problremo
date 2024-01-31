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


struct SegTree
{
  vector<int> t;
  vector<bool> marked;
  SegTree(int n)
  {
    t.assign(4 * n, 0);
    marked.assign(4 * n, false);
  }
  void push(int v)
  {
    if (marked[v])
    {
      t[v * 2] =  max(t[v], t[v * 2]);
      t[v * 2 + 1] = max(t[v], t[v * 2 + 1]);
      marked[v * 2] = marked[v * 2 + 1] = true;
      marked[v] = false;
    }
  }

  void update(int v, int tl, int tr, int l, int r, int new_val)
  {
    if (l > r)
      return;
    if (l == tl && tr == r)
    {
      t[v] = max(t[v], new_val);
      marked[v] = true;
    }
    else
    {
      push(v);
      int tm = (tl + tr) / 2;
      update(v * 2, tl, tm, l, min(r, tm), new_val);
      update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
      t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
  }

  int get(int v, int tl, int tr, int pos)
  {
    if (tl == tr)
    {
      return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      return get(v * 2, tl, tm, pos);
    else
      return get(v * 2 + 1, tm + 1, tr, pos);
  }
  int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -1e9;
    if (l == tl && tr == r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
};

struct segTreeRangeAssign
{
  vector<int> t;
  vector<bool> marked;
  segTreeRangeAssign(int n)
  {
    t.assign(4 * n, 0);
    marked.assign(4 * n, false);
  }
  void push(int v)
  {
    if (marked[v])
    {
      t[v * 2] = t[v * 2 + 1] = t[v];
      marked[v * 2] = marked[v * 2 + 1] = true;
      marked[v] = false;
    }
  }

  void update(int v, int tl, int tr, int l, int r, int new_val)
  {
    if (l > r)
      return;
    if (l == tl && tr == r)
    {
      t[v] = new_val;
      marked[v] = true;
    }
    else
    {
      push(v);
      int tm = (tl + tr) / 2;
      update(v * 2, tl, tm, l, min(r, tm), new_val);
      update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
    }
  }

  int get(int v, int tl, int tr, int pos)
  {
    if (tl == tr)
    {
      return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      return get(v * 2, tl, tm, pos);
    else
      return get(v * 2 + 1, tm + 1, tr, pos);
  }
};

void solve()
{
  int q;
  cin >> q;
  vector<ii> v(q);
  int size = 0;
  for (int i = 0; i < q; i++)
  {
    cin >> v[i].first >> v[i].second;
    size = max(size, v[i].first + v[i].second);
  }
  segTreeRangeAssign ft(((size+10) * 2));
  SegTree maxTree(((size+10) * 2));
  for (auto p : v)
  {
    int l = p.second, r = p.second + p.first;
    
    
    // cout << l << r << endl;
    int ansL = ft.get(1, 0, size, l);
    int ansR = ft.get(1, 0, size, r);
    // cout << ansL << " " << ansR << endl;

    if (ansL == ansR && maxTree.query(1, 0, size, l, r) < (ansL + 1))
    {
      cout << "YES" << "\n";
      ft.update(1, 0, size, l, r, ansL + 1);
      maxTree.update(1, 0, size, l, r, ansL + 1);
    }
    else
      cout << "NO" << "\n";
  }

  // for(int i=0; i<=size; i++) cout << ft.get(1, 0, size, i) << " ";

  // cout << endl;
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