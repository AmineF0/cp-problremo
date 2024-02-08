#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void constructST(vector<ll>&nums,vector<ll>&st_min,ll left,ll right,ll pos){
    if(right==left ){
        st_min[pos]=nums[left];
        return;
    }
    long long mid=(left+right)/2;
    cout << left << right << pos << endl;
    constructST(nums,st_min,left,mid,2*pos+1);
    constructST(nums,st_min,mid+1,right,2*pos+2);

    st_min[pos]=st_min[2*pos+1]+st_min[2*pos+2];
}

void updateSTLazy(vector<ll>&st,vector<vector<ll>>&lazymod,vector<ll>&lazyrep,ll upstart, ll upend ,ll left,ll right, ll val, ll pos,bool mod){
    /*
        in this fct i try to update segment tree with 2 ops mod and replace
        param:
            st: vector represent segment tree
            lazymod: matrix each node represents the valeus of mod there
            lazyrep: vector repsent the val to replace
            upstart: the range start
            upend: the range end
            left: the start of st. initial val =0
            right: the end of st. initial val = size()-1;
            val : the value to replace or to mod;
            pos: the position. initail val=0;
            mod: the mode of the op if mod =true then we will aply mod else we will replace
    */
    if(left>right)
        {cout<<1<<endl;
            return;}
    if(lazymod[pos].size()){
        cout<<2<<endl;
        for(int i=0;i<lazymod[pos].size();i++){
            st[pos]%=lazymod[pos][i];
            if(left!=right){
                lazymod[2*pos+1].push_back(lazymod[pos][i]);
                lazymod[2*pos+2].push_back(lazymod[pos][i]);
            }
        }
        lazymod[pos].clear();
    }

    if(lazyrep[pos]){
        cout<<3<<endl;
        st[pos]+=lazyrep[pos];
        if(left!=right){
            lazyrep[2*pos+1]+=lazyrep[pos];
            lazyrep[2*pos+2]+=lazyrep[pos];
        }
        lazyrep[pos]=0;
    }
    if(upstart>right||upend<left)
        {cout<<upstart<<" "<<upend<<" "<<right<<" "<<left<<endl;return;}
    if(upstart<=left && upend>=right && mod){
        st[pos]%=val;
        if(left!=right){
            cout<<pos<<endl;
            lazymod[2*pos+1].push_back(val);
            cout<<5<<endl;
            lazymod[2*pos+2].push_back(val);
        }
        return;
    }
    if(upstart<=left && upend>=right && !mod){
        cout<<6<<endl;
        st[pos]+=val;
        if(left!=right){
            lazyrep[2*pos+1]+=val;
            lazyrep[2*pos+2]+=val;
        }
        return;
    }

    ll mid=(left+right)/2;
    updateSTLazy(st,lazymod,lazyrep,upstart,
    upend,left,mid,val,2*pos+1,mod);
    updateSTLazy(st,lazymod,lazyrep,upstart,
    upend,mid+1,right,val,2*pos+2,mod);
    st[pos]=st[2*pos+1]+st[2*pos+2];
}

ll query(vector<ll>&st,vector<vector<ll>>&lazymod,vector<ll>&lazyrep,
        ll qstart,ll qend,ll left,ll right,ll pos){

    if(left>right)
        return 0;
    
    if(lazymod[pos].size()){
        for(int i=0;i<lazymod[pos].size();i++){
            st[pos]%=lazymod[pos][i];
            if(left!=right){
                lazymod[2*pos+1].push_back(lazymod[pos][i]);
                lazymod[2*pos+2].push_back(lazymod[pos][i]);
            }
        }
        lazymod[pos].clear();
    }

    if(lazyrep[pos]){
        st[pos]+=lazyrep[pos];
        if(left!=right){
            lazyrep[2*pos+1]+=lazyrep[pos];
            lazyrep[2*pos+2]+=lazyrep[pos];
        }
        lazyrep[pos]=0;
    }

    if(qstart>right || qend<left)
        return 0;
    ll mid = (left+right)/2;
    return query(st,lazymod,lazyrep,qstart,qend,left,mid,2*pos+1)+
    query(st,lazymod,lazyrep,qstart,qend,mid+1,right,2*pos+2);
}

int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll>nums;
    for(int i=0;i<n;i++){
        int tmp;cin>>tmp;
        nums.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    ll stsize=4*pow(2,ceil(log(nums.size())))*2-1;
    cout<<stsize<<endl;
    vector<ll>st(stsize);
    constructST(nums,st,0,nums.size()-1,0);
    for(int i=0;i<st.size();i++){
        cout<<st[i]<<' ';
    }
    cout<<endl;
    vector<vector<long long >> lazymod(stsize,vector<ll>());
    for(int i=0;i<lazymod.size();i++){
        lazymod[i].push_back(9);
    }
    for(int i=0;i<lazymod.size();i++){
        for(int j=0;j<lazymod[i].size();j++){
            cout<<lazymod[i][j]<<" ";
        }
    }


}
