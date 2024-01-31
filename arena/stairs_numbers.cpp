#include <bits/stdc++.h>
using namespace std;

void getStair(int* start, int num ,int node, int dim, int* end){
    if(num==0 && node==0 && dim!=0) {
        for(int i=0; i<10;i++) {
            getStair(start, 0, i, dim-1, end);
        }
        return;
    }
    if(num >= end[dim] || num < start[dim]) return;
    if(dim == 0) {
        if(num!=0)
         cout << num <<  endl;
        return;
    }
    
    if(node==0) getStair(start, num*10+node, node+1, dim-1, end);
    else if(node==9) getStair(start, num*10+node, node-1, dim-1, end);
    else {
        if(dim!=1){
            getStair(start, num*10+node, node-1, dim-1, end);
            getStair(start, num*10+node, node+1, dim-1, end);
        }
        else getStair(start, num*10+node, node-1, dim-1, end);
    }
}

void init(int start, int end, int* startArr, int* dim,  int* endArr){
    int tmpEnd=end,tmpStart=start,strtDim=0;
    while(tmpEnd!=0){
        tmpEnd/=10;
        (*dim)++;
    }
    while(tmpStart!=0){
        tmpStart/=10;
        strtDim++;
    }
    for(int i=0; i<*dim; i++){
        endArr[i]=end;
        end/=10;
    }
    for(int i=0; i<strtDim; i++){
        startArr[i]=start;
        start/=10;
    }
}

int main(){
    
    int start,end; cin >> start >> end;

    int dim=0;
    int startArr[11], endArr[11];
    memset(startArr, -1, sizeof(startArr[0])*11);
    memset(endArr, 1e9+2, sizeof(endArr[0])*11);
    
    init(start,end,startArr,&dim,endArr);
    
    getStair(startArr, 0, 0, dim+1, endArr);

    return 0;
}