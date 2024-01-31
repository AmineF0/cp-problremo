#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int k;cin>>k;
    while(k--){
        int n;cin>>n;
        set<int > s;
        set<int>tmp, tmp2;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x;cin>>x;
            v.push_back(x);
            s.insert(x);
            tmp.insert(x);
        }
        int ans=n-s.size();
        set<int> not_first_encouter;
        for(int i=0; i<n; i++){
            if(!not_first_encouter.count(v[i])){not_first_encouter.insert(v[i]); continue;}
            int t=v[i];
            
            if(tmp.size()<n) 
            	if((t)%10>0 && tmp.count(t-1)==0) {tmp.insert(t-1);v[i]=t-1;continue;}
            if(tmp.size()<n) 
            	if((t)%10<9 && tmp.count(t+1)==0) {tmp.insert(t+1);v[i]=(t+1);continue;}
            if(tmp.size()<n) 
            	if((t/10)%10>0 && tmp.count(t-10)==0) {tmp.insert(t-10);v[i]=(t-10);continue;}
            if(tmp.size()<n) 
            	if((t/10)%10<9 && tmp.count(t+10)==0) {tmp.insert(t+10);v[i]=(t+10);continue;}
            if(tmp.size()<n)
            
            	if((t/100)%10>0 && tmp.count(t-100)==0) {tmp.insert(t-100);v[i]=(t-100);continue;}
            if(tmp.size()<n) 
            	if((t/100)%10<9 && tmp.count(t+100)==0) {tmp.insert(t+100);v[i]=(t+100);continue;}
            if(tmp.size()<n) 
            	if((t/1000)%10>0 && tmp.count(t-1000)==0) {tmp.insert(t-1000);v[i]=(t-1000);continue;}
            if(tmp.size()<n) 
            	if((t/1000)%10<9 && tmp.count(t+1000)==0) {tmp.insert(t+1000);v[i]=(t+1000);continue;}
            
            if(tmp.size()<n) 
            	if((t)%10>1 && tmp.count(t-2)==0) {tmp.insert(t-2);v[i]=(t-2);continue;}
            if(tmp.size()<n) 
            	if((t)%10<8 && tmp.count(t+2)==0) {tmp.insert(t+2);v[i]=(t+2);continue;}
            if(tmp.size()<n) 
            	if((t/10)%10>1 && tmp.count(t-20)==0) {tmp.insert(t-20);v[i]=(t-20);continue;}
            if(tmp.size()<n) 
            	if((t/10)%10<8 && tmp.count(t+20)==0) {tmp.insert(t+20);v[i]=(t+20);continue;}

            if(tmp.size()<n) 
            	if((t/100)%10>1 && tmp.count(t-200)==0) {tmp.insert(t-200);v[i]=(t-200);continue;}
            if(tmp.size()<n) 
            	if((t/100)%10<8 && tmp.count(t+200)==0) {tmp.insert(t+200);v[i]=(t+200);continue;}
                        if(tmp.size()<n) 
            	if((t/1000)%10>1 && tmp.count(t-2000)==0) {tmp.insert(t-2000);v[i]=(t-2000);continue;}
            if(tmp.size()<n) 
            	if((t/1000)%10<8 && tmp.count(t+2000)==0) {tmp.insert(t+2000);v[i]=(t+2000);continue;}

            if(tmp.size()<n)
                
                	if((t)%10>2 && tmp.count(t-3)==0) {tmp.insert(t-3);v[i]=(t-3);continue;}
            if(tmp.size()<n)
                    
                    	if((t)%10<7 && tmp.count(t+3)==0) {tmp.insert(t+3);v[i]=(t+3);continue;}
            if(tmp.size()<n)
                        
                        	if((t/10)%10>2 && tmp.count(t-30)==0) {tmp.insert(t-30);v[i]=(t-30);continue;}
            if(tmp.size()<n)
                            
                            	if((t/10)%10<7 && tmp.count(t+30)==0) {tmp.insert(t+30);v[i]=(t+30);continue;}
            if(tmp.size()<n)
                                
                                	if((t/100)%10>2 && tmp.count(t-300)==0) {tmp.insert(t-300);v[i]=(t-300);continue;}
            if(tmp.size()<n)
                                    
                                    	if((t/100)%10<7 && tmp.count(t+300)==0) {tmp.insert(t+300);v[i]=(t+300);continue;}
            if(tmp.size()<n)
                                        
                                        	if((t/1000)%10>2 && tmp.count(t-3000)==0) {tmp.insert(t-3000);v[i]=(t-3000);continue;}
            if(tmp.size()<n)
                                            
                                            	if((t/1000)%10<7 && tmp.count(t+3000)==0) {tmp.insert(t+3000);v[i]=(t+3000);continue;}
                                                
                                        
        
        }
        
        cout<<ans<<endl;
        for(auto i:v){
            if(i<10){
                cout<<"000"<<i<<endl;
            }
            else if(i<100){
                cout<<"00"<<i<<endl;
            }
            else if(i<1000){
                cout<<"0"<<i<<endl;
            }
            else{
                cout<<i<<endl;
            }
        }
 
 
    }
}