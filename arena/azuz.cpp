#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin>>n;
	for ( int i=0 ; i<n ; i++){
		string a,b;
		cin>>a>>b;
		if ( a.size()!=b.size() ) cout<<"Azuz is not my leader"<<endl;
		else if( (a[0]!=b[0]) || (a[a.size()-1]!=b[b.size()-1]) ) cout<<"Azuz is not my leader"<<endl;
		else{
			vector <int> v1(26,0),v2(26,0);
			for ( int j=1 ; j<a.size()-1 ; j++) v1[a[j]-'a']++;
			for ( int j=1 ; j<b.size()-1 ; j++) v2[b[j]-'a']++;
			if ( v1==v2){
				cout<<"Awesome anagram"<<endl;
			}else{
				cout<<"Azuz is not my leader"<<endl;
			}
		}
	}
	return 0;
}
