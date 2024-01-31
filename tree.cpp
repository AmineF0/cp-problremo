#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
    node(int data_, struct node* left_=NULL, struct node* right_=NULL){
        data = data_;
        left = left_;
        right = right_;
    }
};
typedef struct node node;

void inorder(node * n){
    stack<node*> st;
    st.push(n);
    cout << "In :\n";
    while(! st.empty()){
        while(st.top()->left){
            st.push(st.top()->left);
        }
        node* t = st.top(); st.pop();
        cout << t->data << " ";
        if(t->right) st.push(t->right); 
    }
    cout << endl << endl;
}

void preorder(node * n){
    stack<node*> st;
    st.push(n);
    cout << "Pre :\n";
    while(! st.empty()){
        node* t = st.top(); st.pop();
        cout << t->data << " ";
        if(t->right) st.push(t->right);
        if(t->left) st.push(t->left); 
    }
    cout << endl << endl;
}

void postorder(node * n){
    stack<node*> st;
    st.push(n);
    cout << "Post :\n";
    while(! st.empty()){
        node* t = st.top(); st.pop();
        cout << t->data << " ";
        if(t->right) st.push(t->right);
        if(t->left) st.push(t->left); 
    }
    cout << endl << endl;
}

int main(){
/*
        1
    2       5
  3   4   6

*/
    node* n = new node(1,
        new node(2,
            new node(3),
            new node(4)
        ),
        new node(5,
            new node(6)
        )
    );

    preorder(n);
    inorder(n);


    return 0;
}