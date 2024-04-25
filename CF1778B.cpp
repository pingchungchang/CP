#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m,d;
	cin>>n>>m>>d;
	int arr[n+1],pos[n+1];
	for(int i =1;i<=n;i++){
		cin>>arr[i];
		pos[arr[i]] = i;
	}
	int brr[m];
	for(auto &i:brr)cin>>i;
	bool flag = true;
	for(int i = 1;i<m;i++){
		if(pos[brr[i]]>pos[brr[i-1]]+d||pos[brr[i]]<pos[brr[i-1]])flag = false;
	}
	if(!flag){
		cout<<"0\n";
		return;
	}
	int ans= n+1;
	for(int i = 1;i<m;i++){
		if(d<n-1)ans = min(ans,d-(pos[brr[i]]-pos[brr[i-1]])+1);
		ans = min(ans,pos[brr[i]]-pos[brr[i-1]]);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
