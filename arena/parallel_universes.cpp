#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <stdio.h>

using namespace std;


int main(){
    
    int n, s;
    cin >> n >> s;
    vector<int> v(s, 0);
    while(n--){
        int a, b;
        for(int i=0; i<s; i++){
            scanf("%d -> %d", &a, &b);
            v[a-1] = b-1;
        }
        int ans=0;
        int cnt=0;
        vector<int> vis(s, 1);

        for(int i=0; i<s; i++){
            if(vis[i]){
                int j=i;
                while(vis[j]) {
                    vis[j]=0;
                    j=v[j];
                    cnt++;
                }
                ans += cnt-1;
                cnt=0;
            }
        }

        cout << ans << endl;
    }
}