#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

vi readvi(int n);


/**
 * @return int
 *  => 1 : sufficient
 *    -1 : not sufficient
 *     0 : exactly
 */
int is_valid(vi& cars, int time, int sandwiches){
    for(int car : cars){
        int sandwich_in_this_car = time/car;
        sandwiches -= sandwich_in_this_car;
        if(sandwiches < 0) return 1;
    }
    if(sandwiches < 0) return 1;
    if(sandwiches > 0) return -1;
    return 0;
}

void solve(){

    int nbr_cars, nbr_sandwiches , distance; cin >> nbr_cars >> nbr_sandwiches >> distance;
    vi cars = readvi(nbr_cars);

    int mn = 0, mx = 1e6;
    int t = mn + (mx-mn)/2;

    while(mn<mx){
        int isv = is_valid(cars, t, nbr_sandwiches);
        if(isv == 1){
            mx = t-1;
            t = mn + (mx-mn)/2;
        }
        else if(isv==-1){
            mn = t+1;
            t = mn + (mx-mn)/2;
        }
        else break;
    }


    cout << t*distance << endl;

}


int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}

vi readvi(int n){
    vi v(n);
    for(int i=0;i <n; i++) cin >> v[i];
    return v;
}