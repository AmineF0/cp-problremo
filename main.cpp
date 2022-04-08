#include <iostream>
using namespace std;

typedef struct elem {
    int val;
    elem* next = NULL;
} elem;

elem* ajouter_fin(elem* head, int val){
    elem* e = new elem;
    e->val = val;
    
    if(head == NULL) return e;

    elem* tmp = head;
    while(tmp->next) tmp = tmp->next;
    tmp->next = e;
    return head;
}

elem* inserer(elem* head, int position, int val){
    if(position==0 || head == NULL) {
        elem* e = new elem;
        e->val = val;
        return e;
    }

    elem* tmp = head;
    int i=0;

    while(tmp->next && i<position) tmp = tmp->next; // chercher position d insertion

    
    elem* nw = new elem;
    nw->val = val;

    nw->next = tmp->next;
    tmp->next = nw;

    return head;
}

elem* ecrire(elem* head){
    cout << " la liste : ";
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

elem* sort(elem* head){



    return head;
}

elem* lire(){
    elem* head = NULL;
    int val, pos;
    cout << "voulez vous ajouter des elements (o/n)? : ";
    char decision; cin >> decision;
    while(decision == 'o'){
        cout << "ecrire la valeur : ";
        cin >> val;
        cout << "ecrire position d insertion :";
        cin >> pos;
        head = inserer(head, pos, val);
        cout << "voulez vous ajouter des elements (o/n)? : ";
        cin >> decision;
    }
    ecrire(head);
    return head;

}

int main(){
    lire();
}