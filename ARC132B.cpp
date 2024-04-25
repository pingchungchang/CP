#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	int f,e;
	for(int i = 0;i<n;i++){
		cin>>v[i];
		if(v[i] == 1)f=i;
		if(v[i] == n)e = i;
	}
	if(abs(e-f)!=1){
		if(e>f)cout<<0;
		else cout<<1;
	}
	else{
		if(e>f){
			cout<<min(f+1+1,1+(n-1)-e+1);
		}
		else{
			cout<<min(e+1,1+(n-1)-f+1+1);
		}
	}
	return 0;
}
