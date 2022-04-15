#include <iostream>

using namespace std;

int main(){

    int n; // read the number of people

    int ans=0;

    for(int i=0; i<n; i++){ // for each person 
        int person_age ; 
        cin >> person_age ;
        if(person_age > ans ){
            ans = person_age;
        }
    }

    cout << ans; 


    return 0;
}