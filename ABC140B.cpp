#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n],b[n],c[n-1];
	for(auto &i:a)cin>>i,i--;
	for(auto &i:b)cin>>i;
	for(auto &i:c)cin>>i;
	int ans = 0;
	ans += b[a[0]];
	for(int i = 1;i<n;i++){
		if(a[i] == a[i-1]+1)ans += c[a[i]-1];
		ans += b[a[i]];
	}
	cout<<ans;
}
