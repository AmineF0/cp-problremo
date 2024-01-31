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

bool isCycle(map<int, vector<int>> &mss, set<int> &visited, int s)
{
  if (visited.count(s))
    return false;
  if (mss.find(s) == mss.end()){
    visited.insert(s);
    return true;}

  visited.insert(s);
  bool valid = true;
  for (auto d : mss[s])
  {
    valid &= isCycle(mss, visited, d);
  }
  return valid;
}

void solve()
{
  int n;
  cin >> n;
  int cnt = 0;
  map<string, int> trans;
  map<int, vector<int>> mss;
  set<int> s;
  set<int> uniquev;
  bool valid = true;
  for (int i = 0; i < n; i++)
  {
    string a, b;
    cin >> a >> b;
    
    if(trans.find(a)==trans.end()) trans[a]=cnt++;
    if(trans.find(b)==trans.end()) trans[b]=cnt++;

    mss[trans[a]].push_back(trans[b]);

    if (s.count(trans[b]))
      valid = false;
    else
      s.insert(trans[b]);
  }
  
  set<int> not_root;
  for(auto con : mss){
    for(auto neig : con.second){
        not_root.insert(neig);
    }
  }

  set<int> roots;
  for(auto con : mss){
    if(not_root.count(con.first)==0) roots.insert(con.first);
  }

  set<int> vs;

  if(roots.size()==0){
    valid = false;
  }

  for(auto d : roots){
      valid = valid & isCycle(mss,vs, d);
      if(!valid) break;
      vs.insert(d);
  }

  if(vs.size()!=trans.size()){
    valid = false;
  }

  cout << (valid ? "Yes" : "No") << endl;
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