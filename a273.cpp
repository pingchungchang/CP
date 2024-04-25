#include <bits/stdc++.h>
using namespace std;

int f(int n,int m){
	if(m == 0)return n;
	n -= (n/m)*m;
	return f(m,n);
}
int main(){
	int n,m;
	while(cin>>n>>m){
		if(n<m)swap(n,m);
		cout<<f(n,m)<<'\n';
	}
}
