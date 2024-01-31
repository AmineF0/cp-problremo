#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <stdio.h>

using namespace std;
typedef long long ll;

    int maxSubArray(vector<int>& nums) {
        int m = nums[0], s=0;
        for(int i=0; i<nums.size(); i++){
            if(s<0 || s+nums[i]<0) s=nums[i];
            else  s+= nums[i];
            m=max(m,s);
        }
        return m;
    }

int main(){
    
    int n; cin >> n;

    vector<int> v(n); for(int i=0; i<n; i++) cin >> v[i];


    cout << maxSubArray(v);

}