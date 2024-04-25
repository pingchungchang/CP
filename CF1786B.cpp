#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,h,w;
	cin>>n>>h>>w;
	int cake[n],dis[n];
	for(auto &i:cake)cin>>i;
	for(auto &i:dis)cin>>i;
	pair<int,int> range ={-2e9,2e9};
	for(int i = 0;i<n;i++){
		int l = cake[i]-h,r = cake[i]+h;
		int tl = dis[i]-w,tr = dis[i]+w;
		tl = l-tl;
		tr = r-tr;
		if(tl>tr)swap(tl,tr);
		range.first = max(range.first,tl);
		range.second = min(range.second,tr);
	}
	if(range.first<=range.second)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
