#include<bits/stdc++.h>

using namespace std;

typedef struct step{
    int a, b, c;
} step;

step next(step s){
    step n;

    n.a = s.b+s.c;
    n.b = s.a+s.c;
    n.c = s.b+s.a;

    return n;
}

int main(){
    int a0,b0,c0,n;
    cin >> a0 >> b0 >> c0 >> n;

    step s = {a0, b0, c0};

    for(int i=0; i<n; i++){
        s = next(s);
    }

    cout << s.a+s.b+s.c ;
    
}