#include<iostream>
#include<map>
#include<iomanip>
#include<vector>
#include <cmath>


using namespace std;


typedef struct node {

    string name;
    map<string, node*> children;
    int acc=0, att=0;

} node;

vector<string> split(string s){
    string cur ="";
    vector<string> vs;
    for(char c : s){
        if(c=='/') vs.push_back(cur);
        else cur += c;
    }
    vs.push_back(cur);
    return vs;
}

void addAtt(node* r, vector<string> vs){
    
    node* cur = r;
    r->att+=1;
    for(string s : vs){
        if(cur->children.find(s) == cur->children.end()){
            cur->children[s] = new node();
            cur->children[s]->name = s;
        }
        cur->children[s]->att+=1;
        cur = cur->children[s];
    }

}



void print(node* r){

    cout << r->name <<" "<<r->att <<" " << r->acc<< " enter : " <<endl;

    for(auto f : r->children){
        print(f.second);
    }

}

void getVal(node * r, vector<string> vs){
    node* f = r;
    for(string s : vs){
        f = f->children[s];
    }

    double d= floor((f->acc*1./f->att)*1e6)/1e6;

    if(f->acc!=0) cout << fixed << setprecision(6) << d << endl;
    else cout << 0 << endl;
}

void childAcc(node* r){
    for(auto f : r->children){
        f.second->acc++;
        childAcc(f.second);
    }
}

void setAcc(node*r , vector<string> vs){
    node* cur = r;
    r->acc+=1;
    for(string s : vs){
        cur->children[s]->acc+=1;
        cur = cur->children[s];
    }
    childAcc(cur);
}

int main(){

    int n, q; cin >> n >> q;

    node* root = new node();
    root->name = "*root*";

    for(int i=0; i<n; i++){
        string s; cin >> s;
        vector<string> vs = split(s);
        addAtt(root, vs);
    }

    for(int i=0; i<q; i++){
        int op; cin >> op;
        string s; cin >> s;
        vector<string> vs = split(s);
        if(op==1){
            setAcc(root, vs);
        } else {
            getVal(root, vs);
        }
    }

    //print(root);


}
