#include <bits/stdc++.h>
using namespace std;

int f(int n,int k){
	if(k==0||n==k)return 1;
	return f(n-1,k)+f(n-1,k-1);
}
int main(){
	int n,k;
	while(cin>>n>>k){
		cout<<f(n,k)<<'\n';
	}
}


//C(n,k)=C(n-1,k)+C(n-1,k-1),
