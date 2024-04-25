#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n+1] = {};
	set<int> gp[n] = {};
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		gp[i%k].insert(arr[i]);
	}
	int miss = 0;
	for(int i = 1;i<=n;i++){
		if(gp[i%k].find(i)!= gp[i%k].end())arr[i] = i,gp[i%k].erase(i);
		else{
			miss++;
		}
	}
	/*
	for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';
	cout<<'\n';

   */
	bool flag = true;
	for(int i = 1;i<=n;i++)if(i != arr[i])flag = false;
	if(flag)cout<<0<<'\n';
	else if(!flag&&miss == 2)cout<<1<<'\n';
	else cout<<-1<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
