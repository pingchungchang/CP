#include <bits/stdc++.h>
using namespace std;

int main(){
	int m[8] = {};
	int r[8] = {};
	for(int i =0 ;i<8;i++)cin>>m[i];
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		if(s == "LOAD"){
			int a,b;
			cin>>a>>b;
			r[a] = m[b];
		}
		else if(s == "STORE"){
			int a,b;
			cin>>a>>b;
			m[a] = r[b];
		}
		else if(s == "ADD"){
			int a,b,c;
			cin>>a>>b>>c;
			r[a] = r[b]+r[c];
		}
		else{
			int a,b;
			cin>>a>>b;
			r[a] = r[b];
		}
	}
	cout<<r[0]<<'\n'<<m[0];
}
