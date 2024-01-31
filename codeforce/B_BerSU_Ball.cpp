#include<bits/stdc++.h>
using namespace std;

int dawi(vector<int> dyour ,int n, double r){
    int poto = 0;
    double lastDawi = -1;

    for(int dar : dyour){
        if(dar > lastDawi) {
            poto++;
            lastDawi = dar+2*r;
        }
    }
    


    return poto <= n;
}

int main(){



}