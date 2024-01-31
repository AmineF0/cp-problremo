#include<bits/stdc++.h>

using namespace std;

typedef struct node {
    char val;
    int cnt=0;
    node(char v) {val =v ; cnt =1;}
    node(char v, int c) {val =v ; cnt =c;}
    void add() {cnt++;}
} node;

string mult(char c, int cnt){
    string s="";
    while(cnt--) s+=c;
    return s; 
}

string removeDuplicates(string s, int k) {
    list<node> l;
    node n(s[0]);
    for(int i=1; i<s.size(); i++){
        if(n.val==s[i]) n.cnt++;
        else {
            if(n.cnt>=k) {
                cout << "removing" << n.val << endl;
                if(l.size()) {
                    n = l.back();
                    l.pop_back();
                } else n = node(s[i] , 0);
                i--;
            }
            else {
                l.push_back(n);
                n = node(s[i]);
            }
        }
    }
    if(n.cnt<k) l.push_back(n);

    string m = "";

    for (node const& v : l){
        m+= mult(v.val, v.cnt);
    }

    return m;
}


int main(){
    string s; int k;
    cin >> s >> k;
    cout << removeDuplicates(s, k);
}