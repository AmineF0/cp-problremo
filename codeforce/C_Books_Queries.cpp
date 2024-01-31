#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;typedef unsigned long long ull;typedef string S;typedef vector<int> vi;typedef vector<vi> vii;typedef vector<ll> vl;typedef vector<vl> vll;typedef map<int,int> mii;typedef map<int,S> mis;typedef map<S,int> msi;typedef set<int> si;typedef set<S> ss;
vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);void print(vii v);ll fact(int n);

typedef struct p{int a;
	p(){}
	p(int a){this->a=a;}
} p;

void solve(){
 
    int n; cin >> n;

	map<int, p> m;

	int rightmost=0, leftmost=0;
	
	for(int i=0; i<n; i++){
		char c; int id;
		cin >> c >> id;

		if(c=='?'){
			p k = m[id];
            if(k.a<0){
                cout << min( abs(k.a-leftmost) , abs(k.a-rightmost)  ) << endl;
            } else {
                cout << min( abs(k.a-leftmost)  ,abs(k.a-rightmost) ) << endl;
            }
			
		} else if(c=='L') {
			m[id] = p(--leftmost);
		} else if(c=='R') {
			m[id] = p(++rightmost);
		}
	}
	
    cout << endl;
}
 
 
 
 
 
int main(){
    solve();
    return 0;
}
 
vi readvi(int n){
    vi v(n);
    for(int i=0;i <n; i++) cin >> v[i];
    return v;
}
 
int maxvi(vi v){
    int mx = v[0];
    for(auto i : v) mx = max(mx, i);
    return mx;
}
 
int minvi(vi v){
    int mx = v[0];
    for(auto i : v) mx = min(mx, i);
    return mx;
}
 
void print(vii v){
    for(vi vv : v) print(vv);
}
 
void print(vi v){
    for(int i : v) cout << i <<"";
    cout << endl;
}
 
ll fact(int n){
    int prod=1;
    for(int i=1; i<=n; i++) prod*=i;
    return prod;
}