#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> ii;
typedef unsigned int ll;
typedef unsigned long long ull;
typedef string S;
typedef vector<long long> vi;
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
 
#define INF 1e8
 
void solve()
{
  ll n;
  cin >> n ;
  ll ans =0;

  vi a = readvi(n);


  
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
 