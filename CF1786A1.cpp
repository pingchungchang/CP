#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int a= 0,b =0 ;
	for(int i = 1;i<=2010;i++){
		if(i%4 == 1||i%4 == 0)a += min(n,i);
		else b += min(n,i);
		n -= min(n,i);
	}
	cout<<a<<' '<<b<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
