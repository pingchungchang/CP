#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int a[n],b[n];
	int s = 0;
	for(auto &i:a)cin>>i,s += i;
	for(auto &i:b)cin>>i,s -= i;
	if(s){
		cout<<"-1\n";
		return;
	}
	vector<int> more;
	for(int i = 0;i<n;i++){
		if(a[i]>b[i])more.push_back(i);
	}
	vector<pair<int,int>> ans;
	for(int i = 0;i<n;i++){
		while(a[i]<b[i]){
			if(a[more.back()] == b[more.back()])more.pop_back();
			a[more.back()]--;
			a[i]++;
			ans.push_back(make_pair(more.back(),i));
		}
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs+1<<' '<<i.sc+1<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
