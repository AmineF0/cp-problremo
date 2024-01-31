#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    while(n){
        int cost=0;
        priority_queue<int> pq;
        for(int i=0; i<n; i++) {
            int a; cin>> a;
            pq.emplace(-1*a);
        }

        while(pq.size()>1){
            int d = pq.top() *-1; pq.pop();
            int e = pq.top() *-1; pq.pop();
            
            cost += d+e;
            pq.emplace(-1*(d+e));
            
        }

        cout << cost << endl;

        cin >> n;
    }
    return 0;
}