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

vi readvi(int n);int maxvi(vi v);int minvi(vi v);void print(vi v);ll fact(int n);

int dpf(string& s, int i, int j, int cnt, int rem){
    if(i>j || cnt == 0) return max(cnt,rem);

    if(s[i] == '0') return dpf(s, i+1, j, cnt-1, rem);
    if(s[j] == '0') return dpf(s, i, j-1, cnt-1, rem);

    int takeL=1000000,
        takeR =1000000;

                int cost1=0, cost2=0;
                int d,l;
                for(d=i; s[d]!='0'; d++){cost1++;}
                for(l=j; s[l]!='0'; l--){cost2++;}


                if(cost1+rem<cnt)  
                        takeL = dpf(s, d, j, cnt, rem+cost1);
                if(cost2+rem<cnt) takeR = dpf(s, l, j, cnt, rem+cost2);


    return  min(max(cnt,rem), min(takeL, takeR));

}

int main(){

    int times; cin >> times; 

    for(int oc=0; oc<times; oc++){
        string s; cin >> s;
        int cnt=0; int rem = 0;
        for(char c : s) if(c=='0') cnt++;
        int i=0, j=s.size()-1;

        
        while(cnt){
            if(s[i]=='0') i++,cnt--;
            else if(s[j]=='0') j--,cnt--;
            else {
                int cost1=0, cost2=0;
                int d,l;
                for(d=i; s[d]!='0'; d++){cost1++;}
                for(l=j; s[l]!='0'; l--){cost2++;}
                if(cost1<cost2){
                    if(cost1+rem>=cnt) break; 
                    else {
                        rem+=cost1;
                        i=d;
                    }
                } else {
                    if(cost2+rem>=cnt) break; 
                    else {
                        rem+=cost2;
                        j=l;
                    }
                }
            }

        }

        cout << max(rem, cnt) << endl;


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

ll fact(int n){
    int prod=1;
    for(int i=1; i<=n; i++) prod*=i;
    return prod;
}