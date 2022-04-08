//#include "import.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;


int isDot(vector<string>& mat, int i, int j){
    if(i<0 || i>=mat.size()|| j<0 || i>=mat[i].size()) return 0;
    return mat[i][j] == '.';
}


int remov=0;

void dfs(vector<string>& mat, int i, int j){
    if(remov<=0 || i<0 || i>=mat.size()|| j<0 || j>=mat[i].size()) return;
    if(mat[i][j]!='.') return;
    
    vvi steps = {{0,1},{1,0},{-1,0},{0,-1}};

    mat[i][j] = 'O';
    for(auto step : steps) dfs(mat, i+step[0], j+step[1]);
    mat[i][j] = '.';

    int count = 0;
    for(auto step : steps) count += isDot(mat, i+step[0], j+step[1]);
    
    if(count == 0 && remov > 0) {
        remov--;
        mat[i][j] = 'X';
        return;
    }


}

int main(){
    int a,b,c; cin >> a >> b >> c;

    vvi visited;
    remov = c;
    vector<string> mat(a, "");

    for(int i=0; i<a; i++) cin >> mat[i];

    for(int i=0; i<a; i++) for(int j=0; j<b;j++) dfs(mat, i, j);
    
    for(int i=0; i<a; i++) cout << mat[i] << endl;

    return 0;
}