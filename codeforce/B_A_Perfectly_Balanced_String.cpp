#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef string S;

typedef vector<int> vi;
typedef vector<vi> vii;

typedef vector<ll> vl;
typedef vector<vl> vll;

typedef map<int,int> mii;
typedef map<int,S> mis;
typedef map<S,int> msi;

typedef set<int> si;
typedef set<S> ss;

vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);

int main(){

    int times; cin >> times; 

    for(int i=0; i<times; i++){
        string s; cin >> s;
        vi freq(26,0);

        bool unique = true;
        int val=-1;
        int vfreq=0;
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
            if( val==-1 ) val = s[i];
            else if(val != s[i]) unique = false;
            vfreq = freq[s[i]-'a'];
        }
        bool repeated= false;
        int v1=-1, v2=-1;
        for(int f : freq){
            if(f==0) continue;
            else if(f!=v1 && f!=v2){
                if(v1==-1) v1=f;
                else if(v2==-1 && (v1-1==f || v1+1==f) ) v2=f;
                else repeated=true; 
            }
        }
        

        if(!repeated || unique) cout << "YES\n";
        else cout << "NO\n";



    }



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

void print(vi v){
    for(int i : v) cout << i <<"";
    cout << endl;
}