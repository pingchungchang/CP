#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	if(n<m*2+1){
		cout<<-1<<'\n';
		return;
	}
	int ans[n+1] = {};
	int c = 1;
	for(int i = 0;i<=m*2;i+=2)ans[i] = c++;
	for(int i = 1;i<=m*2;i+=2)ans[i] = c++;
	for(int i = m*2+1;i<n;i++)ans[i] = c++;
	for(int i = 0;i<n;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
