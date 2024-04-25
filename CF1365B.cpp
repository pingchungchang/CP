#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	pii arr[n];
	for(auto &i:arr)cin>>i.fs;
	for(auto &i:arr)cin>>i.sc;
	int flag = 1;
	for(int i = 1;i<n;i++){
		if(arr[i].fs<arr[i-1].fs)flag = false;
	}
	if(flag){
		cout<<"Yes\n";
		return;
	}
	flag = 0;
	for(auto &i:arr)flag|=1<<i.sc;
	if(flag == 3)cout<<"Yes\n";
	else cout<<"No\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
