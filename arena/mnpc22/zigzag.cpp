#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


int main(){
    int n; cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++)
        cin >> v[i];
    

    int ans=0;
    
    vector<vector<int>> d(n, vector<int>(2,0));

    d[n-1][0]=d[n-1][1]=1;
    map<int, int> m, mr; // val -> index

    m[v[n-1]] = n-1;
    mr[-1*v[n-1]] = n-1;

    for(int i=n-2; i>=0; i--){

        auto low = mr.upper_bound(-1*v[i]);
        auto up = m.upper_bound(v[i]);

        if(mr.find(low->first)!=mr.end()){
            d[i][0] = d[mr[low->first]][1];
        }

        if(m.find(up->first)!=m.end()){

            d[i][1] = d[m[up->first]][0];
        }

        m[v[i]] = i;
        mr[-1*v[i]] = i;
    }

    for(int i=0; i<n; i++) {ans += d[i][1];}


    cout << ans << endl;

}