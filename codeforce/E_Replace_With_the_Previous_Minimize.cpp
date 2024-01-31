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

int lexMin(char c){
    return ( c>'a' ) ? (c-1) : 'z';
}

vi freq(string&s){
    vi v(26,0);
    for(char f: s) v[f-'a']++;
    return v;
}

void change(string& s, char from , char to){
    for(int i=0; i<s.size(); i++) if(s[i]==from) s[i]=to; 
}

char tom(map<char,char>& m, char from){
    char to = 'M';
    while(m.find(from)!=m.end()) {
        to = m[from];
        from = m[from];
    }
    return to;
}

int main(){

    int times; cin >> times; 

    for(int i=0; i<times; i++){
        int n, k; cin >> n >> k;
        string s ; cin >> s;
        int cost=0;
        map<char, char> m;
        for(char c : s){
            while(c!='a'){
                char to = tom(m, c);
                if(to!='M') {
                    change(s, c, to);
                    c=to;
                    continue;
                }
                if(cost>=k) break; 
                change(s, c, c-1);
                cost++;
                m[c]=c-1;
                c=c-1;
            }
        }

        cout << s << endl;


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